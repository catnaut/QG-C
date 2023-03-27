#include "Calculator.h"
#include "LinkStack.h"
#include <stdlib.h>
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

int getProtiy(char ch)
{
    switch (ch)
    {
    case '(':
        return 0;
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
    ElemType num1;
    int status;
    if (s->count == 0)
    {
        return SUCCESS;
    }
    else
    {
        // 此时理论不会有问题
        getTopLStack(s, &num1);
        return (getProtiy(num1) > getProtiy(ch));
    }
}

Status cal(LinkStack *s, char op)
{
    ElemType num1, num2, num;
    // num1 倒数第 1个
    // 如果第一个成功才运行第二次
    if (popLStack(s, &num2) && popLStack(s, &num1))
    {
        switch (op)
        {
        case '+':
            num = num1 + num2;
            pushLStack(s, num);
            break;
        case '-':
            num = num1 - num2;
            pushLStack(s, num);
            break;
        case '*':
            num = num1 * num2;
            pushLStack(s, num);
            break;
        case '/':
            num = num1 / num2;
            pushLStack(s, num);
            break;
        default:
            // error
            assert(1);
            break;
        }
    }
    else
    {
        // error
        assert(1);
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
        printf("%d\n", a);
        return status;
    }
}

Status calulator(char const *inputStr)
{
    char *p = inputStr;
    LinkStack numStack, opStack;
    initLStack(&numStack);
    initLStack(&opStack);
    char numBuf[numBufSize];
    char op;

    while (*p != '\0')
    {
        if (isNum(*p))
        {
            strcpy(numBuf, ""); // 清空缓冲字符串
            for (size_t i = 0; i < numBufSize && isNum(*p); i++)
            {
                numBuf[i] = *p;
                p++;
            }
            // 此时在 numBuf 内应该有一个数字的字符串
            int num = atoi(numBuf);
            // 转化为数字存放到数字栈
            pushLStack(&numStack, num);
        }
        else if (*p == ' ')
        {
            p++;
        }
        else if (*p == '(')
        {
            while (popLStack(&opStack, &op) && op != '(')
            {
                cal(&numStack, op);
            }
            // 这里需要检测 如果没有 （ 怎么办
        }
        else if (*p == '(')
        {
            // 我不清楚是是否需要保留这个
            // hasLeft =1;
            pushLStack(&opStack, *p);
        }
        else if (isOperator(*p))
        {
            if (checkProtiy(&opStack, *p))
            {
                pushLStack(&opStack, *p);
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
                pushLStack(&opStack, *p);
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