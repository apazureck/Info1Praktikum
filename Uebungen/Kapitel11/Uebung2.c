/**********************************************************************\
* Kurzbeschreibung: Uebung: 11.2; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 10.04.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    unsigned int hour;

    printf("Gib die Stunde der momentanten Uhrzeit ein: ");
    scanf("%u", &hour);
    printf("---> ");

    if (hour == 23 || hour <= 5)
        printf("Gute Nacht");
    else if (hour >= 6 && hour <= 10)
        printf("Guten Morgen");
    else if (hour >= 11 && hour <= 13)
        printf("Mahlzeit");
    else if (hour >= 14 && hour <= 17)
        printf("Schoenen Nachmittag");
    else if (hour >= 18 && hour <= 22)
        printf("Guten Abend");
    else
        printf("keine erlaubte Stunden-Angabe");


    fflush(stdin);
    getchar();
    return 0;
}