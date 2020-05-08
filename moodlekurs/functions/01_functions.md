Um komplexere Programme in C zu schreiben, benötigt es weitere Strukturelemente. Dazu werden in C sogenannte Funktionen verwendet. Diese leiten sich von den mathematischen Funktionen her. Dort werden sie meistens mit $$f(x) = 2*x^2$$, oder ähnlichen Bezeichnungen verwendet. Komplexere mathematische Funktionen können auch mehrere Parameter enthalten:

$$f(x, t) = 2 * x + t$$

In C wird genau dieses Prinzip verwendet. Da es in C oft viele Funktionen gibt, kann man diesen auch komplexere Namen geben. Ein einfaches Beispiel ist Folgendes:

<script height="500px" src="//onlinegdb.com/embed/js/ryHGFgAKU?theme=light"></script>

Diese Funktion macht nichts anderes als `Hello my old friend!` auf der Konsole auszugeben, sobald sie aufgerufen wird. Sie lässt sich beliebig oft aufrufen und wird dabei immer den gleichen Text ausgeben. Jedoch muss hier nicht jedesmal `printf` aufgerufen werden.

### Deklaration einer Funktion

Bevor eine Funktion benutzt werden kann, muss diese immer erst deklariert und implementiert werden. Eine Deklaration muss immer ausserhalb einer anderen Funktion passieren. Deklaration des Funktionskopfes sieht bei der `printWelcome` Funktion so aus:

```c
void printWelcome()
```

Zuerst komm der Datentyp, in diesem Fall kein Datentyp, daher `void`. Danach der Funktionsname, in diesem Fall `printWelcome`. Für Funktionsnamen gelten die gleichen Regeln, wie bei Variablennamen. Die zwei runden Kalmmern dahinter `()` (ohne Leerzeichen) sagen dem Compiler, das es sich hier um eine Funktion handelt.

### Implementierung einer Funktion

In den geschweiften Klammern folgt dann der Programmcode, der jedes Mal ausgeführt wird, wenn die Funktion aufegrufen wird. Hier kann wieder beliebiger C Code stehen. Auch die `main` Funktion ist so eine Funktion. Alles, das dort geht, geht auch in allen anderen Funktionen.

### Aufrufen einer Funktion

Um den in einer Funktion geschriebenen Programmcode aufzurufen, muss man nur den Funktionsnamen mitsamt den Klammern schreiben und danach den Anweisungsterminator setzen:

```c
printWelcome();
```

### Getrennte Deklaration und Implementierung

Es gibt die Möglichkeit eine Funktion zu deklarieren, ohne sie zu implementieren. Dazu kann man einfach nur den Methodenkopf *deklarieren*, ohne die geschweiften Klammern danach zu schreiben. Dafür muss man die Deklaration mit einem Anweisungsterminator beenden. Nun kann an einer anderen Stelle im C Programm die Implementierung stattfinden, wie oben erklärt.

```c
void printWelcome();
```

Die Deklaration und Implementierung zu trennen hat mehrere Vorteile.

#### 1. Kompilierbarkeit von Code

Ältere - oder auch einige spezialisierte - Compiler kompilieren das Programm von oben nach unten. Wenn sie über einen Funktionsaufruf im Programm stolpern und dazu noch keine Funktion kennen, brechen sie den Compilevorgang ab. Das machen sie, da sie an der Stelle nicht wissen, welche Returndatentypen oder Parameterdatentypen die Funktion hat und ob sie ggf. einen Typecast einbauen müssen. Auf Returndatentypen und Parameter wird später in dieser Lektion noch genauer eingegangen.

Dies führt dazu, dass z.B. folgender Code für den Compiler nicht kompilierbar ist:
  
```c
void a() {
    b();
}
void b() {
    a();
}
```

Da hier die Funktion `a` die Funktion `b` aufruft, aber auch `b`, `a`, kennt derCompiler immer zwangsweise eine Funktion nicht. Um dies aufzulösen, muss man dieFunktionen separat *deklarieren*:

