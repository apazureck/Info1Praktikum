/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include "../headers/constants.h"
#include "./Uebung2.2.h"

int main(void)
{
    int run = true;

    printf("Funktionen fuer Binaere Operatoren\n");
    printf("==================================\n");

    workingbyte = getStartByte();
    unsigned char fallback = workingbyte;

    while (run)
    {
        int workingBit = getOperatingBit();
        run = processOnByte(workingBit, fallback, getOperation());
    }

    printf("\n\n=> Ende.");

    fflush(stdin);
    getchar();
    return 0;
}

unsigned char getStartByte()
{
    int b0, b1, b2, b3, b4, b5, b6, b7;
    int inputInvalid = false;
    do
    {
        printf("Bitte geben Sie 1 Byte als binaere Folge ein: ");
        inputInvalid = scanf("%1d%1d%1d%1d%1d%1d%1d%1d", &b0, &b1, &b2, &b3, &b4, &b5, &b6, &b7) != 8;
        fflush(stdin);
        inputInvalid = inputInvalid || checkInput(b0);
        inputInvalid = inputInvalid || checkInput(b1);
        inputInvalid = inputInvalid || checkInput(b2);
        inputInvalid = inputInvalid || checkInput(b3);
        inputInvalid = inputInvalid || checkInput(b4);
        inputInvalid = inputInvalid || checkInput(b5);
        inputInvalid = inputInvalid || checkInput(b6);
        inputInvalid = inputInvalid || checkInput(b7);
        if (inputInvalid)
            printf("Kein gueltiges Byte. Bitte noch einmal eingeben.\n");
    } while (inputInvalid);

    return b0 << 7 | b1 << 6 | b2 << 5 | b3 << 4 | b4 << 3 | b5 << 2 | b6 << 1 | b7;
}

int checkInput(int b)
{
    return b < 0 || b > 1;
}

int getOperatingBit()
{
    int retbyte;
    int inputInvalid = true;
    do
    {
        printf("Auf welche Bitposition soll sich die Operation beziehen? (7..0): ");
        inputInvalid = scanf("%d", &retbyte) != 1;
        fflush(stdin);
        inputInvalid = retbyte < 0 || retbyte > 7;
        if (inputInvalid)
            printf("Die Eingabe ist ungueltig.\n");
    } while (inputInvalid);
    return retbyte;
}

int processOnByte(int workonbit, unsigned char fallback, int operation)
{
    switch (operation)
    {
    case CMD_BIT_CHECK:
        printf("%d: Bit pruefen\n", CMD_BIT_CHECK);
        cmd_checkbit(workonbit, workingbyte);
        break;
    case CMD_END:
        printf("%d: Beenden\n", CMD_END);
        return false;
        break;
    case CMD_BIT_NEGATE:
        printf("%d: Bit negieren\n", CMD_BIT_NEGATE);
        workingbyte = cmd_negateBit(workonbit, workingbyte);
        break;
    case CMD_BIT_RESET:
        printf("%d: Bit ruecksetzen/loeschen\n", CMD_BIT_RESET);
        workingbyte = cmd_resetBit(workonbit, workingbyte);
        break;
    case CMD_BIT_SET:
        printf("%d: Bit setzen\n", CMD_BIT_SET);
        workingbyte = cmd_setBit(workonbit, workingbyte);
        break;
    default:
        printf("Unbekanntes Kommando\n");
        break;
    }
    printf("Nach der Bitoperation ergibt sich folgendes Bitmuster fuer das Byte: ");
    printbinary(workingbyte, 8, 4, ' ');
    printf("\n\n");
    return true;
}

void printMenu()
{
    printf("1: Bit pruefen\n");
    printf("2: Bit setzen\n");
    printf("3: Bit zurecksetzen/loeschen\n");
    printf("4: Bit negieren\n");
    printf("5: Ende\n");
}

int getOperation()
{
    int inputinvalid, selection;
    unsigned char c = 0;
    printMenu();
    do
    {
        printf("Deine Wahl: ");
        inputinvalid = scanf("%d%c", &selection, &c) != 2 || c != '\n';
        inputinvalid = selection > 5 || selection < 1;
        if(inputinvalid)
            printf("Eingabe ungueltig. Bitte nur eine Angabe aus dem Menue verwenden.\n");
    } while (inputinvalid);
    return selection;
}

void printbinary(int value, int n, int breakafter, char breakcharacter)
{
    printf("0b");
    for (int i = n-1; i >= 0; i--)
    {
        printf("%d", (value >> i) & 1);
        if (i % breakafter == 0)
            printf("%c", breakcharacter);
    }
}

void cmd_checkbit(int workonbit, unsigned char workingbyte)
{
    printf("Bit %d ist im Byte: %s\n", workonbit, ((workingbyte >> workonbit) & 1) ? "gesetzt" : "nicht gesetzt");
}

unsigned char cmd_negateBit(int workonbit, unsigned char workingbyte)
{
    printf("Neuer Wert des Bits %d: %d\n", workonbit, !((workingbyte >> workonbit) & 1));
    return setBit(workonbit, workingbyte, !((workingbyte >> workonbit) & 1));
}

unsigned char setBit(int workonbit, unsigned char workingbyte, int newvalue)
{
    unsigned char mask = !(newvalue & 1) << workonbit;
    mask = ~mask;
    workingbyte &= mask;
    return workingbyte | newvalue << workonbit;
}

unsigned char cmd_setBit(int workonbit, unsigned char workingbyte)
{
    printf("Neuer Wert des Bits %d: %d\n", workonbit, 1);
    return setBit(workonbit, workingbyte, 1);
}

unsigned char cmd_resetBit(int workonbit, unsigned char workingbyte)
{
    printf("Neuer Wert des Bits %d: %d\n", workonbit, 0);
    return setBit(workonbit, workingbyte, 0);
}