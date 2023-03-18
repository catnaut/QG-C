#include "linkedListAddition.h"
#include <stdio.h>
#include <stdlib.h>

Status InsertNode(LNode *p, ElemType e)
{
    LNode *n = CreatLNode();
    n->data = e;
    return InsertList(p, n);
}

LNode *FindEnd(LNode *p)
{
    if (p == NULL)
        return p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Status PrintList(LinkedList *L)
{
    LNode *p = (*L)->next;
    if (p == NULL)
    {
        printf("List is NULL\n");
        return ERROR;
    }
    if (IsLoopList(*L))
    {
        printf("Can't print loop list.\n");
        return ERROR;
    }
    printf("Print LinkedList:\n");
    printf("H");
    while (p != NULL)
    {
        printf("->%d", p->data);
        p = p->next;
    }
    printf("\n");
    return SUCCESS;
}

// when p->next = NULL && p != q
// connect p to q
Status CreatLoop(LNode *p, LNode *q)
{
    if (p->next == NULL && p != q)
    {
        p->next = q;
        return SUCCESS;
    }
    else
        return ERROR;
}