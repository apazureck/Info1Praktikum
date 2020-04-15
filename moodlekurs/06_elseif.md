Es ist auch möglich `if`-Anweisungen zu verschachteln, um somit komplexe Entscheidungsbäume zu erzeugen. Dies wird jedoch sehr schnell unübersichtlich, wie im folgenden Beispiel zu sehen ist.

<script height="500px" src="//onlinegdb.com/embed/js/ryQbZIMOU?theme=light"></script>

Um diese Verschachtelung besser lesbar zu machen, kann `else` und `if` zu `else if` kombiniert werden. Jedes `else if` hat eine eigene Bedingung. Die `else if` Kaskade kann mit einem `else` abgeschlossen werden.

```c
if(/* Erste Bedingung */) {
    // Die Erste Bedingung wird geprüft, wenn dies nicht true wird...
} else if (/* Zweite Bedingung */) {
    // wird die zweite Bedingung geprüft, wenn sie nicht erfüllt wird...
} else if (/* Dritte Bedingung */) {
    // wird die dritte Bedingung geprüft, wenn diese nicht erfüllt wird...
}
// Dies kann beliebig oft wiederholt werden
else {
    // Zuletzt kann eine else Bedingung angegeben werden, 
    // die ausgeführt wird, wenn alle anderen Bedingungen 
    // nicht erfüllt werden
}
```

Dies macht das obige Beispiel besser lesbar, da die Verschachtelung der `else`-Teile nun nicht mehr vorhanden ist. Die Verschachtelung verschwindet nun, die Funktion des Codes hingegen hat sich nicht geändert.

<script height="500px" src="//onlinegdb.com/embed/js/SJEwNUzO8?theme=light"></script>