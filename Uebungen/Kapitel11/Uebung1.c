/**********************************************************************\
* Kurzbeschreibung: Uebung: 11.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 10.04.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int year;
    printf("Geben Sie das Jahr an, das auf ein Schaltjahr geprüft werden soll: ");
    scanf("%d", &year);
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                printf("  ---> Schaltjahr");
            else
                printf("  ---> Kein Schaltjahr");
        }
        else
            printf("  ---> Schaltjahr");
    }
    else
        printf("  ---> Kein Schaltjahr");

    fflush(stdin);
    getchar();
    return 0;
}