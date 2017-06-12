// Nachdem noch kein Array als Returnwert möglich werden hier globale Variablen benutzt.
int x, y, oldx, oldy;

/*--- Funktionsdefinitionen ------------------------------------------*/

//! Fragt den Benutzer nach dem Startpunkt und speichert die Koordinaten in den gobalen Variablen x und y
void getStartPoint();
//! Holt sich die neuen Koordinaten und speichert diese in den globalen Variablen x und y.
/*!
    ! /return false (1), wenn nur -1 eingegeben wurde (Beenden des Programms), andernfalls true (0)
*/
int getPoints();
//! Berechnet den Euklidschen Abstand zwischen zwei Punkten.
/*!
    /param x0 X-Wert der 1. Koordinate
    /param y0 Y-Wert der 1. Koordinate
    /param x1 X-Wert der 2. Koordinate
    /param x1 Y-Wert der 2. Koordinate
    /return Euklidschen Abstand
*/
double getEuclidDistance(int x0, int y0, int x1, int y1);