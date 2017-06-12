/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/

#ifndef UEBUNG2_2_H
#define UEBUNG2_2_H

/*--- Definitionen ---------------------------------------------------*/

#define CMD_BIT_CHECK 1
#define CMD_BIT_SET 2
#define CMD_BIT_RESET 3
#define CMD_BIT_NEGATE 4
#define CMD_END 5

/*--- Globale Variablen ----------------------------------------------*/

unsigned char workingbyte;

/*--- Funktionsdefinitionen ------------------------------------------*/
/*! Fragt den Benutzer nach dem Startbyte und prüft alle Werte auf korrekte Eingaben.
    /return Das eingegebene Byte.
*/
unsigned char getStartByte();
/*! Prüft ein eingegebenes Integer auf korrekte Werte.
    /return true (1), wenn Wert falsch ist, andernfalls 0;
*/
int checkInput(int b);

/*! Holt sich das Byte, auf dem gearbeitet werden soll
    /return Index des Bytes
*/
int getOperatingBit();

/*! Fuehrt die Eingegebenen Funktionen auf das Byte aus.
    /param workingbit Das Bit, auf das die Funktionen angewendet werden sollen.
    /param fallback Rückfallwert (originaleingabe)
    /param Operation, die durchgeführt werden soll.
*/
int processOnByte(int workonbit, unsigned char fallback, int operation);

/*! Holt sich die Eingabe vom Benutzer, was auf das Byte angewendet werden soll und gibt die Eingabe zurück (falls gueltig).
    /return Eingabe des Benutzers
*/
int getOperation();

//! Gibt das Auswahlmenü auf der Konsole aus.
void printMenu();

//! Gibt eine Zahl binär aus mit angegebener Breite.
//! /param value Auszugebender Binärwert.
//! /param width Breite des Binärwerts.
//! /param breakafter Fügt nach den hier angegebenen Werten einen Breakunsigned character, der mit breakunsigned character definiert wird ein. Bei diesem Wert > n wird kein Breakunsigned character eingefügt.
//! /param breackunsigned character z.B. Space: ' ' oder Linebreak '\n'
void printbinary(int value, int width, int breakafter, char breakcharacter);

//! Prüft ein Bit auf einen Wert und gibt das Ergebnis mit printf aus
//! /param workonbit Bit, auf dem gearbeitet werden soll
void cmd_checkbit(int workonbit, unsigned char workingbyte);

//! Negiert das angegebene bit auf der globalen Varia
//! /param workonbit Bit, auf dem gearbeitet werden soll
//! /param workingbyte Byte, auf dem die Bitoperation ausgeführt werden soll.
//! /return neuer Wert für das Byte;
unsigned char cmd_negateBit(int workonbit, unsigned char workingbyte);

//! Setzt ein Bit im workingbyte auf den angegebenen Wert
//! /param workonbit Bit, auf dem gearbeitet werden soll
//! /param workingbyte Byte, auf das die Operation angewendet werden soll
//! /param newvalue Neuer Wert, der gesetzt werden soll
//! /return Neuer Wert des gegebenen workingbyte
unsigned char setBit(int workonbit, unsigned char workingbyte, int newvalue);

//! Setzt ein Bit auf 1
//! /param workonbit Bit, auf dem gearbeitet werden soll
//! /param workingbyte Byte, auf das die Operation angewendet werden soll
unsigned char cmd_setBit(int workonbit, unsigned char workingbyte);

//! Setzt ein Bit auf 0
//! /param workonbit Bit, auf dem gearbeitet werden soll
//! /param workingbyte Byte, auf das die Operation angewendet werden soll
unsigned char cmd_resetBit(int workonbit, unsigned char workingbyte);
#endif