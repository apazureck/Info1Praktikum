<script src="https://unpkg.com/mermaid@8.5.0/dist/mermaid.min.js">
</script>

Ein Schleifentyp ist die `for`-Schleife (Englisch: `for`-loop). Sie ist eine Spezialform der `while`-Schleife. Sie lässt sich sprachlich aus dem Englischen herleiten: *'Do something `for` n times'*

Die `for`-Schleife hat immer einen Schleifenkopf (Englisch *Header*) und einen Schleifenkörper (Englisch *Body*). Die `for`-Schleife wird immer mit dem Keyword `for` eingeleitet. Danach folgt in runden Klammern der *Header*. Der Body kann bei mehreren Anweisungen in eimem Block stehen (geschweifte Klammer), bei einer einzelnen Anweisung kann diese aber auch ohne Block geschrieben werden; dies ist analog zu `if`.

```c
for (/* Schleifenkopf */) {
    // Schleifenkörper
}

for (*/ Schleifenkopf */)
    /* Schleifenkörper mit nur einer Anweisung */;
```

Bei einer `for`-Schleife ist der *Header* komplexer aufgebaut, als beispielsweise bei der `while`-Schleife. Der Kopf der `for`-Schleife enthält drei Sektionen, die jeweils mit `;` (Semikolon) getrennt werden:

```c
for(/* Initialisierung */; /* Bedingung */; /* Reinitialisierung */) {
    // Der Schleifenkörper
}
```

1. Die **Initialisierung** wird zu Beginn der Schleife ein mal ausgeführt. Sie initialisiert in der Regel ein Zählervariable
2. Die **Bedingung** wird jedes mal ausgeführt **bevor** der Schleifenkörper ausgeführt wird.
3. Die **Reinitialisierung** wird jedes mal ausgeführt **nachdem** der Schleifenkörper ausgeführt wurde.

Somit ergibt sich folgender Ablauf:

<div class="mermaid">
graph LR
    A(Initialisierung) --> B{Bedingung}
    B -->|Nicht erfüllt| E(Weiterer Code....)
    B -->|Erfüllt| C(Schleifenkörper)
    C --> D(Reinitialisierung)
    D --> B
</div>