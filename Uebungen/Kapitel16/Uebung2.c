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

    printf("Eingabe einer geraden Zahl zwischen 1 und 100\n");
    printf("=============================================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\n   Gib eine gerade Zahl zwischen 1 und 100 ein: ");
        int inputok = scanf("%u", &zahl);

        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                run = false;
            printf("Eingabe ist keine gueltige positive Ganzzahl zwischen 1 und 100!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        if(zahl > 100) {
            printf("Die Zahl muss kleiner 100 sein.\n");
        }

        if(zahl%2) {
            printf("Die Zahl ist nicht gerade.\n");
            continue;
        } else {
            printf("Die Zahl %u ist eine gerade Zahl zwischen 1 und 100.\n", zahl);
        }
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}