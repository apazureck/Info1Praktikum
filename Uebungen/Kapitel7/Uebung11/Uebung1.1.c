/**********************************************************************\
* Kurzbeschreibung: Uebung: 7.1.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 05.04.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include "vumrech.h"

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    double distance, timeins, mps;

    printf("Gib die Strecke ein (in Meter): ");
    scanf("%lf", &distance);

    printf("Gib die Zeit ein, die dafür benötigt wird (in Sekunden): ");
    scanf("%lf", &timeins);

    mps = distance / timeins;

    printf("Das entspricht folgender Geschwindigkeit:\n");
    printf("  %lf m/sec =\n", mps);
    printf("    %lf km/h =\n", mps * MS_NACH_KMH);
    printf("      %lf m/d =\n", mps * MS_NACH_MTAG);
    printf("        %lf km/d", mps * MS_NACH_KMTAG);

    fflush(stdin);
    getchar();
    return 0;
}