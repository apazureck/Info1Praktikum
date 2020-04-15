Die `switch`-`case`-Anweisung ist eine komplexere Struktur in C. Sie ist auch fester Bestandteil in allen viel genutzten Hochsprachen. Sie ist eien Art "Spezialform" der `if` - `else if` - `else` Anweisungen, bietet aber Vorteile:

1. Sie ist besser lesbar
2. Sie kann vom Compiler besser optimiert werden
3. Verschiedene `case`s können kombiniert werden

Eine `switch`-`case`-Anweisung beginnt immer mit dem `switch` Keyword. Darauf folgen runde Klammern mit der Variablen, die für die `case`s genutzt werden soll. Ein `case` beginnt immer mit dem `case` Keyword gefolgt von der Konstanten, für die der `case` gelten soll. Den Abschluss bildet ein `:`.

Jeder `case` wird mit einem `break;`, oder `return <return Wert>;`, oder `contintue;` beendet. Falls dies nicht gemacht wird läuft dieser `case` in den nächsten `case`.

```c
switch (/*Variable*/) {
    case /*Konstante 1*/:
        // Hier folgen Anweisungen für den case 1
    break;
    case /*Konstante 2*/:
        // Hier folgen Anweisungen für den case 2
    break;
    // ... Es können beliebig viele cases hinzugefügt werden.
    default:
        // hier erfolgen Anweisungen, wen der Wert der Variablen auf keinen der obigen cases passt
    break;
}
```

In dem folgenden Programm soll der Benutzer zwei Zahlen eingeben und diese addieren, subtrahieren, multiplizieren oder dividieren können.

Erste Lösung mit `if` - `else if` - `else` - Anweisung:

<script height="500px" src="//onlinegdb.com/embed/js/H1k8Qo7d8?theme=light"></script>

Dies lässt sich in eine `switch` - `case` - Anweisung übertragen:

<script height="500px" src="//onlinegdb.com/embed/js/BJ1pvjXd8?theme=light"></script>

Hier fällt zuerst auf, dass die Variable `option` nur einmal benutzt werden muss. Danach werden die `case`es nur noch über das `case` Keyword ausgewählt. Das `else` wird durch `default:` ersetzt. Die Funktion bleibt hier auch die gleiche.

Vergleichen wir dies einmal mit den oben getätigten aussagen:

#### 1. Der Code ist besser lesbar

Dies hat zuerst den Vorteil, dass weniger Code eingegeben werden muss. Es ist für jeden klar erkennbar, dass sich alle Vergleiche auf die Variable `option` beziehen und es ist auch später nicht möglich, dies einfach zu ändern.

#### 2. Der Compiler kann es besser optimieren

Bei wenigen `case`s wird der Compiler eine `if` - `else if` - `else` Kaskade vorziehen, da diese schneller abläuft. Bei mehreren `case`s wird der Compiler eine sogenannte "hashmap" anlegen. Somit springt er (mehr oder weniger) direkt in den gewünschten Fall. Das heißt jeder `case` ist in etwa gleich schnell erreichbar. Wenn der Compiler lange `else if` Ketten hat, muss er jeden Fall einzeln prüfen, was auch heißt, dass der letzte Fall als letztes geprüft werden wird.

#### 3. Man kann Fälle kombinieren

Dies folgt in einem späteren Teil der Lektion.