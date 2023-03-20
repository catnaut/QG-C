#include <stdlib.h>
#include "linkedList.h"
#include <stdio.h>
// LNode define in linkedList.h

LNode *CreatLNode()
{
    LNode* r = malloc(sizeof(LNode));
    if (r != NULL)
    {
        r->next = NULL;
        r->pre = NULL;
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
    LinkedList List;
    List = (LinkedList)CreatLNode();
    if (List == NULL)
        return ERROR;
    else
    {
        *L = List;
        return SUCCESS;
    }
}

void DestroyList(LinkedList *L)
{

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
    (*L)->pre = NULL;
}

Status InsertList(LNode *p, LNode *q)
{

    // 传入时保证要指针不是空指针
    if (p == NULL || q == NULL)
        return ERROR;
    if (p->next==NULL)
    {
        q->next = p->next;
        q->pre = p;
        p->next = q;
        return SUCCESS;
    }
    else{
        p->next->pre = q;
        q->next = p->next;
        q->pre = p;
        p->next = q;
        return SUCCESS;
    }
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

Status ReverseEvenList(LinkedList *L)
{
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
    if (head->next == NULL || head->next->next == NULL)
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

// 交换p节点的 pre 和 next
static void ChangeLNodePointer(LNode *p){
    LNode* tmp;
    tmp = p->next;
    p->next = p->pre;
    p->pre = tmp;
}

Status ReverseList(LinkedList *L)
{
    // 防止 L 为空
    // 防止 L 为循环链表
    if (L == NULL)
        return ERROR;

    LNode *head = *L;
    // 只有一个头节点 直接可以认为是反转完成
    if (head->next == NULL)
        return SUCCESS;
    
    // 交换首尾指针
    ChangeLNodePointer(head);

    LNode *p = head->next;
    while (p != NULL)
    {
        // 交换前后指针
        ChangeLNodePointer(p);
        p = p->next;
    }
    return SUCCESS;
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
