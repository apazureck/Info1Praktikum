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

    printf("Summe von ungeraden Zahlen\n");
    printf("========================================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\nBis zu welchem n sollen alle ungeraden Zahlen aufaddiert werden? ");
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
        unsigned int summe = 0;
        for(unsigned int i = 1; i <= input; i+=2)
            summe += i;
        
        printf("  Summe der ungeraden Zahlen bis %u: %u\n", input, summe);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}