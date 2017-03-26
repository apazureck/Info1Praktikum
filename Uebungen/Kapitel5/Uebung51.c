/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.5.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 26.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/

int printbinary(int);

int main(void)
{
    int wert;
    short x, u;

    // 1. ob der Wert der short-Variablen x ungerade ist.
    x = 7;

    wert = 0;

    if (x & 0x1)
        wert = 1;

    printf("1. Wert: %d\n", wert);

    // 2. ob der Wert der unsigned short-Variablen u groesser als 255 ist.

    u = 255;
    wert = 0;

    // pattern 0xFF0 equals 0b 0000 1111 1111 0000
    // Check if bits 4 to 8 are set and HSB is not set (indicates negative value)
    printf("u:       ");
    printbinary(u);
    printf("pattern: ");
    printbinary(0xFF0);
    if ((u & 0xFF0) && !(u & 0x8000))
        wert = 1;

    printf("2. Wert: %d\n", wert);

    fflush(stdin);
    getchar();
    return 0;
}

int printbinary(int n)
{
    printf("0b");
    for(int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if(i%4==0)
            printf(" ");
    }
    printf("\n");
}