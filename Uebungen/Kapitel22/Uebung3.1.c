/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/constants.h"
#include "Uebung3.1.h"

int main(void)
{
    printf("Taschenrechner fuer Uhrzeiten\n");
    printf("=============================\n");

    getTime1();
    getTime2();

    char command = getCommand();

    switch (command)
    {
    case '+':
        addTime(h1, m1, s1, h2, m2, s2);
        break;
    case '-':
        subtractTime(h1, m1, s1, h2, m2, s2);
        break;
    default:
        printf("Ungueltige Eingabe!\n");
    }

    fflush(stdin);
    getchar();
    return 0;
}

void getTime1()
{
    int inputinvalid;
    char c;
    do
    {
        printf("Bitte Startzeit eingeben (hh:mm:ss): ");
        int scanfres = scanf("%d:%d:%d%c", &h1, &m1, &s1, &c);
        inputinvalid = scanfres != 4 || c != '\n';
        fflush(stdin);
        inputinvalid |= m1 > 59 || m1 < 0;
        inputinvalid |= s1 > 59 || s1 < 0;
        inputinvalid |= h1 < 0;
        if (inputinvalid)
            printf("Ungueltige Eingabe!\n");
    } while (inputinvalid);
}

void getTime2()
{
    int inputinvalid;
    char c;
    do
    {
        printf("Bitte 2. Zeit eingeben (hh:mm:ss): ");
        inputinvalid = scanf("%d:%d:%d%c", &h2, &m2, &s2, &c) != 4 || c != '\n';
        fflush(stdin);
        inputinvalid |= m2 > 59 || m2 < 0;
        inputinvalid |= s2 > 59 || s2 < 0;
        inputinvalid |= h2 < 0;
        if (inputinvalid)
            printf("Ungueltige Eingabe!\n");
    } while (inputinvalid);
}

char getCommand()
{
    int inputinvalid;
    char command, c;
    do
    {
        printf("Bitte Operation eingeben (+/-): ");
        inputinvalid = scanf("%c%c", &command, &c) != 2 || c != '\n';
        fflush(stdin);
        inputinvalid = !(command == '+' || command == '-');
        if (inputinvalid)
            printf("Ungueltige Eingabe!\n");
    } while (inputinvalid);
    return command;
}

void addTime(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int resd = 0, resh, resm, ress;

    ress = s1 + s2;
    resm = m1 + m2;
    resh = h1 + h2;
    if (ress > 59)
    {
        resm++;
        ress -= 60;
    }
    if (resm > 59)
    {
        resh++;
        resm -= 60;
    }
    if (resh > 23)
    {
        resd = resh / 24;
        resh %= 24;
    }
    printf("%02d:%02d:%02d + %02d:%02d:%02d = %d Tag%c %02d:%02d:%02d", h1, m1, s1, h2, m2, s2, resd, resd == 1 ? ' ' : 'e', resh, resm, ress);
}

void subtractTime(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int resd = 0, resh, resm, ress;

    ress = s1 - s2;
    resm = m1 - m2;
    resh = h1 - h2;
    if (ress < 0)
    {
        resm--;
        ress += 60;
    }
    if (resm < 0)
    {
        resh--;
        resm += 60;
    }
    printf("%02d:%02d:%02d + %02d:%02d:%02d = %c %02d:%02d:%02d", h1, m1, s1, h2, m2, s2, resh < 0 ? '-': ' ', resh, resm, ress);
}