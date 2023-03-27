#include <stdlib.h>
#include "linkedList.h"
#include <stdio.h>
// LNode define in linkedList.h

LNode *CreatLNode()
{
    LinkedList r = malloc(sizeof(LNode));
    if (r != NULL)
    {
        r->next = NULL;
        return r;
    }
    else
    {
        // 在这里是否需要直接提示并退出程序
        return NULL;
    }
}

Status InitList(LinkedList *L)
{
    *L = CreatLNode();
    if (*L == NULL)
        return ERROR;
    else
    {
        return SUCCESS;
    }
}


Status PrintList(LinkedList *L){
    LNode* p = (*L)->next;
    if(p==NULL) return ERROR;
    printf("Print LinkedList:\n");
    while (p!=NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    return SUCCESS;
}


void DestroyList(LinkedList *L){
    
    // p1存储本节点的地址，p2存储下一个节点的地址
    LNode *p1 = (*L)->next;
    LNode *p2;
    while (p1 != NULL)
    {
        p2 = p1->next;
        free(p1);
        p1 = p2;
    }
    (*L)->next = NULL;
}

Status InsertList(LNode *p, LNode *q)
{

    // 传入时保证要指针不是空指针
    if (p == NULL || q == NULL)
        return ERROR;

    q->next = p->next;
    p->next = q;
    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e)
{
    if (p == NULL)
        return ERROR;
    LNode *pre = p;
    LNode *q = p->next;
    while (q != NULL)
    {

        if (q->data == *e)
        {

            pre->next = q->next;
            free(q);
            // p->next = q;
            return SUCCESS;
        }
        pre = pre->next;
        q = q->next;
    }
    return ERROR;
}


Status ReverseEvenList(LinkedList *L){
    // 必须有前两个节点和一个头节点
    LNode *pre = *L;
    if (pre == NULL && pre->next == NULL && pre->next->next == NULL)
        return ERROR;
    LNode *p1 = pre->next;
    LNode *p2 = p1->next;
    for (;;)
    {
        pre->next = p2;
        p1->next = p2->next;
        p2->next = p1;
        if (pre != NULL && pre->next != NULL && pre->next->next != NULL)
            return SUCCESS;
        else
        {
            pre = p1->next;
            p1 = pre->next;
            p2 = p1->next;
        }
    }
}

LNode *FindMidNode(LinkedList *L)
{
    if (L == NULL)
        return NULL;
    LNode *head = *L;
    if (head->next == NULL)
        return NULL;
    LNode *p = head->next;
    LNode *q = head->next;
    for (;;)
    {
        if (q->next == NULL || q->next->next == NULL)
        {
            return p;
        }
        else
        {
            q = q->next->next;
            p = p->next;
        }
    }
}

Status IsLoopList(LinkedList L)
{
    if (L == NULL)
        return ERROR;
    LNode *head = L;
    if (head->next == NULL && head->next->next == NULL)
        return ERROR;
    LNode *p = head->next;
    LNode *q = head->next->next;
    for (;;)
    {
        if (q->next == NULL || q->next->next == NULL)
        {
            return ERROR;
        }
        else if (q == p)
        {
            return SUCCESS;
        }
        else
        {
            q = q->next->next;
            p = p->next;
        }
    }
}

Status ReverseList(LinkedList *L)
{
    // 防止 L 为空
    if (L == NULL)
        return ERROR;

    LNode *head = *L;
    // 只有一个头节点 直接可以认为是反转完成
    if (head->next == NULL)
        return SUCCESS;

    LNode *pre = head;
    LNode *p = head->next;
    LNode *pnext;

    pnext = p->next;
    // 头节点后的第一个是尾节点，指向空
    p->next = NULL;
    // p->next = pre;

    for (;;)
    {
        if (pnext == NULL) // 如果到头
        {
            // nextp->next = p;
            head->next = p;
            return SUCCESS;
        }
        else
        {
            pre = p;
            p = pnext;
            pnext = p->next;
            p->next = pre;
        }
    }
}

Status SearchList(LinkedList L, ElemType e)
{
    if (L == NULL || L->next == NULL)
        return ERROR;
    LNode *p = L->next;
    while (p != NULL)
    {
        if (p->data == e)
        {
            return SUCCESS;
        }
        p = p->next;
    }
    return ERROR;
}
