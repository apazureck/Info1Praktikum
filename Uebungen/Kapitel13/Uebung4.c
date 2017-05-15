/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int run = 1;
    char input;
    const double SQRT_PI = sqrt(M_PI);

    printf("Flaeche, Umfang und Radius eines Kreises\n");
    printf("========================================\n");

    while (run)
    {
        printf("\nDu kannst waehlen, was du eingeben moechtest.\n");
        printf("Ich berechne Dir dann die 2 fehlenden Groessen.\n");
        printf("\tFlaeche eingeben: %10s\n", "f");
        printf("\tUmfang eingeben:  %10s\n", "u");
        printf("\tRadius eingeben:  %10s\n", "r");
        printf("\tBeenden:          %10s\n", "q");
        printf("\nDeine Wahl? ");
        scanf("%1s", &input);

        switch (input)
        {
        case 'f':
        case 'F':
        {
            double flaeche;
            printf("Flaeche? ");
            int ok = scanf("%lf", &flaeche);
            if (!ok)
            {
                printf("Die Eingabe muss eine Zahl sein.\n");
                break;
            }
            printf("......Radius = %.2f\n", sqrt(flaeche / M_PI));
            printf("......Flaeche = %.2f\n", flaeche);
            printf("......Umfang = %.2f\n", sqrt(flaeche) * 2 * SQRT_PI);
        }
        break;
        case 'u':
        case 'U':
        {
            double umfang;
            printf("Umfang? ");
            int ok = scanf("%lf", &umfang);
            if (!ok)
            {
                printf("Die Eingabe muss eine Zahl sein.\n");
                break;
            }
            printf("......Radius = %.2f\n", umfang / M_PI / 2);
            printf("......Flaeche = %.2f\n", pow(umfang, 2) / (4 * M_PI));
            printf("......Umfang = %.2f\n", umfang);
        }
        break;
        case 'r':
        case 'R':
        {
            double radius;
            printf("Umfang? ");
            int ok = scanf("%lf", &radius);
            if (!ok)
            {
                printf("Die Eingabe muss eine Zahl sein.\n");
                break;
            }
            printf("......Radius = %.2f\n", radius);
            printf("......Flaeche = %.2f\n", pow(radius, 2) * (M_PI));
            printf("......Umfang = %.2f\n", radius * 2 * M_PI);
        }
        break;
        case 'q':
        case 'Q':
            run = false;
            break;
        default:
            printf("'%s' ist keine gueltige Eingabe.\n", input);
        }
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}