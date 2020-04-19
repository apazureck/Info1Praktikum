Sie können in Visual Studio Code auch direkt im Editor debuggen. Dazu müssen Sie zuerst einen Breakpoint in die gewünschte Zeile setzen, links neben die Zeilennummer.

Wenn Sie danach ihr Programm mit `F5` starten, sollte, nachdem es gebaut und gestartet ist, in der Zeile stehen bleiben.

Links im Debug Fenster gibt es das sogenannte `Watch` Tab. Dort können Sie Variablen und ganze Ausdrücke sofort auswerten lassen. Alternativ dazu können Sie unten in der Debug Konsole die gleichen Aktionen durchführen. Zusätzlich können Sie auch Extra Funktionen von `GDB` (Das Debugger Programm) nutzen.

Zum Beispiel können Sie das Bitmuster einer Variablen ausgeben lassen. Dazu müssen Sie zuerst VSCode mitteilen, dass Sie `GDB` ausführen möchten. Dies tun sie mit `--exec` gefolgt von einem Leerzeichen und dann der Befehl, den Sie ausführen möchten.

Zum Beispiel:

```shell
--exec print /t 42
```

gibt das Bitmuster der Konstanten `42` aus.

![Debugging VSCode](https://raw.githubusercontent.com/apazureck/Info1Praktikum/master/moodlekurs/vscode/debugging_vscode.gif)