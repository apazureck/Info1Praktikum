Sie können jetzt beginnen ihr erstes Programm zu schreiben. Wenn Sie eine neue Programmiersprache lernen, ist das "Hello World" Beispiel immer ein guter Anfang. Dazu plotten wir einfach den Satz `Hello World` auf die Konsolenausgabe:

```c
#include <stdio.h>
#include <windows.h> // Diese Headerdatei ist nur in Windows nötig

int main() {
    printf("Hello World");
}
```

Diesen Quellcode müssen wir zunächst an den Compiler geben, der daraus ein lauffähiges Programm erstellt. Dazu bietet Ihnen Visual Studio Code die integrierte Konsole (oder Terminal). Falls ihr Terminal Fenster nicht offen ist, nutzen Sie einfach die Tastenkombination `STRG + Shift + ö`.

Jetzt geben Wir auf der Konsole

```ps
gcc main.c
```

ein. Dies sagt unserem compiler (gcc), dass wir die Datei main.c im aktuellen Ordner (Current Working Directory) compilieren möchten.

<img src="https://elearning.ohmportal.de/pluginfile.php/473834/mod_folder/content/0/compile_gcc.gif" height="400px"/>

Jetzt wurde eine Executable `a.exe` erstellt. Diese erscheint auch gleich im Datei Explorer (oben rechts). Wenn wir diese nun ausführen wollen, müssen wir im Terminal

```ps
./a.exe
```

eintippen. Das `./` am Anfang ist nötig, da Powershell sonst die Executable nicht findet. Es heißt soviel wie "Führe etwas im aktuellen Ordner aus".

![Execute first program](https://elearning.ohmportal.de/pluginfile.php/473834/mod_folder/content/0/run_first_program.gif)

Nun erscheint die Ausgabe `Hello World` auf der Konsole.