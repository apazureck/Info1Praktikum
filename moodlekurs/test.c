#include <stdio.h>

int main()
{
int i;

for (i = 0; i < 8; i++)
{
    printf("%d", i);
    
    if (i >= 3 && i <= 5)
        continue;

    printf(",");
}
}