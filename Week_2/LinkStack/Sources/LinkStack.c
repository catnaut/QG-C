#include "LinkStack.h" 
#include "LinkedList.h"
#include "stdlib.h"
//链栈

//初始化栈
Status initLStack(LinkStack *s){
    LinkedList List;
    InitList(&List);
    if (List == NULL){
        return ERROR;
    }
    s->top = List;
    s->count =0;
    return SUCCESS;
}


// 判断栈是否为未初始化或者为空
// 未初始化或者为空返回 SUCCESS 
Status isEmptyLStack(LinkStack *s){
    if(s==NULL)
    {
        return SUCCESS;
    }
    else{
        if (s->top==NULL)
        {
            return SUCCESS;
        }
        else{
            return ERROR;
        }   
    }
}


//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(!isEmptyLStack(s)&&s->count>0){
        *e = s->top->next->data;
        return SUCCESS;        
    }
    else{
        // 栈为空或者不合法
        e = NULL;
        return ERROR;
    }
}


//清空栈
//链表的头节点还在
Status clearLStack(LinkStack *s){
	if(isEmptyLStack(s)){
        // 栈为空或者不合法
        return ERROR;
    }
    else{
        DestroyList(&(s->top));
        s->count = 0;
        return SUCCESS;
    }
}


//销毁栈
//链表的头节点销毁了，此时无法插入，需要重新 Init 
Status destroyLStack(LinkStack *s){
    if(isEmptyLStack(s)){
        // 栈不合法
        return ERROR;
    }
    else{
        clearLStack(s);
        // 我申请 stack 的时候是使用 auto 关键字 无法通过 free() 释放
        // 这里只做清除
        // free(s);
        free(s->top);
        s->top = NULL;
        return SUCCESS;
    }
}


//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(isEmptyLStack(s) && s->count<0){
        // 不合法
        return ERROR;
    }
    else{
        // 这什么操作 要我重新检测一边？
        return SUCCESS;
    }
}


//入栈
Status pushLStack(LinkStack *s,ElemType data){
	if(isEmptyLStack(s)){
        // 栈不合法
        return ERROR;
    }
    else{
        LNode* node = CreatLNode();
        node->data = data;
        s->count ++;
        return InsertList(s->top,node);
    }
}


//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s)||s->count<1){
        // 栈为空或者不合法
        return ERROR;
    }
    else{
        DeleteList(s->top,data);
        s->count --;
        return SUCCESS;
    }
}