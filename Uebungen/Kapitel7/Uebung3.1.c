/**********************************************************************\
* Kurzbeschreibung: Uebung: 7.2.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 10.04.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int width;
    char dashes[] = "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    printf("Wie breit soll der Rahmen werden: ");
    scanf("%i", &width);

    printf("+%.*s+\n", width, dashes);
    printf("|%*s|\n", width, "");
    printf("|%*s|\n", width, "");
    printf("|%*s|\n", width, "");
    printf("+%.*s+\n", width, dashes);

    fflush(stdin);
    getchar();
    return 0;
}