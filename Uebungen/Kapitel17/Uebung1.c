/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../headers/constants.h"
#include <time.h>

/*--- Funktionsdefinitionen ------------------------------------------*/

int main(void)
{
    int run = true;

    // Initialize random generator
    srand(time(NULL));

    printf("Zahlen Raten\n");
    printf("============\n");

    while (run)
    {
        printf("Ich denke mir eine Zahl aus dem Interfall [1,x]\n");
        printf("Du musst dann versuchen, diese Zahl zu erraten.\n\n");
        printf("Zunaechst musst du einmal festlegen, wie gross die zu\n");
        printf("ratende Zahl maximal sein darf: ");

        unsigned int res;
        int max;
        char tmp;
        res = scanf("%d%c", &max, &tmp);
        fflush(stdin);

        while (res != 2 || tmp != '\n' || max < 1)
        {
            printf("Kein gueltiger Wert. Gib eine gueltige, positive Ganzzahl Zahl ein: ");
            res = scanf("%d%c", &max, &tmp);
            fflush(stdin);
        }

        printf("Hm.... ");
        int zahl = rand() % max + 1,
            guess,
            loopcounter = 1;

        printf("OK, ich habe eine Zahl. Druecke q zum beenden.\n");

        do
        {
            printf("Dein %d. Versuch: ", loopcounter++);
            res = scanf("%d%c", &guess, &tmp);

            if (res != 2 || tmp != '\n' || guess < 1 || guess > max)
            {
                if (res == 0)
                    tmp = getchar();
                if (tmp == 'q' || tmp == 'Q')
                {
                    run = false;
                    break;
                }
                printf("Deine Zahl ist ungueltig. Gib eine positive Ganzzahl im Bereich von 1 bis %u ein.\n", max);
            }
            else
            {
                if (guess < zahl)
                    printf("%30s", "..... zu niedrig\n");
                else if (guess > zahl)
                    printf("%30s", "..... zu hoch\n");
            }
            fflush(stdin);
        } while (guess != zahl);
        if (run)
            printf("\nDu hast %d Versuche zum Erraten der Zahl benoetigt.\n\n", loopcounter);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}