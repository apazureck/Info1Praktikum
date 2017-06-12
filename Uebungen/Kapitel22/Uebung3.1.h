#ifndef UEBUNG3_1_H
#define UEBUNG3_1_H

// Globale Variablen in Ermangelung an Rueckgabeparameter
int h1, m1, s1, h2, m2, s2;

//! Holt sich die Zeitwerte mit Scanf und legt sie auf h1, m1 und s1
void getTime1();
//! Holt sich die Zeitwerte mit Scanf und legt sie auf h2, m2 und s2
void getTime2();
//! Addiert 2 Zeitwerte und gibt das Ergebnis aus
//! /param h1 Stunde des ersten Zeitwerts
//! /param m1 Minuten des ersten Zeitwerts
//! /param s1 Sekunden des ersten Zeitwerts
//! /param h2 Stunde des zweiten Zeitwerts
//! /param m2 Minuten des zweiten Zeitwerts
//! /param s2 Sekunden des zweiten Zeitwerts
void addTime(int h1, int m1, int s1, int h2, int m2, int s2);
//! Subtrahiert 2 Zeitwerte und gibt das Ergebnis aus
//! /param h1 Stunde des ersten Zeitwerts
//! /param m1 Minuten des ersten Zeitwerts
//! /param s1 Sekunden des ersten Zeitwerts
//! /param h2 Stunde des zweiten Zeitwerts
//! /param m2 Minuten des zweiten Zeitwerts
//! /param s2 Sekunden des zweiten Zeitwerts
void subtractTime(int h1, int m1, int s1, int h2, int m2, int s2);

//! holt sich vom Benutzer, ob er addieren oder subtrahieren soll.
//! /return eingebenes Command, falls gueltig.
char getCommand();

#endif