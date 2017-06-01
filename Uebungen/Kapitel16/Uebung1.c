/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/constants.h"

/*--- Funktionsdefinitionen ------------------------------------------*/

int main(void)
{
    int run = true;
    unsigned int zahl;

    printf("Fritz und Hans essen Aepfel\n");
    printf("===========================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\n   Wieviele Aepfel haben Fritz und Hans gekauft? ");
        int inputok = scanf("%u", &zahl);

        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                run = false;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        if(zahl%8) {
            printf("Die Zahl ist nicht durch 8 teilbar.\n");
            continue;
        }

        // Calculation:
        unsigned int fritz = 0, hans = 0, runde = 1;
        printf("Runde | Fritz |  Hans |  Rest |\n");
        printf("------+-------+-------+-------|\n");
        while(zahl > 0) {
            printf("%5u | %5u | %5u | %5u |\n", runde++, fritz += 5, hans += 3, zahl -= 8);
        }
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}