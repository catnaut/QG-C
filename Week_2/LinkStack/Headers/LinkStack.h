#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "LinkedList.h"

// typedef enum Status 
// {
//     ERROR = 0, 
// 	SUCCESS = 1
// } Status;

// typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkedList top;
	int	count;
}LinkStack;



//链栈

//初始化栈
Status initLStack(LinkStack *s);

// 判断栈是否为未初始化或者为空
// 未初始化或者为空返回 SUCCESS
Status isEmptyLStack(LinkStack *s);

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e);

//清空栈
//链表的头节点还在
Status clearLStack(LinkStack *s);

//销毁栈
//链表的头节点销毁了，此时无法插入，需要重新 Init 
Status destroyLStack(LinkStack *s);

//检测栈长度
Status LStackLength(LinkStack *s,int *length);

//入栈
Status pushLStack(LinkStack *s,ElemType data);

//出栈
Status popLStack(LinkStack *s,ElemType *data);

#endif 
