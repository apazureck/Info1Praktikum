Ein weiterer Aspekt von `switch` - `case` ist, dass man von einem `case` in den anderen kommen kann. Dies wird erreicht, indem man keinen `break;` am Ende des `case`s angibt:

```c
switch(variable) {
    case 'a':
    case 'A':
        // Beide cases landen in diesem Codeblock
        break;
    case /*xy*/:
        // anderer case
        break;
    default:
        // default case
        break;
}
```

Somit erreicht man, dass die `case`s `'a'` und `'A'` im gleichen Codeteil landen werden. Dies hat wiederum den Vorteil, dass man diesen Teil leicht erweitern kann und nur einmal angeben muss.

Bezogen auf unser voriges Beispiel, kann man den Nutzer nun ermöglichen nicht nur `+`, `-`, `*` und `/` einzugeben, sondern er könnte auch `a`, `s`, `m` und `d` eingeben:

<script src="//onlinegdb.com/embed/js/HknhZnXOL?theme=light"></script>

Was bekommt der Benutzer bei der Eingabe `c` ausgegeben?

```c
int input = 0;

printf("Geben Sie einen Buchstaben ein: ");
scanf("%c", &input);

switch(input) {
    case 'A':
    case 'd':
    case 'e':
        printf("Das kann ja jeder!");
        break;
    case 'b':
    case 'F':
    case 'd':
        printf("Das kann ich auch!");
        break;
    default:
        printf("Das kann keiner!");
}
```