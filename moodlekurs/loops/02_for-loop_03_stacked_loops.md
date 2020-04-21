Schleifen lassen sich in C auch verschachteln. Das wird vor allem später bei mehrdimensionalen Arrays eingesetzt. Beim Verschachteln von Schleifen wird eine äussere Schleife aufgerufen, die - im Fall der `for`-Schleife - einen Zähler besitzt.). Danach wird die innere Schleife aufgerufen:

```c
// z seteht hier für Zähler
int zAussen, zInnen;
// A steht für aussen, I steht für innen
int endA, endI;

// Äussere Schleife
for(zAussen = 0; zAussen < endA; zAussen++) {
    // Äusserer Schleifencoden

    // Innerer Schleife
    for(zInnen = 0; zInnen < endA; zInnen++) {
        // Innerer Schleifencode
        // for ... Hier wäre wieder eine Verschachtelung möglich
    }
}
```

Dadurch kann man komplexere Datenstrukturen ausgeben, oder auch einfach Tabellen erzeugen, wie folgendes Beispiel zeigt. In diesem wird eine einfache Tabelle ausgegeben. Die äussere `for`-Schleife kümmert sich um die Zeilen, die innere `for`-Schleife kümmert sich um die Spalten.

<script height="500px" src="//onlinegdb.com/embed/js/rkya_f3uL?theme=light"></script>