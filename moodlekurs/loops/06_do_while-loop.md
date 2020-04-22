Die `while`-Schleife, wie auch die `for`-Schleife, prüfen *vor* jeder Ausführung die Schleifenbedingung. Daher nennt man sie auch *kopfgesteuert*.

Dieses Verhalten kann auch umgekehrt werden, sodass die `while`-Schleife erst nach dem Durchlauf des Schleifenkörpers die Bedingung prüft. Dafür wird zuerst das Keyword `do` verwendet, gefolgt von dem Schleifenkörper. Danach folgt das `while` Keyword mit der Schleifenbedingung:

```c
do {
    // Schleifenkörper
} while (/* Bedingung */);
```

Die Bedingung wird abschließend mit einem `;` (Strichpunkt) beendet. Dies führt letztendlich dazu, dass der Schleifenkörper auf jeden Fall einmal durchlaufen wird, bevor die Bedingung geprüft wird. Daher nennt man diese Schleife auch fußgesteuert.

<div class="mermaid">
graph LR
    A(Start) --> C
    B{Bedingung} -->|Nicht erfüllt| E(Weiterer Code....)
    B -->|Erfüllt| C(Schleifenkörper)
    C --> B
</div>

Im folgenden Beispiel können Sie einen Wert kleiner 5 eingeben und sehen dabei, dass die Schleife immer einmals ausgeführt wird:

<script height="500px" src="//onlinegdb.com/embed/js/HJzF-ERuL?theme=light"></script>

<script src="https://unpkg.com/mermaid@8.5.0/dist/mermaid.min.js">
</script>