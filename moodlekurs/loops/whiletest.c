#include <stdio.h>

int main()
{
    char c;
    int input = -1;
    
    while(input < 5 || input > 10) {
        
        printf("Geben Sie eine Zahl zwischen 5 und 10 ein: ");
        scanf("%d", &input);
        
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    
    printf("Die Zahl ist %d", input);
    return 0;
}
