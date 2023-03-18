#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>


// 为了方便快速测试 
Status InsertNode(LNode *p,ElemType *e){
    LNode* n = CreatLNode();
    n->data = 1;
    return InsertList(p,n);
}


int main(int argc, char const *argv[])
{
    LinkedList *L = malloc(sizeof(LinkedList));
    InitList(L);
    LNode* n1 = CreatLNode();
    n1->data = 1;
    InsertList(*L,n1);
    printf("status:%d\n",PrintList(L));
    DestroyList(L);
    printf("status:%d\n",PrintList(L));
    // PrintList(L);
    return 0;
}
