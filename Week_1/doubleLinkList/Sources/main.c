#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include "linkedListAddition.h"



// Status InsertPoolNode();


enum COMMAND {
    exitProgram,
    print=1,
    headInsert,
    endInsert,
    destroyList,
    searchList,
    reverseList,
    isLoopList,
    findMidNode,
    creatLoop
};


void menu(){
    printf("0.exit\n");
    printf("1.print\n");
    printf("2.headInsert\n");
    printf("3.endInsert\n");
    printf("4.destroyList\n");
    printf("5.searchList\n");
    printf("6.reverseList\n");
    printf("7.isLoopList\n");
    printf("8.findMidNode\n");
    printf("9.connect to head to creat a loop\n");
}



int main(int argc, char const *argv[])
{
    // LinkedList *List = malloc(sizeof(LinkedList));
    LinkedList List;
    // LinkedList *pList = List
    InitList(&List);
    // LNode* n1 = CreatLNode();
    // n1->data = 1;
    // InsertList(*L,n1);


    // InsertNode(*List,4);
    // InsertNode(*List,3);
    // InsertNode(*List,2);
    // InsertNode(*List,1);
    // InsertNode(FindEnd(*List),10);
    // printf("status:%d\n",PrintList(List));
    // printf("test changeOddEven:\n");
    // ReverseEvenList(List);
    // printf("status:%d\n",PrintList(List));
    // LNode* n = FindMidNode(List);
    // if (n!=NULL) printf("mid:%d\n",n->data);
    // else printf("mid:error\n");
    // printf("status:%d\n",PrintList(List));

    // // ElemType aIntNumber = 1;
    // // ElemType *e = &aIntNumber; 
    // // DeleteList(*L,e);
    // // printf("status:%d\n",PrintList(L));
    // printf("reverse\n");
    // ReverseList(List);
    // printf("status:%d\n",PrintList(List));



    menu();
    for(;;){
        int command;
        int num;
        printf("command:");
        scanf("%d",&command);

        switch (command)
        {
        case print:
            PrintList(List);
            break;
        case headInsert:
            printf("insert number:");
            scanf("%d",&num);
            printf("headInsert(0=error,1=success):%d\n",InsertNode(List,num));
            // InsertNode(List,num);
            List->next->pre = NULL;
            List->pre = FindEnd(List);
            break;
        case endInsert:
            printf("int put the insert number:");
            // int num;
            scanf("%d",&num);
            // InsertNode(FindEnd(List),num);
            printf("endInsert(0=error,1=success):%d\n",InsertNode(FindEnd(List),num));
            List->pre = FindEnd(List);
            break;
        case destroyList:
            DestroyList(&List);
            break;
        case searchList:
            printf("int put a number:");
            // int num;
            scanf("%d",&num);
            SearchList(List,num);
            break;
        case reverseList:
            printf("reverseList(0=error,1=success):%d\n",ReverseList(&List));
            break;
        case isLoopList:
            printf("isLoopList(0=error,1=success):%d\n",IsLoopList(List));
            break;
        case exitProgram:
            printf("exit\n");
            return 0;
            break;
        case findMidNode:
            printf("mid node data:%d\n",FindMidNode(&List));
            break;   
        case creatLoop:
            if(List->next!=NULL){
                printf("creatLoop(0=error,1=success):%d\n",CreatLoop(FindEnd(List),List->next));
                // CreatLoop(FindEnd(*List),(*List)->next);
            }
            break;  
        default:
            printf("unkonw\n");
            break;
        }
    }
    
    // DestroyList(L);
    // printf("status:%d\n",PrintList(L));
    // PrintList(L);
    return 0;

}
