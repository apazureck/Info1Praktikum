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
    // testcomment
    printf("     Hauptmenue\n     ==========\n");
    printf("[A]endern\n[B]eenden\n[D]rucken\n[E]ingeben\n[L]oeschen\n\nWas wuenschen Sie zu tun ?");

    fflush(stdin);
    getchar();
    return 0;
}