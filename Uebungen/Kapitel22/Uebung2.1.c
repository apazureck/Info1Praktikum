/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/constants.h"
#include "./Uebung2.1.h"

int main(void)
{
    int run = true;
    double sum = 0;
    printf("Laenge eines Streckenzuges\n");
    printf("==========================\n");

    // printf("\nDruecke q zum Beenden.\n\n");

    getStartPoint();

    do
    {
        run = getPoints();
        if (run)
        {
            sum += getEuclidDistance(x, y, oldx, oldy);
            printf("Die neue Streckenlänge betraegt: %.2f Einheiten\n", sum);
            oldx = x;
            oldy = y;
        }
    } while (run);

    printf("\n\n=> Die resultierende Streckenlaenge betraegt: %.2f Einheiten.", sum);

    fflush(stdin);
    getchar();
    return 0;
}

void getStartPoint()
{
    int invalid = false;
    char c;
    do
    {
        if (invalid)
            printf("Eingabe nicht korekt. Bitte Ganzzahlen eingeben.\n");
        printf("Bitte Starpunkt eingeben (x,y): ");
        int res = scanf("%d,%d%c", &oldx, &oldy, &c);
        fflush(stdin);
        invalid = res != 3 || c != '\n';
    } while (invalid);
}

int getPoints()
{
    int invalid = false;
    char c;
    do
    {
        if (invalid)
            printf("Eingabe nicht korekt. Bitte Ganzzahlen eingeben.\n");
        printf("Neuer Streckenpunkt x,y (Abbruch mit -1): ");
        int res = scanf("%d,%d%c", &x, &y, &c);
        fflush(stdin);
        invalid = res != 3 || c != '\n';
        if (res == 1 && x == -1)
            return false;
    } while (invalid);
    return true;
}

double getEuclidDistance(int x0, int y0, int x1, int y1)
{
    return sqrt(pow(x0 - x1, 2.0) + pow(y0 - y1, 2));
}