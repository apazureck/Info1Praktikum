/**********************************************************************\
* Kurzbeschreibung: Uebung: 8.1.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 10.04.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    unsigned int k1, k2, k3, k4, total;

    printf("Stimmen fuer den 1. Kandidat: ");
    scanf("%u", &k1);

    printf("Stimmen fuer den 2. Kandidat: ");
    scanf("%u", &k2);

    printf("Stimmen fuer den 3. Kandidat: ");
    scanf("%u", &k3);

    printf("Stimmen fuer den 4. Kandidat: ");
    scanf("%u", &k4);

    total = k1 + k2 + k3 + k4;

    printf("1. Kandidat: %.2lf%%\n", (double)k1 / total * 100);
    printf("1. Kandidat: %.2lf%%\n", (double)k2 / total * 100);
    printf("1. Kandidat: %.2lf%%\n", (double)k3 / total * 100);
    printf("1. Kandidat: %.2lf%%\n", (double)k4 / total * 100);

    fflush(stdin);
    getchar();
    return 0;
}