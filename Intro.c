/**********************************************************************\
* Kurzbeschreibung: Uebung: 1.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 20.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    printf("Hello, what is your name?\n");

    char name[100];
    int age;
    scanf("%s", &name);

    printf("Hello %s\n", name);
    printf("How Old are you?\n");
    scanf("%i", &age);

    if (age > 30)
        printf("Grumpy old geezer!");
    else
        printf("Hey young fellow!");

    fflush(stdin);
    getchar();
    return 0;
}
