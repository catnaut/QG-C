#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include "problem.h"


// 为了方便快速测试 
Status InsertNode(LNode *p,ElemType *e){
    LNode* n = CreatLNode();
    n->data = 1;
    return InsertList(p,n);
}


Status InsertPoolNode();


int main(int argc, char const *argv[])
{
    LinkedList *L = malloc(sizeof(LinkedList));
    InitList(L);
    // LNode* n1 = CreatLNode();
    // n1->data = 1;
    // InsertList(*L,n1);


    InsertNode(*L,4);
    InsertNode(*L,3);
    InsertNode(*L,2);
    InsertNode(*L,1);
    printf("status:%d\n",PrintList(L));
    printf("test changeOddEven:\n");
    changeOddEven(*L);
    printf("status:%d\n",PrintList(L));
    LNode* n = FindMidNode(L);
    if (n!=NULL) printf("mid:%d\n",n->data);
    else printf("mid:error\n");
    printf("status:%d\n",PrintList(L));

    // ElemType aIntNumber = 1;
    // ElemType *e = &aIntNumber; 
    // DeleteList(*L,e);
    // printf("status:%d\n",PrintList(L));
    printf("reverse\n");
    ReverseList(L);
    printf("status:%d\n",PrintList(L));

    
    // DestroyList(L);
    // printf("status:%d\n",PrintList(L));
    // PrintList(L);
    return 0;

}
