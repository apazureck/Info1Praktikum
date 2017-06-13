#ifndef UEBUNG1_1_H
#define UEBUNG1_1_H

#define MAX_NUMBERS 100

//! Erfragt vom Benutzer, wie viele Zahlen er maximal haben möchte, dabei wird ein Maximalwert von der symbolischen Konstante MAX_NUMBERS berücksichtigt.
//! /returns Benutzereingabe maximale Anzahl von Nummern
int getNumbers();

//! Erfragt vom Benutzer, wie viele er aus den in max gegebenen Zahlen ziehen möchte.
//! /param max Maximale Anzahl an Nummern, die gezogen werden können
//! /return Anzahl an zu ziehenden Nummern
int getDraws(int max);

//! Gibt das Array mit den gezogenen Zahlen aus
//! /param count Anzahl der zu ziehenden Zahlen
//! /param all Anzahl aller Zahlen aus denen gezogen werden kann.
void printDrawnNumbers(int count, int all);

//! Bubblesort Algorithmus von Wikipedia
//! *array Array, das sortier werden soll
//! length Länge des Arrays
void bubblesort(int *array, int length);
#endif