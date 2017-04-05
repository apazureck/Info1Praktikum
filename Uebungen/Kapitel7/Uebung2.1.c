/**********************************************************************\
* Kurzbeschreibung: Uebung: 7.2.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 05.04.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    char input[6];

    printf("Gib eine 5-Stellige Zahl ein: ");
    scanf("%5s", input);

    printf("Die Quersumme dieser Zahl ist %d", input[0] + input[1] + input[2] + input[3] + input[4] - 5 * 48);

    fflush(stdin);
    getchar();
    return 0;
}