#ifndef UEBUNG3_2_H
#define UEBUNG3_2_H

//! Liest so lange mit scanf ein, bis die Eingabe korrekt ist.
//! /return Korrekte Eingabe
int readNumber();

//! Sortiert die gegebenen Zahlen
//! /param n1 Erste Zahl
//! /param n2 Zweite Zahl
//! /param n3 Dritte Zahl
//! /param n4 Vierte Zahl
//! /return Anzahl gebrauchter verschiebungen
int sortNumbers(int n1, int n2, int n3, int n4);

//! Gibt die vier Zahlen aus.
//! /param n1 Erste Zahl
//! /param n2 Zweite Zahl
//! /param n3 Dritte Zahl
//! /param n4 Vierte Zahl
//! /param count Loopcounter
void printNumbers(int n1, int n2, int n3, int n4, int count);

#endif