#include <stdio.h>
#include "LinkStack.h"

int main(int argc, char const *argv[])
{
    LinkStack stack;
    initLStack(&stack);
    printf("status:%d\n",isEmptyLStack(&stack));
    int a;
    printf("status:%d\n",getTopLStack(&stack,&a));
    printf("a:%d\n",a);
    printf("status:%d\n",pushLStack(&stack,1));
    printf("status:%d\n",getTopLStack(&stack,&a));
    printf("a:%d\n",a);
    printf("status:%d\n",pushLStack(&stack,2));
    printf("status:%d\n",getTopLStack(&stack,&a));
    printf("status:%d\n",popLStack(&stack,&a));
    printf("a:%d\n",a);
    printf("status:%d\n",getTopLStack(&stack,&a));
    printf("a:%d\n",a);
    printf("status:%d\n",clearLStack(&stack));
    printf("status:%d\n",getTopLStack(&stack,&a));
    printf("a:%d\n",a);
    printf("status:%d\n",pushLStack(&stack,3));
    printf("status:%d\n",destroyLStack(&stack));
    printf("status:%d\n",getTopLStack(&stack,&a));
    return 0;
}
