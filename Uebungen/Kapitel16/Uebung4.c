/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include "../headers/constants.h"

/*--- Funktionsdefinitionen ------------------------------------------*/

void cleaninput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    unsigned int numCount;
    int ok = false;

    printf("Wie viele Zahlen? ");
    while (!ok)
    {
        ok = scanf("%u", &numCount);
        ok = ok && numCount > 0;
        if(ok)
            break;
        printf("Die Eingabe ist keine gueltige Zahl > 0\n");
        printf("Wie viele Zahlen? ");
    }

    double numbers[numCount];

    for (unsigned int i = 0; i < numCount; i++)
    {
        printf("%u. Zahl: ", i + 1);
        while (!scanf("%lf", &numbers[i]))
        {
            printf("Eingabe ist keine gueltige Gleitkommazahl. Bitte noch einmal.\n");
            printf("%u. Zahl: ", i + 1);
            cleaninput();
        }
    }

    unsigned int j = 0, maxIndex = 0, minIndex = 0;
    while (j < numCount)
    {
        if (numbers[j] < numbers[minIndex])
            minIndex = j;
        else if (numbers[j] > numbers[maxIndex])
            maxIndex = j;

        j++;
    }

    printf("--> Die %u. Zahl (%.2lf) war die groesste Zahl.\n", maxIndex + 1, numbers[maxIndex]);
    printf("--> Die %u. Zahl (%.2lf) war die kleinste Zahl.\n", minIndex + 1, numbers[minIndex]);

    fflush(stdin);
    getchar();
    return 0;
}