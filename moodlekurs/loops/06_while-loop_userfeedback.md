Neben der Stabilität eines Programms ist es auch wichtig, dass der Benutzer Hilfe und Rückmeldung bekommt, wenn eine Eingabe falsch getätigt wurde. Um dieses Feedback zur Verfügung zu stellen müssen mehrere Dinge geprüft werden.

1. Kann Die Eingabe generell eingelesen werden?
2. Hat der Benutzer nur korrekte Eingaben gemacht?

### Kann die Eingabe gelesen werden?

Um zu überprüfen, ob `scanf` in der Lage war die Benutzereingabe mit dem gegebenen *Formatstring* einzulesen, kann der Rückgabewert von `scanf` verwendet werden. Der Rückgabewert (auch *Returnwert* genannt) von `scanf` gibt Ihnen immer die Anzahl der korrekt eingelesenen Argumente.

Bei folgendem Code enthält die Variable `ok` den Wert 1, wenn der Benutzer eine Zahl eingegeben hat; andernfalls ist er `0`.

```c
int ok = scanf("%d", &input);
```

Gibt der Benutzer hier `52` ein, so steht in der Variablen `ok` eine 1. Gibt er `irgendwas` ein, so wird der Wert `0`.

Desto mehr Argumente im *Formatstring* stehen, desto größer wird auch der Rückgabewert. Im folgenden Beispiel werden drei Einzelziffern mit `%1d` eingelesen und in drei Variablen `ziffer1`, `ziffer2` und `ziffer3` abgespeichert.

```c
int ok = scanf("%1d%1d%1d", &ziffer1, &ziffer2, &ziffer3);
```

Gibt der Benutzer `123` ein, so wird die Variable `ok` auf `3` gesetzt. Gibt er `12a` ein, so wird `ok` auf 2 gesetzt, da `scanf` nur 2 Werte mit dem Formatstring einlesen konnte.

### Hat der Benutzer nur korrekte Eingaben gemacht?

`scanf` beginnt anhand der Formatstrings die Eingabe *zeichenweise* zu lesen. Das heißt

```c
int ok = scanf("%d", &input);
```

gibt eine `1` zurück, wenn der Benutzer `14Aepfel` eingibt, da es die Dezimalzahl `14` einlesen konnte. Wenn man nun verhindern möchte, dass der Benutzer etwas anderes eingibt als eine Zahl, ist es nötig auch noch das letzte Zeichen einzulesen. Dies sollte nur die `Return` Taste sein (also `\n`).

Dies kann man erreichen, indem man noch ein `%c` anhängt und prüft, ob es sich dabei um den character `\n` handelt:

```c
int input, ok;
char c;

ok = scanf("%d%c", &input, &c);
```

Hier wird nun die Variable `ok` immer `2`, wenn alles korrekt eingegeben wurde. Hat der Benutzer keine gültige Zahl eingegeben wird `ok` auf den Wert `0` gesetzt, da `scanf` schon beim Einlesen der Zahl scheitert. Wird `55d` eingegeben, so wird `ok` auch gleich `2`, aber in `c` steht nun `d` und nicht `\n`. `input` enthält hier den Wert `55`.