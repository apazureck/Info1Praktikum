`printf` ermöglicht es dem Programmierer Variablen und Konstanten auf der Konsole in einer gewünschten Darstellung auszugeben. Es ist auch möglich, Eingaben des Benutzers formatiert einzulesen. Dabei wird die Funktion `scanf` verwendet.

`scanf` ist, wie auch `printf`, in der Datei `stdio.h` definiert. Wird diese Datei in ein C-Programm mittels der `#include` Compiler-Direktive included, so ist diese Funktion verfügbar. Die Anwendung ist größtenteils analog zu der von `printf`:

```c
scanf("formatstring", /*variable1*/, /*variable2*/, /*...*/);
```

Bei `scanf` funktionieren die meisten Bezeichner, die auch bei `printf` anwendbar sind. Dies vereinfacht die Arbeit mit Eingaben, da die eingegebenen Werte gleich in die entsprechend typisierten Variablen abgespeichert werden können. Daher muss man nicht manuell die eingegebenen Zeichenketten abarbeiten und die Werte "per Hand" formatieren.

`scanf` wartet dabei auf die Eingabe des Benutzers so lange, bis der Benutzer die **Return** Taste beätigt. Ein einfaches Beispiel dazu:

<script src="//onlinegdb.com/embed/js/BJzU53yO8?theme=light"></script>

### Einlesen von Benutzereingaben

Dabei muss man wissen, wie Konsolenprogramme, bzw. wie die Konsole - auch *shell* genannt - funktionieren. Die Konsole besitzt drei Buffer:

1. `stdin` ist der Eingangsbuffer. Hier werden Eingaben von der Konsole, bzw. von dem Benutzer eingelesen. 
2. `stdout` ist der Ausgangsbuffer. Hier werden Ausgaben abgelegt, die später auf der Konsole erscheinen sollen. Dies kann mit `printf` erfolgen. <font color="gray">*Es gibt auch andere Möglichkeiten, die gewünschten Werte dort "hineinzustreamen", die jedoch hier nicht behandelt werden.*</font>
3. `stderr` ist der Buffer für Fehlerausgaben. Wenn auf diesen Buffer geschrieben wird, weiß die Konsolenanwendung / das Betriebssystem, dass etwas schief gegangen ist.

Wenn ein Benutzer etwas eingibt, landet es erst einmal "*in der Konsole*". Sobald der Benutzer die **Return** Taste betätigt, wird die Eingabe (eine Zeichenfolge) im `stdin` Buffer abgelegt. Sobald das passiert und `scanf` auf eine Eingabe wartet, wird es aktiv. Es sieht sich die Daten im Eingangsbuffer `stdin` an und versucht, den angegebenen `formatstring` darauf anzuwenden. Ist es erfolgreich - das heißt kann es alle gewünschten Formate einlesen - so läuft das Programm weiter. Ist es nicht erfolgreich, so wartet es auf weitere Benutzereingaben, bis der Formatstring erfüllt ist.

### Speichern der Eingaben in Variablen

Im obigen Codeschnipsel ist zu sehen, dass man `scanf` nicht einfach die Variable übergibt, in die man etwas abspeichern möchte. Man muss ein `&` vor dem Variablennamen setzen. Das hat etwas mit einem grundlegenden Prinzip von C zu tun, das sich "call by value" nennt. Das heißt, dass Funktionen, wie zum Beispiel `scanf`, oder auch `printf` **NUR WERTE ÜBERGEBEN WERDEN KÖNNEN**:

```c
int i = 25;
printf("%d", i);
```

In diesem Beispiel wird nicht der Speicherort / die Speicheraddresse der Variablen `i` übergeben, sondern einfach der Wert. Wenn das Programm läuft, ruft es also eigentlich

```c
printf("%d", 25);
```

auf.

Bei `printf` erfordert es daher keinen weiteren Denkaufwand, da dies das Standardverhalten von C ist. Wir teilen `printf` mit:

> Gib mir den Wert 25 auf der Konsole als Dezimalwert aus!

Bei `scanf` ist die Sache daher etwas komplizierter. Da man Funktionen nur Werte übergeben kann, muss `scanf` mitgeteilt werden, an welche **SPEICHERADDRESSE** es den Wert ablegen möchte, damit man den Wert später im Programm nutzen kann. Diese Speicheraddresse hat bei uns den Namen `i`. Der Computer sieht hier nur eine wirkliche Speicheraddresse. Das heißt, wenn man einen Wert in der Variablen `i` ablegen möchte, muss das Programm `scanf` den Wert der Speicheraddresse übergeben. Wir sagen `scanf` also:

> Lies einen Dezimalwert vom Benutzer ein und lege ihn mir in der Speicheradresse meiner Variablen `i` ab!

Vergisst man das `&` vor der Variablen, so wird `scanf` versuchen den eingelesenen Wert in der Variablen mit der Speicheradresse `25` abzulegen. Diese ist in jedem Fall durch das Betriebssystem belegt. Dieses verhindert auch, dass etwas geschrieben werden kann, was nicht im Hoheitsgebiet des Programms liegt. Daher wird es das Programm einfach von aussen mit einem Fehler beenden.