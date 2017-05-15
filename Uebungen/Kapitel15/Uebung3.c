/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include "../headers/constants.h"

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int run = true;
    unsigned int input;

    printf("Berechnung der Leibniz-Reihe\n");
    printf("========================================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\nWieviele Brueche sollen addiert, bzw. subtrahiert werden? ");
        int inputok = scanf("%u", &input);

        // Check input
        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                break;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        double toggle = 1, summe = 0;
        for(unsigned int i = 1, j=1; i <= input; i++, j+=2, toggle *= -1)
            summe += 1.0/j*toggle;
        
        printf("  Summe bis zum %u. Glied: %f ===> PI=%f\n", input, summe, 4*summe);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}