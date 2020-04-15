Manchmal möchte man auch eine Verzweigung im Code haben, wenn die Bedingung der `if`-Anweisung nicht erfüllt ist. Daher kann man nach einem `if`-Block ein `else` anfügen. Dieses Keyword ist nur hier gültig. Wenn es ohne zugehöriges `if` angewendet wird, so kann der Compiler den Code nicht kompilieren und gibt eine entsprechende Fehlermeldung aus.

```c
if (/* BEDINGUNG */) {
    // Der if-Block Wird ausgeführt wenn Bedingung erfüllt ist
} else {
    // Der else-Block wird ausgeführt, wenn die Bedingung NICHT erfüllt ist
}
```

**Hier einige Beispiele**:

<script src="//onlinegdb.com/embed/js/SybrDhNf_I?theme=light"></script>