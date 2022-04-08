#include <stdio.h>

int main()
{
    char c = -1;

    printf("%d", c >> 8);

    c = 1;
    
    printf("%d", c >> 8);
}