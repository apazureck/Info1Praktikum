/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.6.2; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 29.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

#define PI      3.14159265359

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    const double g = 9.80655;
    double h;

    printf("Hoehe des Koerpers (in Meter): ");
    scanf("%lf", &h);

    double t = sqrt(2 * h / g);

    printf("--->Fallzeit: %lf Sek", t);

    fflush(stdin);
    getchar();
    return 0;
}