#include <iostream>
#include "util.h"

void GetAllChars()
{
	int i = 0;
    
    do
    {
        printf("%d %c \n\n",i,i);
        i++;
    }
    while(i <= 255);
}