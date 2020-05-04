In C und auch in anderen mordernen Hochsprachen gibt es die Möglichkeit, die Schleife wärend der Ausführung des Schleifenkörpers abzubrechen. Dies kann man mit dem Keyword `break` erreichen.

```c
while(/* Bedingung */) {
    // Ihr code
    if (/* Abbruchbedingung */)
        break;
    // Wird nicht mehr ausgeführt, wenn die Abbruchbedingung erfüllt ist.
}
```

Sobald die Abbruchbedingung erfüllt ist, wird mit `break` die Schleife verlassen. Der Code, der folgt wird nicht mehr ausgeführt. Folgendes Ablaufdiagramm verdeutlicht den Ablauf:

<div class="mermaid">
graph TD

before[Code davor] --> whileHEAD[/Schleifenbedingung\]
whileHEAD --> whileCodeBefore[Code]
whileCodeBefore --> if{Abbrechen}
if -->|ja| break
break --> goOn
if -->|nein| codeAfter[Code danach]
codeAfter --> whileFOOT
whileFOOT[\ ....................... /] --> goOn[Weiterer Code]
</div>

<script src="https://unpkg.com/mermaid@8.5.0/dist/mermaid.min.js">
</script>