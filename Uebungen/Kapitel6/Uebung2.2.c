/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.6.2; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 29.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    const double kmhtomps = 1000.0/3600;
    double hours, minutes, way, consumption, totaltime;

    printf("Gefahrene Stunden: ");
    scanf("%lf", &hours);

    printf("Gefahrene Minuten: ");
    scanf("%lf", &minutes);

    totaltime = hours + minutes / 60;

    printf("Gefahrene Kilometer: ");
    scanf("%lf", &way);

    printf("Gebrauchte Liter: ");
    scanf("%lf", &consumption);

    printf("   Durchschnittl. Geschwindigkeit: %.2lf km/h (%.2lf m/s)\n", way/totaltime, way/totaltime*kmhtomps);
    printf("   Durchschnittl. Benzinverbrauch: %.2lf l/100 km", consumption / way * 100);

    fflush(stdin);
    getchar();
    return 0;
}