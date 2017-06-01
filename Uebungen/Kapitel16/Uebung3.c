/**********************************************************************\
* Kurzbeschreibung: Uebung: 13.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 25.03.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/constants.h"

/*--- Funktionsdefinitionen ------------------------------------------*/

void cleaninput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    int run = true, ok = false;
    unsigned int shove;
    char textbuffer[501];

    printf("Verschlüsseln mit einem Verschiebechiffre\n");
    printf("=============================================\n");
    printf("Druecke 'q' zum beenden.\n\n");
    printf("Der wievielte Nachfolger soll immer genommen werden? ");

    while (!ok)
    {
        ok = scanf("%u", &shove);
        ok = ok && shove < 26;
        if (!ok)
        {
            printf("Der eingegebene Wert ist keine positive Ganzzahl kleiner 26 sein!\nDer wievielte Nachfolger soll immer genommen werden? ");
        }
        cleaninput();
    }

    printf("Gib nun den zu verschluesselten Text ein.\n");
    while (run)
    {
        scanf("%500s", &textbuffer[0]);
        if (textbuffer[0] == 'q' || textbuffer[0] == 'Q')
        {
            if (textbuffer[1] == 0)
            {
                run = false;
                continue;
            }
        }
        int i = 0;
        while (textbuffer[i])
        {
            char tmp = textbuffer[i];
            //captial letters
            if (tmp >= 'A' && tmp <= 'Z')
            {
                tmp += shove;
                if (tmp > 'Z')
                    tmp = 'A' + tmp - 'Z' - 1;
            }
            else if (tmp >= 'a' && tmp <= 'z')
            {
                tmp += shove;
                if (tmp > 'z')
                    tmp = 'a' + tmp - 'z' - 1;
            }
            textbuffer[i] = tmp;
            i++;
        }

        printf("%s\n", textbuffer);
        cleaninput();
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}