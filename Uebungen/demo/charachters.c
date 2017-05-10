/**********************************************************************\
* Kurzbeschreibung: Uebung: 1.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    char input;

    while(1) {
        input = (char)getchar();
        printf("%c", input);
        printf("%d", input);
    }
}