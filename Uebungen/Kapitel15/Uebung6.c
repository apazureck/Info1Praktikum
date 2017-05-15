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

    printf("Alle Teiler einer Zahl\n");
    printf("======================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\nGib eine Zahl ein: ");
        int inputok = scanf("%u", &zahl);

        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                run = false;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        unsigned int haelfte = zahl/2, nointro = true, hits = 0;
        for(unsigned int i = 2; i <= haelfte; i++)
            if(!(zahl%i)) {
                hits++;
                if(nointro) {
                    nointro = false;
                    printf("%u ist teilbar durch: %u", zahl, i);
                } else 
                printf(", %u", i);
            }
        
        if(!hits)
            printf("%u ist eine Primzahl.\n", zahl);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}