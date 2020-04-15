Mit `scanf` lassen sich auch komplexere Formatstrings einlesen, als einzelne Werte. Dies wird vor allem später wichtig, wenn Sie Benutzereingaben auf deren Korrektheit überprüfen müssen. Wie auch bei `printf` lassen sich auf einen Schlag mehrere Eingaben einlesen.

Zum Beispiel kann man Koordinateneingaben des Benutzers einlesen:

<script src="//onlinegdb.com/embed/js/r1M-WT1O8?theme=dark"></script>

Hier wird der Benutzer aufgefordert, seine Koordinaten im Format `x, y` einzugeben. Wenn der Benutzer korrekte eingaben macht, erfolgt auch eine korrekte Ausgabe. X wird der variablen `x` zugeordnet, Y der Variablen `y`.

Eingaben wie

```shell
1, 2
-2, 3
-2, -2
```

erzeugen korrekte Ausgaben:

```shell
Sie haben die Koordinate X: 1, Y: 2 eingegeben!
Sie haben die Koordinate X: -2, Y: 3 eingegeben!
Sie haben die Koordinate X: -2, Y: -2 eingegeben!
```

Beachtet der Benutzer jedoch das gewünschte Format nicht, so ergeben sich falsche Ausgaben:

```shell
1 2
```

Hier hat der Benutzer das Komma vergessen. Es ergibt folgende Ausgabe (*bei onlinegdb!*):

```shell
Sie haben die Koordinate X: 1, Y: 0 eingegeben!
```

> Der online Compiler gibt hier immer eine 0 aus, jedoch kann das auf der entsprechenden Maschine irgendein Wert sein, der bei der Deklaration der Variablen im Speicher stand.

### Überprüfen der korrekten Benutzereingaben

Funktionen in C können nicht nur Werte als Übergabeparameter erhalten, sondern auch einen sogenannten **return Wert** zurückgeben. Dieser ist bei `scanf` die Anzahl der korrekt eingelesenen Variablen.

Schreiben wir also den obigen Code um:

<script src="//onlinegdb.com/embed/js/HkNnX6kO8?theme=light"></script>

Jetzt erhalten wir zusätzliche Informationen, wie viele Werte mit dem gegebenen Formatstring korrekt eingelesen werden konnten. Die Anzahl der korrekt eingelesenen Werte wird in der Variablen `successfullyRead` abgelegt. Bei den Korrekten Eingaben beträgt dieser Wert `2`. Bei der falschen Eingabe nur `1`.

> Für die ersten Aufgaben ist es ausreichend die Benutzereingaben einfach einzulesen. Später im Praktikum wird es erforderlich die Eingaben des Benutzers auf Richtigkeit zu überprüfen.

Welche Ausgabe erzeugt folgender Code?

```c
double longitude, latitude;
int sucessfullyRead;

printf("Geben Sie ihre aktuelle Position ein: ");
successfullyRead = scanf("%f, %f", &longitude, &latitude);

printf("%d korrekte Eingaben: Ihre aktuelle Koordinate ist: %f, %f", successfullyRead, latitude, longitude);
```

Eingabe des Benutzers:

```shell
49.453194, 11.097812
```