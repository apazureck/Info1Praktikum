/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.6.2; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 29.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

#define LIGHTYEARS      9.4605 * 1000000000000

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    double lightyears;
    printf("Wieviele Lichtjahre : ");
    scanf("%lf", &lightyears);

    printf("   ----> %lf", LIGHTYEARS * lightyears);

    fflush(stdin);
    getchar();
    return 0;
}