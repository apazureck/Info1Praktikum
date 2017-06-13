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
#include "Uebung1.2.h"

int main(void)
{
    const int end = 1000;
    int crossed[end], i, j, primenumbers[end], pnmlength = 0;

    // Initialisiere allnumbersays
    for (i = 0; i < end; i++)
        crossed[i] = 1;
    
    i = 1;
    crossed[0] = 0;
    while(i<end) {
        primenumbers[pnmlength++] = i+1;
        for(j = i; j < end; j += i+1) {
            crossed[j] = 0;
        }
        i = getNextPrimeNumber(crossed, i+1, end);
    }

    printf("Die Primzahlen von 1 bis %d sind:\n", end);
    for(i = 0; i < pnmlength; i++)
        printf("%5d", primenumbers[i]);

    fflush(stdin);
    getchar();
    return 0;
}

int getNextPrimeNumber(int crossed[], int start, int end) {
    int i = start;
    while (i < end && !crossed[i]) 
        i++;
    return i;
}