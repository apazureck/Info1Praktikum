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
    unsigned int persons;

    printf("Haendeschuetteln aller Personen auf einer Party\n");
    printf("===============================================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\nWieviele Personen sind auf der Party? ");
        int inputok = scanf("%u", &persons);

        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                run = false;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        unsigned int summe = 0;
        for(unsigned int i = persons-1; i > 0; i--)
            summe += i;
        
        printf("  Es werden %u mal die Haende geschuettelt.\n", summe);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}