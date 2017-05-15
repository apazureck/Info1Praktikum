/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12
#define true 1
#define false 0

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    char input, run = true;
    unsigned int days, months, years;
    unsigned int nday, nmonth, nyear, ok = true;

    printf("Folgedatum zu einem Datum\n");
    printf("=========================\n");
    printf("Druecke 'q' zum beenden\n");

    while (run)
    {
        printf("\nDieses Programm liest ein Kalender-Datum ein, und gibt dann\n");
        printf("das Datum des nachfolgenden Tages aus.\n\n");

        printf("Gib ein Datum ein (tt.mm.jjj): ");
        int res = scanf("%2u.%2u.%4u", &days, &months, &years);

        if (!res)
        {
            printf("Keine gueltige Datumseingabe erkannt.\n");
            input = getchar();
            if (input == 'q' || input == 'Q')
                run = false;
            fflush(stdin);
            continue;
        }
        nday = days;
        nmonth = months;
        nyear = years;

        if (months > 12)
            ok = false;
        else
            switch (days)
            {
            case 28:
                if (months == 2)
                {
                    if ((!(years % 4) && years % 100) || !(years % 400))
                        nday++;
                    else
                    {
                        nday = 1;
                        nmonth++;
                    }
                }
                else
                    nday++;
                break;
            case 29:
                if (months == 2)
                {
                    if (!(years % 4) && years % 100 || !(years % 400))
                    {
                        nmonth++;
                        nday = 1;
                    }
                    else
                        ok = false;
                }
                else
                    nday++;
                break;
            case 30:
                // has 31 days?
                if (months == JAN || months == MAR || months == MAY || months == JUL || months == AUG || months == OCT || months == DEC)
                    nday++;
                // has 30 days
                else
                {
                    nmonth++;
                    nday = 1;
                }
                break;
            case 31:
                // check if month does not have 31 days
                if (months == FEB || months == APR || months == JUN || months == SEP || months == NOV)
                    ok = false;
                // Check if it is december
                else if (months == DEC)
                {
                    nyear++;
                    nmonth = JAN;
                    nday = 1;
                }
                else
                {
                    nmonth++;
                    nday = 1;
                }
                break;
            default:
                if (days < 28)
                    nday++;
                else
                    ok = false;
                break;
            }

        if (ok)
            printf("%2u.%2u.%4u ---> %2u.%2u.%4u", days, months, years, nday, nmonth, nyear);
        else
            printf("%2u.%2u.%4u ist kein gueltiges Datum.\n", days, months, years);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}