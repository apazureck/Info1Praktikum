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
    unsigned int octal;

    printf("Gib eine Oktalzahl ein: ");
    scanf("%o", &octal);

    printf("---> %o(8) = %u(10) = %x(16)", octal, octal, octal);

    fflush(stdin);
    getchar();
    return 0;
}