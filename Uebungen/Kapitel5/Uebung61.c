/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.6.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 27.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    unsigned short x = 0x12ab, y = 0, z = 0;
    printf("Initial Value: 0x%X\n", x);
    y = x >> 8;
    // printf("%X\n", y);
    z = (x & 0xFF);
    z = z << 8;
    // printf("%X\n", z);
    x = y | z;
    printf("New Value:     0x%X\n", x);
    fflush(stdin);
    getchar();
    return 0;
}