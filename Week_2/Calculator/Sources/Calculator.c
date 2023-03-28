#include "Calculator.h"
#include "LinkStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define numBufSize 10

Status isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

Status isNum(char ch)
{
    return ((ch >= '0' && ch <= '9'));
}

int getProtiy(ElemType o)
{
    switch (o.op)
    {
    case '(':
        return 3;
        break;
    // case ')':
    //     return 0;
    //     break;
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 1;
    default:
        assert(1);
        break;
    }
}

// 如果可以直接压栈 即 栈内的优先级大于 压入的 ch
// 返回 SUCCESS
Status checkProtiy(LinkStack *s, char ch)
{
    ElemType op1;
    ElemType op;
    op.op = ch;
    int status;
    if (s->count == 0)
    {
        return SUCCESS;
    }
    else
    {
        // 此时理论不会有问题
        getTopLStack(s, &op1);
        return (getProtiy(op1) > getProtiy(op));
    }
}

Status cal(LinkStack *s,ElemType e)
{
    ElemType num1, num2, num;
    // num1 倒数第 1个
    // 如果第一个成功才运行第二次
    if (popLStack(s, &num2) && popLStack(s, &num1))
    {
        switch (e.op)
        {
        case '+':
            num.num = num1.num + num2.num;
            pushLStack(s, num);
            break;
        case '-':
            num.num = num1.num - num2.num;
            pushLStack(s, num);
            break;
        case '*':
            num.num = num1.num * num2.num;
            pushLStack(s, num);
            break;
        case '/':
            num.num = num1.num / num2.num;
            pushLStack(s, num);
            break;
        default:
            // error
            assert(0);
            break;
        }
    }
    else
    {
        // error
        assert(0);
    }
}

Status printAnswer(LinkStack *s)
{
    ElemType a;
    int status;
    if (s->count == 1)
    {
        status = popLStack(s, &a);
        // destroyLStack(&s);
        printf("%f\n", a.num);
        return status;
    }
}

// 把浮点转为 ElemTpye
ElemType float2Elem(float n){
    ElemType tmp;
    tmp.num = n;
    return tmp;
}

// 把char转为 ElemTpye
ElemType char2Elem(char c){
    ElemType tmp;
    tmp.op = c;
    return tmp;
}


ElemType getNum(char** pptr){
    // char* p = *pptr;
    char numBuf[numBufSize];
    float r;
    memset(numBuf,'\0',numBufSize); // 清空缓冲字符串
    for (size_t i = 0; i < numBufSize && isNum(**pptr); i++)
    {
        numBuf[i] = **pptr;
        (*pptr)++;
    }
    // 此时在 numBuf 内应该有一个数字的字符串
    r = atof(numBuf);
    // 转化为 ElemType 返回
    return float2Elem(r);
}


Status calulator(char const *inputStr)
{
    char *p = inputStr;
    LinkStack numStack, opStack;
    initLStack(&numStack);
    initLStack(&opStack);
    char numBuf[numBufSize];
    ElemType op;

    while (*p != '\0')
    {
        if (isNum(*p))
        {
            pushLStack(&numStack,getNum(&p)); // 将数字压入栈
        }
        else if (*p == ' ')
        {
            p++;
        }
        else if (*p == ')')
        {
            while ((popLStack(&opStack,&op)) && op.op != '(')
            {
                cal(&numStack, op);
            }
            p++;
            // 这里需要检测 如果没有 （ 怎么办
        }
        else if (*p == '(')
        {
            // 我不清楚是是否需要保留这个
            // hasLeft =1;
            pushLStack(&opStack, char2Elem(*p));
            p++;
        }
        else if (isOperator(*p))
        {
            if (checkProtiy(&opStack, *p))
            {
                pushLStack(&opStack, char2Elem(*p));
                p++;
            }
            else
            {
                // 可以出栈 继续循环
                while (!checkProtiy(&opStack, *p) && popLStack(&opStack, &op))
                {
                    cal(&numStack, op);
                }
                // 此时优先级大于进行压栈
                pushLStack(&opStack, char2Elem(*p));
                p++;
            }
        }
        else
        {
            return ERROR;
        }
    }
    // 字符串遍历结束开始出栈
    while (popLStack(&opStack, &op))
    {
        cal(&numStack, op);
    }
    printAnswer(&numStack);
}