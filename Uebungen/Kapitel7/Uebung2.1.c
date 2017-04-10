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
    int input0, input1, input2, input3, input4;

    printf("Gib eine 5-Stellige Zahl ein: ");
    scanf("%1d%1d%1d%1d%1d", &input0, &input1, &input2, &input3, &input4);

    printf("Die Quersumme dieser Zahl ist %d", input0 + input1 + input2 + input3 + input4);

    fflush(stdin);
    getchar();
    return 0;
}