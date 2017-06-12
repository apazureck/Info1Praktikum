/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/constants.h"
#include "Uebung3.2.h"

int main(void)
{
    int n1, n2, n3, n4;
    printf("Sortieren von 4 Zahlen\n");
    printf("======================\n");

    n1 = readNumber();
    n2 = readNumber();
    n3 = readNumber();
    n4 = readNumber();

    if (n1 < n2 && n2 < n3 && n3 < n4)
        printf("Was soll das?!\nDie Zahlen sind bereits sortiert!\n");
    else
    {
        sortNumbers(n1, n2, n3, n4);
    }

    fflush(stdin);
    getchar();
    return 0;
}

int readNumber()
{
    int invalidInput = false, number;
    char c;
    do
    {
        printf("Zahl?: ");
        invalidInput = scanf("%d%c", &number, &c) != 2 || c != '\n';
        if (invalidInput)
            printf("Die Eingabe ist inkorrekt. Bitte eine korrekte Ganzzahl eingeben:\n");
    } while (invalidInput);
    return number;
}

int sortNumbers(int n1, int n2, int n3, int n4)
{
    int getauscht, count = 0;
    do
    {
        int tmp;
        getauscht = false;
        if (n1 > n2)
        {
            tmp = n1;
            n1 = n2;
            n2 = tmp;
            getauscht = true;
        }
        if (n2 > n3)
        {
            tmp = n2;
            n2 = n3;
            n3 = tmp;
            getauscht = true;
        }
        if (n3 > n4)
        {
            tmp = n3;
            n3 = n4;
            n4 = tmp;
            getauscht = true;
        }
        if(getauscht)
            printNumbers(n1, n2, n3, n4, ++count);
    } while (getauscht);
    printf("!!!! FERTIG nach %d Durchlaeufen !!!!!", count);
}

void printNumbers(int n1, int n2, int n3, int n4, int count)
{
    printf("  %d. Durchlauf - Aktueller Stand\nZahl 1: %d\nZahl 2: %d\nZahl 3: %d\nZahl 4: %d\nWeiter mit return...\n", count, n1, n2, n3, n4);
    fflush(stdin);
    getchar();
    fflush(stdin);
}