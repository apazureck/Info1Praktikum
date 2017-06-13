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
#include "Uebung1.1.h"

int main(void)
{
    srand(time(NULL));
    int arrlength = getNumbers();
    int numbersToDraw = getDraws(arrlength);
    printDrawnNumbers(numbersToDraw, arrlength);

    fflush(stdin);
    getchar();
    return 0;
}

int getNumbers() {
    int inputInvalid, numbers;
    char c;
    do {
        printf("Wieviele Kugeln sollen zur Verfuegung stehen (mind. 1 und max %d): ", MAX_NUMBERS); 
        inputInvalid = scanf("%d%c", &numbers, &c) != 2 || c != '\n';
        inputInvalid |= numbers < 1 || numbers > MAX_NUMBERS;
        if(inputInvalid)
            printf("Eingabe ungueltig!\n");
    } while(inputInvalid);
    return numbers;
}

int getDraws(int max) {
    int inputInvalid, numbers;
    char c;
    do {
        printf("Wieviele werden davon gezogen (mind. 1 und max. %d): ", max); 
        inputInvalid = scanf("%d%c", &numbers, &c) != 2 || c != '\n';
        inputInvalid |= numbers < 1 || numbers > max;
        if(inputInvalid)
            printf("Eingabe ungueltig!\n");
    } while(inputInvalid);
    return numbers;
}

void printDrawnNumbers(int count, int all) {
    int aAll[all], picks[count], i, rest = all;

    for(i = 0; i < all; i++)
        aAll[i] = i + 1;

    for(i = 0; i < count; i++) {
        // Pick random index
        int iPick = rand() % rest--;
        // Set pick on output array
        picks[i] = aAll[iPick];
        // copy last entry to picked number to cross it out
        aAll[iPick] = aAll[rest];
    }

    bubblesort(picks, count);

    printf("===== %d aus %d =====\n", count, all);
    for(i = 0; i<count; i++)
        printf("%5d", picks[i]);
}

void bubblesort(int *array, int length)
 {
     int i, j;
     for (i = 0; i < length - 1; ++i) 
     {

        for (j = 0; j < length - i - 1; ++j) 
        {
            if (array[j] > array[j + 1]) 
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
     }
 }