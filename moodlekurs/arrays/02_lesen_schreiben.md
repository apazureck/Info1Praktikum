Ist ein Array deklariert, so verhält es sich mit den Werten im Array genauso, wie auch mit den Werten von Variablen. Es wird das letzte Bitmuster in dem Datentypen interpretiert, welchen die Variable hat.

Daher muss man die Werte in einem Array erst zuweisen, sprich intialisieren. Um einen einzelnen Wert in einem Array zuzuweisen, schreibt man den Arraynamen und danach in eckigen Klammern den Index des zu setzenden Eintrags. Danach kann mit einem Zuweisungsoperator `=` der Wert an dem Index des Arrays gesetzt werden.

```c
float array[6];
array[0] = 1.f;
```

Hier gilt zu beachten, dass die Arrayeinträge - wie auch in dem Speicherausschnitt oben zu sehen - über einen sogenannten Index angesprochen werden. Dieser Index beginnt immer mit einer 0. Das `erste` Element in einem Array hat somit den Index `0`, das `zweite` den Index `1`, das `dritte` den Index `2`, usw.