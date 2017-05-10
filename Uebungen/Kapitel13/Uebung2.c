/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

#define SQUARE 'q' : case 'Q'
#define RECTANGLE 'r' : case 'R'
#define CIRCLE 'k' : case 'K'
#define ELLIPSE 'e' : case 'E'

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    char input;
    double blen, bheight;

    printf("   Quadrat:   q\n");
    printf("   Rechteck:  r\n");
    printf("   Kreis:     k\n");
    printf("   Ellipse:   e\n");
    printf("Deine Wahl? ");
    scanf("%c", &input);

    fflush(stdin);

    switch (input)
    {
    case SQUARE:
        printf("Seitenlaenge des Quadrats: ");
        scanf("%lf", &blen);
        printf("\n..... Flaeche = %.2lf", blen * blen);
        break;
    case RECTANGLE:
        printf("Laenge der 1. Rechteckseite: ");
        scanf("%lf", &blen);
        printf("Laenge der 2. Rechteckseite: ");
        scanf("%lf", &bheight);
        printf("\n..... Flache = %.2lf", blen * bheight);
        break;
    case CIRCLE:
        printf("Radius des Kreises: ");
        scanf("%lf", &blen);
        printf("\n..... Flaeche = %.2lf", blen * blen * M_PI);
        break;
    case ELLIPSE:
        printf("Radius der X-Achse: ");
        scanf("%lf", &blen);
        printf("Radius der y-Achse: ");
        scanf("%lf", &bheight);
        printf("\n...... Flaeche = %.2lf", blen * bheight * M_PI);
        break;
    default:
        printf("..... '%c' ist keine erlaubte Wahl", input);
        break;
    }

    fflush(stdin);
    getchar();
    return 0;
}