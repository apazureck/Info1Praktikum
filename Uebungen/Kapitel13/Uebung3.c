/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

#define SQUARE 'q' : case 'Q'
#define RECTANGLE 'r' : case 'R'
#define CIRCLE 'k' : case 'K'
#define ELLIPSE 'e' : case 'E'

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    char input;
    unsigned int days, months, years;
    unsigned int nday, nmonth, nyear, ok = true;

    printf("Folgedatum zu einem Datum\n");
    printf("=========================\n");
    printf("Dieses Programm liest ein Kalender-Datum ein, und gibt dann\n");
    printf("das Datum des nachfolgenden Tages aus.\n\n");

    printf("Gib ein Datum ein (tt.mm.jjj): ");
    scanf("%2u.%2u.%4u", &days, &months, &years);

    nday = days;
    nmonth = months;
    nyear = years;

    if (months > 12)
        printf("%2u.%2u.%4u ist kein gueltiges Datum.\n", days, months, years);
    else if (months == 2)
    {
    }
    else
        switch (days)
        {
        case 29:
            if(months == 2) {

            } else {
                nday++;
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

    fflush(stdin);
    getchar();
    return 0;
}