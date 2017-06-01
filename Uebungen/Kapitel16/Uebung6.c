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
    unsigned int zahl, outzahl, quersumme = 0;
    printf("Quersumme zu einer Zahl\n");
    printf("=======================\n\n");

    printf("Zahl? ");

    while(!scanf("%u", &zahl)) {
        printf("Zahl muss eine positive Ganzzahl sein.\nZahl? ");
        fflush(stdin);
    }
    
    outzahl = zahl;
    quersumme += zahl % 10;

    while(zahl = zahl/10)
        quersumme += zahl % 10;

    printf("Quersumme zu %u ist: %u", outzahl, quersumme);
    fflush(stdin);
    getchar();
    return 0;
}