```c
void a();
void b();

void a() {
    b();
}

void b() {
    a();
}
```

Nun kann wirklich jeder Compiler den Code kompilieren, da der Compiler dieStrukturen der Funktionen kennt.

#### 2. Trennen von Code

Wenn man eigene Funktionen schreibt, möchte man diese später ggf. in eine eigene Funktionsbiliothek auslagern, welche auch andere Programmierer benutzen können. Damit ein anderer Programmierer auch ohne den Quellcode in der C Datei diese Funktionen benutzen kann, kann man diese in eine *Headerdatei* auslagern. Somit weiß der Compiler, ohne den Quellcode zu kennen, wie der eigene Code aussehen muss, damit die Funktionen aus der benutzten Bibliothek aufgerufen werden kann. Später setzt der sogenannte Linker die konkreten Speicheraddressen des Programmcodes der anderen Bibliothek, damit der schon kompilierte Code ausgeführt wird.

Dies hat wiederum auch Vorteile:

1. **Man kann größere Projekte schneller bauen**, da nicht jedes mal der ganze Code gebaut werden muss, sondern nur der eigene Teil, an dem man programmiert.
2. **Andere bekommen den Quellcode nicht**. Vor allem in Firmen möchte man ungern den eigenen Quellcode jedem offenlegen. Code kann sehr schnell kopiert werden und somit könnte jeder sehr einfach den eigenen Code in andere Anwendungen integrieren.

Ein Beispiel sind hier die C Standardfunktionen. In den vorangegangenen Projekten wurde immer die Bibliothek *Standard Input and Output* mit der Headerdatei `stdio.h` genutzt. Der entsprechende Code für `printf`, `scanf` und Co. wird dabei nicht jedes mal gebaut, sondern der schon gebaute Code aus der Standardbibliothek wird in das eigene Programm integriert.

Dies nennt man auch Modularisierung. Da man eigenen Code aus eigenen Modulen zusammenbauen kann. Jedes Programm enthält dabei aber auch nur die Module, die es wirklich braucht und nicht immer alle unnötigen Module. Dies ist heute etwas weniger relevant, als zu den Anfangszeiten des Informationszeitalters. Damals war Speicher eine knappe Ressource. Jedoch gewinnt das Thema auch heute wieder an Relevanz, da durch Cloud Computing viele kleine Mehrverbräuche in Summe wiederum großen Einfluss haben.

Berücksichtigt man nun die oben genannten Aspekte, so kann man den eingangs gezeigten Code folgendermaßen umstrukturieren:

[Projekt auf onlinegdb.com](https://onlinegdb.com/HJgiiuH7cL)

Lokal sieht die Sache etwas komplizierter aus. Man muss dem Compiler alle Quelldateien, also `main.c` und `welcome.c` übergeben:

```shell
gcc main.c welcome.c -o myProgram.exe
```

Onlingdb kümmert sich automatisch um die Referenzen. Bei eigenen Projekten mit vielen C Dateien kann dies schnell ausufern, da man hier jede im Projekt verwendete Datei beim Compiler angeben muss. Daher gibt es hierfür auch sogenannte *Makefiles*, die dies automatisieren. *Dies ist aber nicht Bestandteil dieses Kurses*. [Zum Ausprobieren gibt es auf github noch einmal das hier verwendete Beispielprojekt]().

Aber um den Code für andere Compiler Kompilierbar zu machen, sollte bei den Übungen folgendes Layout verwendet werden:

```c
#inlcude <stdio.h>

// Deklarationen hier angeben:
void printWelcome();

int main() {
    printWelcome();
    return 0;
}

void printWelcome() {
    printf("Hello my old friend!");
}
```

## Frage 1

Was gibt folgender Code aus?

```c
void hello() {
    printf("Hello");
}

void world() {
    printf("World");
}

int main() {
    hello();
    hello();
    world();
    world();
}
```