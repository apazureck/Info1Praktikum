/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.6.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 29.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    char zeichen = 'F';

    printf("%d", (zeichen >> 7) & 1);
    printf("%d", (zeichen >> 6) & 1);
    printf("%d", (zeichen >> 5) & 1);
    printf("%d", (zeichen >> 4) & 1);
    printf("%d", (zeichen >> 3) & 1);
    printf("%d", (zeichen >> 2) & 1);
    printf("%d", (zeichen >> 1) & 1);
    printf("%d", zeichen & 1);

    fflush(stdin);
    getchar();
    return 0;
}