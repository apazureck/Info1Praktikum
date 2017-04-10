/**********************************************************************\
* Kurzbeschreibung: Uebung: 11.3; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 10.04.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int numerator, denominator;

    printf("Zahl x durch Zahl y teilbar ?\n");
    printf("=============================\n");
    printf("Dieses Programm sagt Ihnen, ob eine Zahl x durch eine Zahl y\n");
    printf("teilbar ist. Dazu muessen nur die beiden ganzen Zahlen x und y eingeben.\n");

    printf("x? ");
    scanf("%d", &numerator);

    printf("y? ");
    scanf("%d", &denominator);

    printf("%d ist durch %d ..... ", numerator, denominator);

    if(numerator % denominator == 0)
        printf("teilbar");
    else
        printf("nicht teilbar");

    fflush(stdin);
    getchar();
    return 0;
}