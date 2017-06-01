/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <float.h>
#include "../headers/constants.h"

/*--- Funktionsdefinitionen ------------------------------------------*/

void cleaninput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    double max;
    int ok = false;
    printf("Fibonacci-Zahlen\n");
    printf("================\n\n");
    printf("Bis wohin? ");

    while (!ok)
    {
        ok = scanf("%lf", &max);
        ok = ok && max >= 0.9; // 0.9 to get epsilon double (rough)
        if(ok)
            break;
        printf("Die Zahl muss eine positive Zahl sein.\nBis wohin? ");
        cleaninput();
    }
    unsigned int i = 3u;
    double last1 = 1.0, last2 = 1.0;
    if (max > 0.1)
        printf("%4u. %10.0lf\n", 1u, last2);
    if (max > 1.1)
        printf("%4u. %10.0lf\n", 2u, last1);

    double current = last2 + last1;
    last2 = last1;
    last1 = current;

    while (current <= max)
    {
        printf("%4u. %10.0lf\n", i, current);
        if (!(i % 20))
        {
            fflush(stdin);
            printf("Beliebige Taste zum fortfahren druecken...\n");
            getchar();
        }

        current = last2 + last1;
        last2 = last1;
        last1 = current;

        i++;
    }

    fflush(stdin);
    getchar();
    return 0;
}