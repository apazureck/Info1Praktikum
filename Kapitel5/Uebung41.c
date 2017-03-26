/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.4.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 26.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int wert;
    int a, x, y, z, jahr;

    a = -15;

    if (a >= -20)
        wert = 1;
    else if (a <= 100)
        wert = 1;
    else
        wert = 0;

    printf("1. Wert: %d\n", wert);

    x = 1;
    y = 7;

    if (x < 0)
    {
        if (x >= 5 && x <= 30)
            wert = 1;
        else
            wert = 0;
    }
    else
        wert = 0;
    fflush(stdin);
    getchar();
    return 0;
}