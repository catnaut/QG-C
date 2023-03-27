#include <stdio.h>
#include "Calculator.h"

int main(int argc, char const *argv[])
{

    if (argc==2)
    {
        calulator(argv[1]);
    }
    else{
        printf("require 1 argument");
    }
    return 0;
}
