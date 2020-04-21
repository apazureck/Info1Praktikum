in der Regel wird die `for`-Schleife benutzt, um Zählervariablen hochzählen zu lassen. Wenn zum Beispiel eine Liste an gleichartigen Daten abgearbeitet wird, so bekommt jeder Listeneintrag eine Nummer und diese können mit einer `for`-Schleife und einem Zähler entsprechend abgearbeitet werden. Oder man nutzt nur einen Zähler. Daher auch, wie im ersten Teil erwähnt, der Name `for`:

> *Do something **for** n times*.

Dadurch sieht die übliche `for`-Schleife in der Regel so aus:

<script src="//onlinegdb.com/embed/js/HyJcP9sdU?theme=light"></script>

Diese Schleife gibt einfach die Zahlen von `0` - `9` aus (mit Komma getrennt).

### Mehrere Schleifenzähler

Die `for`-Schleife erlaubt es auch mehrere Schleifenzähler gleichzeitig zu nutzen. Die einzelnen Headerteile werden mit `;` getrennt. Wenn mehrere Anweisungen in der **Initialisierung** oder der **Reinitialisierung** erfolgen sollen, so muss werden diese mit `,` getrennt.

Im unteren Beispiel werden `i` und `j` gemeinsam in der **Initialisierung** gesetzt:

```c
i = 0, j = 10
```

Später in der **Reinitialisierung** werden diese dann auch beide verändert:

```c
i++, j--
```

Die Bedingung kann keine mehrere Zuweisungen pro Durchlauf haben, da diese immer nur ein logisches `wahr` oder `falsch` zurückgeben darf; entweder die Schleife läuft, oder sie läuft nicht.

Um die Teile noch einmal zu verdeutlichen hier der Schleifenkopf auf mehrere Zeilen aufgelöst[^1]:

```c
for(
    i = 0, j = 10; // Die Initalisierung
    i < j;         // Die Bedingung (hier gehen keine mehreren Anweisungen)
    i++, j--       // Die Reinitialisierung
    ) {
    ...            // Hier geht es weiter mit dem Schleifenkörper
```


Der Schleifenzähler `i` läuft dadurch von `0` bis zu `4`, da ihm `j` von `10` entgegenkommt. Beide Variablen werden in der **Reinitialisierung** verändert. `i` wird inkrementiert, `j` wird dekrementiert. Daher treffen sich beide beim Wert `5`. Dies bringt die Bedingung dazu logisch `falsch`, also gleich `0` zu werden, was die Schleife abbricht. Hier ist auch zu sehen, dass die Bedingung vor dem erneuten Durchlauf des Schleifenkörpers geprüft wird, denn sonst würde bei beiden die `5` ausgegeben.

<script src="//onlinegdb.com/embed/js/Hk7M_qid8?theme=light"></script>

[^1]: In der Praxis kann man eine `for`-Schleife auch wie oben genannt schreiben, wenn man viele Zähler initialisiert. Jedoch ist dies meist ein Anzeichen dafür, dass die `for`-Schleife fehl am Platz ist und besser eine andere Konstruktion verwendet werden sollte.