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
    const double g = 9.80655;
    unsigned int h;

    printf("In welcher Hoehe verlaesst der Fallschirmspringer den Flieger (in Meter): ");
    scanf("%u", &h);

    unsigned int t = sqrt(2 * (h - 650) / g);

    printf("---> Der Springer muss nach %u Sekunden die Reissleine ziehen", t);

    fflush(stdin);
    getchar();
    return 0;
}