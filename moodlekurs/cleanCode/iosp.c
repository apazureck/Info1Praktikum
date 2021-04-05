#include <stdio.h>
#include <stdlib.h>
#include "../headers/constants.h"
#include <time.h>

const int MAX = 5, DICESIDES = 6;

/*--- Funktionsdefinitionen ------------------------------------------*/

int main(void)
{
    int run = true;

    // Initialize random generator
    srand(time(NULL));

    printf("Wuerfelspiel bis 100\n");
    printf("====================\n");

    printf("\nDruecke q zum Beenden.\n\n");

    printf("Bei diesem Wuerfelspiel wuerfelt jeder Spieler sooft er will.\n\
Verzichtet ein Spieler auf weiteres Wuerfeln, bevor er eine 1 wuerfelt,\n\
bekommt er die Summe der bisher erzielten Augen gutgeschrieben.\n\
Wuerfelt er aber eine 1, so erhaelt er gar nichts und der andere Spieler\n\
kommt an die Reihe. Es gewinnt, wer als erster 100 Augen hat.\n\n");

    unsigned int sumComputer = 0, sumPlayer = 0;
    while (run && sumPlayer < 100 && sumComputer < 100)
    {

        unsigned int diceroll, sum;
        int i;
        char tmp;

        printf("\nDer Computer ist an der Reihe:\n");
        // COMPUTER MOVE
        for (i = 0, sum = 0; i < MAX && sum < 19; i++)
        {
            diceroll = rand() % DICESIDES + 1;
            printf("Der Computer wuerfelt eine %u\n", diceroll);
            if (diceroll == 1)
            {
                printf("Der Computer hat eine 1 gewuerfelt. Die gesammelten Punkte von %u verfallen!\n\n", sum);
                break;
            }
            else
                sum += diceroll;
        }

        if (diceroll != 1)
        {
            sumComputer += sum;
        }

        printf("Aktueller Punktestand: %u : %u\n", sumComputer, sumPlayer);

        if (sumComputer > 100)
            break;

        printf("\nDer Spieler ist am Zug:\n");

        sum = 0;

        do
        {
            char userinput = 0;
            printf("Wuerfeln (j)? ");
            scanf("%c", &userinput);
            fflush(stdin);
            if (userinput == 'q' || userinput == 'Q')
            {
                run = false;
                return 0;
            }
            else if (userinput == 'j' || userinput == 'J')
            {
                diceroll = rand() % DICESIDES + 1;
                printf("Du hast eine %u gewuerfelt.\n", diceroll);
            }
            else
                break;

            if (diceroll == 1)
                break;
            sum += diceroll;
        } while (diceroll != 1);

        if (diceroll == 1)
            printf("Pech gehabt, Dir entgehen jetzt % u Punkte.\n", sum);
        else
        {
            sumPlayer += sum;
        }

        printf("Aktueller Punktestand: %u : %u\n", sumComputer, sumPlayer);
    }

    printf("Das Spiel wurde beendet. ");
    if (sumComputer > sumPlayer)
        printf("Der Computer hat gewonnen.");
    else
        printf("Du hast gewonnen, Glückwunsch!");
    fflush(stdin);
    getchar();
    return 0;
}