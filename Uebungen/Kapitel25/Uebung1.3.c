/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/constants.h"
#include "Uebung1.3.h"

int main(void)
{
    int iterations = getIterations(), i, changed = 0, stayed = 0;
    srand(time(NULL));

    for (i = 0; i < iterations; i++)
    {
        // Initialize the doors
        int doors[3] = {0, 0, 0};
        // Set the winning door
        doors[rand() % 3] = 1;
        int pick = rand() % 3;
        int tip;
        do
            tip = rand() % 3;
        while (tip == pick && doors[tip]);

        int change;
        for (change = 0; change < 3; change++)
            if(change != tip && change != pick)
                break;
        
        if(doors[change])
            changed++;
        
        if(doors[pick])
            stayed++;
    }

    printf("\n");
    printf("----------------------------------------------------\n");
    printf("Der Moderator darf weder Rate- noch Auto-Tuer oeffnen\n");
    printf("   Gewinnchance beim Wechseln:       ..... %.2lf%%\n", (double)changed/iterations*100);
    printf("                beim Nicht-Wechseln: ..... %.2lf%%\n\n", (double)stayed/iterations*100);

    printf("----------------------------------------------------\n");

    fflush(stdin);
    getchar();
    return 0;
}

int getIterations()
{
    int inputinvalid, iterations;
    char c;
    do
    {
        printf("Anzahl der Simulationen: ");
        inputinvalid = scanf("%d%c", &iterations, &c) != 2 || c != '\n';
        if (inputinvalid)
            printf("Eingabe ungueltig.\n");
    } while (inputinvalid);
    return iterations;
}