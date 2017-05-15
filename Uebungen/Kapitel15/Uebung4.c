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

double factorial(double n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main(void)
{
    int run = true;
    unsigned int x, n;

    printf("Berechnung der Exponential-Reihe\n");
    printf("========================================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\nx? ");
        int inputok = scanf("%u", &x);

        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                run = false;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        printf("\nn? ");
        inputok = scanf("%u", &n);
        // Check input
        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                run = false;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        double summe = 0;
        for(unsigned int i = 0; i <= n; i++)
            summe += pow(x, i) / factorial(i);
        
        printf("  e hoch %u = %f (bis zum %u. Glied)\n", x, summe, n);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}