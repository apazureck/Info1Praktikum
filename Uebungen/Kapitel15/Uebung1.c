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

    printf("Harmonische Reihe\n");
    printf("========================================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\nBis zu welchem n soll die harmonische Reihe berechnet werden? ");
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
        double summe = 0;
        for(int i = 1; i<= input; i++)
            summe += 1.0 / i;
        
        printf("  Summe bis 1/%u: %f\n", input, summe);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}