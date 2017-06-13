#ifndef UEBUNG1_1_H
#define UEBUNG1_1_H

//! Findet die nächste Primzahl, die nicht abgehakt ist.
//! /param *crossed ausgestrichene Zahlen sind hier mit 0 belegt.
//! /param start Startindex, ab dem die neue Primzahl gesucht werden soll.
//! /param length Länge der arrays
//! /return Index der nächsten Primzahl
int getNextPrimeNumber(int crossed[], int start, int length);

#endif