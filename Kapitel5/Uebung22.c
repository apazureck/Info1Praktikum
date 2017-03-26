/**********************************************************************\
* Kurzbeschreibung: Uebung: 5.2.2; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 26.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
int main(void)
{
    float pi, t1, t2, t3, t4, t5;
    t1 = 292 + 0.5;
    t2 = 1 + 1 / t1;
    t3 = 15 + 1 / t2;
    t4 = 7 + 1 / t3;
    pi = 3 + 1 / t4;

    printf("Pi = %f\n", pi);

    fflush(stdin);
    getchar();
    return 0;
}
