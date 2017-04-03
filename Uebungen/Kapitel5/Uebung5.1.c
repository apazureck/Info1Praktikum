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

    u = 256;
    wert = 0;

    // pattern 0x7FF0 equals 0b 0111 1111 0000 0000
    // Check if bits 4 to 8 are set and HSB is not set (indicates negative value)
    // printf("u:       ");
    // printbinary(u);
    // printf("pattern: ");
    // printbinary(0x7F00);

    if ((u & 0x7F00) && !(u & 0x8000))
        wert = 1;

    printf("2. Wert: %d\n", wert);

    // 3. ob das 7.Bit (von links her gezählt) in der unsigned short-Variablen u auf 1 gesetzt ist
    u = 520;
    wert = 0;

    // printf("u:       ");
    // printbinary(u);
    // printf("pattern: ");
    // printbinary(0x0200);

    if (u & 0x0200)
        wert = 1;

    printf("3. Wert: %d\n", wert);

    // 4. ob der Wert der short-Variablen x im Intervall [0,127] liegt

    x = 0;
    wert = 1;

    printbinary(x);
    printbinary(0xFF80);
    if (x & 0xFF80)
        wert = 0;

    printf("4. Wert: %d\n", wert);

    // 5. ob der Wert der unsigned short-Variablen u durch 4 teilbar ist
    u = 43;

    wert = 1;
    if (u & 0x3)
        wert = 0;

    printf("4. Wert: %d\n", wert);

    fflush(stdin);
    getchar();
    return 0;
}

int printbinary(int n)
{
    printf("0b");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}