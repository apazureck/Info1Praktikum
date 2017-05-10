/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    char input;

    printf("     Hauptmenue\n     ==========\n");
    printf("[A]endern\n[B]eenden\n[D]rucken\n[E]ingeben\n[L]oeschen\n\nWas wuenschen Sie zu tun ? ");
    scanf("%c", &input);

    fflush(stdin);

    switch (input)
    {
    case 'a':
    case 'A':
        printf("..... Sie haben (A)endern gewaehlt .....");
        break;
    case 'b':
    case 'B':
        printf("..... Sie haben (B)eenden gewaehlt .....");
        break;
    case 'd':
    case 'D':
        printf("..... Sie haben (D)rucken gewahlt .....");
        break;
    case 'e':
    case 'E':
        printf("..... Sie haben (E)ingeben gewaehlt .....");
        break;
    case 'l':
    case 'L':
        printf("..... Sie haben (L)oeschen gewahlt .....");
        break;
    default:
        printf("..... Ihre Wahl '%c' ist unerlaubt .....", input);
        break;
    }

    fflush(stdin);
    getchar();
    return 0;
}