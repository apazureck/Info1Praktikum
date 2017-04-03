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
    int invtime;
    double seedmoney, interest, resultingInterest;
    double const den = 100 * 360;
    printf("Anfangskapital: ");

    scanf("%lf", &seedmoney);

    printf("Jahreszins (in %%): ");

    scanf("%lf", &interest);

    printf("Wie viele Tage soll Ihr Kapital angelegt werden? ");

    scanf("%i", &invtime);

    resultingInterest = seedmoney * interest * invtime / den;

    printf("Anfangskapital:            %15.2lf\n", seedmoney);
    printf("Zinsen (nach %5d Tagen): %15.2lf\n", invtime, resultingInterest);
    printf("%.*s\n", 60, "--------------------------------------------------------------------------------------------------------");
    printf("Endkapital:                %15.2lf\n", seedmoney + resultingInterest);

    fflush(stdin);
    getchar();
    return 0;
}