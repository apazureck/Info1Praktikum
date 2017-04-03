/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.4.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 26.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int wert;
    int a, b, x, y, z, jahr, zaehler;
    char antwort;

    // 1. ob der Wert der Variablen a im Intervall [-20,100] liegt
    a = -15;

    wert = a >= -20 && a <= 100;

    printf("1. Wert: %d\n", wert);

    // 2. ob Wert der Variablen x negativ ist, aber zugleich auch der Wert der Variablen y im Intervall [5,30] liegt

    x = 1;
    y = 7;

    wert = x < 0 && y >= 5 && y <= 30;

    printf("2. Wert: %d\n", wert);

    // 3. ob Wert der ganzzahligen Variablen z ungerade ist und zugleich auch durch 3 und 5 teilbar ist

    z = 15;
    wert = 0;

    wert = z % 2 != 0 && z % 3 == 0 && z % 5 == 0;

    printf("3. Wert: %d\n", wert);

    // 4. ob der Wert der ganzzahligen Variablen jahr durch 400 oder durch 4, aber nicht durch 100 teilbar ist (Bedingung für ein Schaltjahr)

    jahr = 2100;
    wert = 0;

    wert = jahr % 400 == 0 || (jahr % 4 == 0) && (jahr % 100 != 0);

    printf("4. Wert: %d\n", wert);

    // 5. ob das Produkt der beiden int-Variablen a und b in den Datentyp unsigned char ohne Überlauf untergebracht werden kann
    // Character ist 8 bit integer => maxvalue = 255

    a = 25;
    b = 10;
    wert = 0;

    wert = a * b <= 255;

    printf("5. Wert: %d\n", wert);

    // 6. ob der Wert der char-Variablen antwort weder das Zeichen ’j’ noch das Zeichen ’J’ enthält

    antwort = 'A';
    wert = 0;

    wert = antwort != 'j' || antwort != 'J';

    printf("6. Wert: %d\n", wert);

    // 7. ob der Wert der int-Variablen zaehler nicht im Intervall [5,25] liegt

    zaehler = 30;

    wert = 1;

    wert = zaehler >= 5 && zaehler <= 25;

    printf("7. Wert: %d\n", wert);

    fflush(stdin);
    getchar();
    return 0;
}