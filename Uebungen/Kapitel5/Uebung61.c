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
    printf("Number 1: %i\n", (18/2*(4+5)/(9-6))%(6+8/4));
    printf("Number 2: %i\n", (4-10+(100+100-40+80)/5/2/4+36)/((90-30)/(10-5)));
    fflush(stdin);
    getchar(); 
    return 0;
}