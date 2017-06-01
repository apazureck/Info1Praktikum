/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "../headers/constants.h"
#include <time.h>

/*--- Funktionsdefinitionen ------------------------------------------*/

int main(void)
{
    int run = true;

    // Initialize random generator
    srand(time(NULL));

    printf("17.2 Quadratwurzel mit NEWTON-Iteration\n");
    printf("=======================================\n\n");

    while (run)
    {
        int zahl;
        double abweichung;
        char tmp;
        printf("Druecke q zum Beenden.\n");
        printf("Zu welcher Zahl soll Quadratwurzel berechnet werden? ");

        int res = scanf("%d%c", &zahl, &tmp);
        if (!res)
        {
            tmp = getchar();
            if (tmp == 'q' || tmp == 'Q')
            {
                run = false;
                break;
            }
        }
        fflush(stdin);

        while (res != 2 || tmp != '\n' || zahl < 1)
        {
            printf("Der Wert ist nicht gueltig. Bitte gib eine positive Ganzzahl ein: ");
            res = scanf("%d%c", &zahl, &tmp);

            if (!res)
            {
                tmp = getchar();
                if (tmp == 'q' || tmp == 'Q')
                {
                    run = false;
                    break;
                }
            }

            fflush(stdin);
        }

        if (run == false)
            break;

        printf("Wie groß darf die Abweichung vom wirklichen Wert maximal sein? ");
        res = scanf("%lf%c", &abweichung, &tmp);
        if (!res)
        {
            tmp = getchar();
            if (tmp == 'q' || tmp == 'Q')
            {
                run = false;
                break;
            }
        }

        while (res != 2 || tmp != '\n' || abweichung <= DBL_EPSILON)
        {
            printf("Der Wert ist nicht gueltig. Bitte gib eine positive Zahl ein: ");
            res = scanf("%lf%c", &abweichung, &tmp);

            if (!res)
            {
                tmp = getchar();
                if (tmp == 'q' || tmp == 'Q')
                {
                    run = false;
                    break;
                }
            }

            fflush(stdin);
        }

        if (run == false)
            break;

        int showIterations;
        res = 0;

        while (res != 2 || abweichung <= DBL_EPSILON)
        {
            printf("Sollen die einzelnen Iterationsschritte angezeigt werden (j/n)? ");
            res = scanf("%c", &tmp);
            fflush(stdin);
            if (res == 1)
            {
                int inputOk = false;
                switch (tmp)
                {
                case 'q':
                case 'Q':
                    run = false;
                    inputOk = true;
                    break;
                case 'j':
                case 'J':
                    showIterations = true;
                    inputOk = true;
                    break;
                case 'n':
                case 'N':
                    showIterations = false;
                    inputOk = true;
                    break;
                default:
                    printf("Eingabe ungueltig.\n");
                    break;
                }
                if (inputOk)
                    break;
            }
        }

        double realValue = sqrt(zahl),
               x = zahl;
        int loopcounter = 1;

        do
        {
            x = (x + zahl / x) / 2;
            if (showIterations)
                printf("                    %.10lf (%d. Iteration)\n", x, loopcounter++);
        } while (fabs(realValue - x) >= abweichung);

        printf("\n");
        printf("    NEWTON-Wert:    %.10lf\n", x);
        printf("Wirklicher Wert:    %.10lf\n", realValue);
        printf("--------------------------------\n");
        printf("     Abweichung:    %.10lf\n\n", abweichung);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}