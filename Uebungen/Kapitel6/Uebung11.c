/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.6.2; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 29.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

#define PI      3.14159265359
#define FOURPI  4 * PI

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    double radius;
    printf("Radius der Kugel : ");
    scanf("%lf", &radius);

    double umfang = 2.0 * radius * PI;

    printf("Umfang=%lf\n", umfang);

    double volumen = FOURPI * radius * radius * radius / 3.0;

    printf("Volumen=%lf\n", volumen);

    double oberflaeche = FOURPI * radius * radius;

    printf("Oberflaeche=%lf\n", oberflaeche);

    fflush(stdin);
    getchar();
    return 0;
}