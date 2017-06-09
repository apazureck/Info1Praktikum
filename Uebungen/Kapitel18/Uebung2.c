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

const int MAX = 5, DICESIDES = 6;

/*--- Funktionsdefinitionen ------------------------------------------*/

int main(void)
{
    int run = true, i, mhalf, scanfres = 0, m, n;

    // Initialize random generator
    srand(time(NULL));

    printf("Primzahlen\n");
    printf("==========\n");

    do
    {
        printf("Geben Sie den Bereich (m,n ; n > m > 0) ein,\nfuer den die Primzahlen ausgegeben werden sollen: ");
        scanfres = scanf("%d,%d", &m, &n);
        fflush(stdin);
    } while (scanfres != 2 || m >= n || n < 2 || m < 1);

    
    while (m <= n)
    {
        mhalf = m / 2;
        int prime = true;
        for (i = 2; i <= mhalf; i++)
            if (!(m % i))
            {
                prime = false;
                break;
            }
        if (prime)
            printf("%8d,", m);
        m++;
    }

    fflush(stdin);
    getchar();
    return 0;
}