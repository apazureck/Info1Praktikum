Die simpelste Form einer Schleife ist die `while`-Schleife. Sie ist aus einem Schleifenkopf (Englisch *Header*) und einen Schleifenkörper (Englisch *Body*) aufgebaut.

Im Schleifenkopf steht die sogenannte Schleifenbedingung (Englisch *Condition*). Ist diese logisch `wahr`, bzw. `true`, so wird der Schleifenkörper ausgeführt. Ist sie logisch `falsch`, bzw. `false`, so wird der Schleifenkörper nicht mehr ausgeführt. Etwas ist in C immer `true`, wenn es `!= 0` ist!

<div class="mermaid">
graph LR
    A(Start) --> B
    B{Bedingung} -->|Nicht erfüllt| E(Weiterer Code....)
    B -->|Erfüllt| C(Schleifenkörper)
    C --> B
</div>

Im Schleifenkörper steht die gewünschte Anweisung, die ausgeführt werden soll, solange die Schleifenbedingung `true` ist. Wenn es nur eine Anweisung ist, so kann sie einfach (im Idealfall eingerückt in der nächsten Zeile) nach der geschlossenen Klammer des Schleifenkopfs stehen. Möchte man mehrere Anweisungen im Schleifenkörper ausführen, so kann man sie in einen Block (geschweifte Klammern schreiben);

```c
while (/* BEDINGUNG MUSS WAHR SEIN */)
    // Einzelne Anweisung

while (/* BEDINGUNG MUSS WAHR SEIN */) {
    // Anweisung 1
    // Anweisung 2
    // etc.
}
```

Im folgenden Beispiel ist ein einfacher Zähler realisiert. Dieser startet beim Wert der Variablen `i = 0` und zählt bis einschließlich `i = 10`. Danach ist `i` größer als 10 und die nächste Anweisung ausserhalb der Schleife wird ausgeführt. In diesem Fall `printf`.

<script height="500px" src="//onlinegdb.com/embed/js/r19nESs_I?theme=light"></script>

<script src="https://unpkg.com/mermaid@8.5.0/dist/mermaid.min.js">
</script>