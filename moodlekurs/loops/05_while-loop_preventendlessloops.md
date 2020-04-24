`while`-Schleifen weisen auch eine Ähnlichkeit zur `if`-Struktur auf. Sie prüfen, ob eine Bedingung erfüllt ist und führen dann den Körper aus. Ein `if` nur einmal, eine `while`-Schleife so lange, bis die Bedingung nicht mehr erfüllt ist.

Dies lässt sich für die Überprüfung der Korrektheit der Benutzereingaben verwenden. Solange die Benutzereingabe nicht im gewünschten Bereich ist, wird der Benutzer aufgefordert sie zu wiederholen:

<script height="500px" src="//onlinegdb.com/embed/js/BJKFwE0dI?theme=light"></script>

## Endlosschleifen verhindern

Gibt der Benutzer in diesem Beispiel jedoch keine Zahl ein, sondern einen ASCii Character, so wird die Schleife nicht mehr beendet (ausser der Wert ASCII Characters liegt zufällig im Bereich 5 - 10).

Gibt der Benutzer `a` ein und bestätigt mit Return ( = `"\n"`, wird diese Schleife endlos ausgeführt. Das kommt daher, dass `scanf` den Wert nicht einlesen kann, da es keine Zahl ist, sondern ein Buchstabe und somit nicht in das Muster passt. So wird der Eingangspuffer nicht geleert. In diesem steht immer noch

```c
"a\n"
```

`scanf` liest danach wieder den Eingangspuffer, kann es immer noch nicht interpretieren und der Benutzer hat auch keine Möglichkeit mehr den Wert zu überschreiben. Daher wird die ganze Zeit der Aufforderungstext auf die Konsole geschrieben, bis der Benutzer sie, zum Beispiel durch Beenden der Konsole, beendet.

Um dies zu verhindern, muss der Eingangsbuffer gelöscht werden, nachdem die Eingabe getätigt wurde. Hier kann wieder von einer `while`-Schleife gebrauch gemacht werden.

```c
while ((c = getchar()) != '\n' && c != EOF) { }
```

Diese `while`-Schleife liest solange characters mit `getchar()` vom Eingangspuffer, bis das Eingegebene `\n` gefunden wurde. Wird kein `\n` gefunden bricht die `while`-Schleife ab, sobald keine Werte mehr im Buffer sind. Dies wird mit der in der `stdio.h` definierten Konstanten `EOF` geprüft. `EOF` ist eine `int` Konstante mit dem Wert `-1`:

```c
#define EOF (-1)
```

Wird diese Schleife vor dem Einlesen von neuen Werten ausgeführt, so kann sichergestellt werden, dass der Eingabepuffer immer leer ist, bevor etwas neues eingelesen wird. Nachfolgendes Beispiel zeigt diese Änderung. Nun wird die Endlosschleife zuverlässig verhindert.

<script height="500px" src="//onlinegdb.com/embed/js/S1rvqB0dU?theme=light"></script>

Nun ist der Code tolerant gegenüber falschen Benutzereingaben und führt nicht mehr zu einem Absturz des Programms.