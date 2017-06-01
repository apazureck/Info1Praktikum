/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include "../headers/constants.h"

/*--- Funktionsdefinitionen ------------------------------------------*/

int main(void)
{
    int zahl;
    printf("Quersumme zu einer Zahl\n");
    printf("=======================\n\n");

    printf("Zahl? ");

    while (!scanf("%d", &zahl))
    {
        printf("Zahl muss eine Ganzzahl sein.\nZahl? ");
        fflush(stdin);
    }

    printf("      Dualdarstellung zu %i: ", zahl);
    for (int i = 31; i >= 0; i--)
    {
        printf("%i", (zahl >> i) & 1);
        if (!(i % 8))
            printf(" ");
    }

    printf("\nDuale BCD-Darstellung zu %i: ", zahl);

    // get max pow(10)
    int divisor = 10;
    // solange sich die zahl durch 10 teilen lässt multipliziere den divisor mit 10
    while (zahl / divisor)
        divisor *= 10;

    divisor /= 10;

    while (divisor)
    {
        int part = zahl / divisor;
        for (int i = 3; i >= 0; i--)
            printf("%i", (part >> i) & 1);

        printf(" ");
        zahl %= divisor;
        divisor /= 10;
    }

    fflush(stdin);
    getchar();
    return 0;
}