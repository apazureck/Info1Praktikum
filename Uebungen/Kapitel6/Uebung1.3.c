/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.6.2; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 29.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

#define PI      3.14159265359

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    double radius, umfang;
    printf("Welchen Radius hat der Körper, um den das Seil gelegit wird (in m)? : ");
    scanf("%lf", &radius);

    umfang = 2.0 * PI * radius;
    umfang = umfang + 1;

    // calculate delta radius and save it in radius
    radius = umfang / 2 / PI - radius;

    printf("\nNach einer Verlängerung um 1 Meter\n   steht es um %.2lf cm ab.", radius * 100);

    fflush(stdin);
    getchar();
    return 0;
}