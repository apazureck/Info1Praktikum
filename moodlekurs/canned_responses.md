## Dateiheader
Bitte keine Dateiheader verwenden. Das macht heutzutage git oder svn. Das stiftet mehr Verwirrung, als dass es hilft, macht Dateien unnötig groß und unübersichtlich und ist sehr fehleranfällig.

## Unbenutzte Includes
Bitte achten Sie darauf, dass Sie keine unnötigen Includes machen. Das kann u.u. Performance beim Bauen kosten und macht ggf. unnötige Abhängigkeiten zu Dingen, die Sie gar nicht verwenden.

## Source Code Formatter
Bitte verwenden Sie einen Source Code Formatter. Formatieren Sie Code nicht mit der Hand. Source Code Formatter können Ihnen dabei helfen auch im Team eine einheitliche Struktur zu erhalten. In VSCode einfach mit Alt+Shift+f und in CodeBlocks rechtsclicken und dann mit AStyle formattieren.

## Ausdruecke als Funktionsargument
Ausdrücke direkt als Funktionsargument sind kein guter Stil. Das macht Code unübersichtlich und schwerer lesbar.

## AUsdruck als Konstanten
Bitte schreiben Sie den Ausdruck als Konstante. Ihr Compiler kann sonst u.u. nicht optimieren. Wenn Sie einen konstanten Ausdruck schreiben, z.B 3/4f, wenn Sie dreiviertel ausdrücken wollen, dann ist das absolut OK. Ihr Compiler macht dann einfach eine Konstante mit der maximalen Genauigkeit. Wenn Sie das über Funktionen / Variablen machen, dann kann der Compiler ggf. nicht optimieren, weil er nicht einschätzen kann, ob sich die Werte zur Laufzeit ändern. Bei Konstanten weiß er Bescheid.

# int main void
Kein int main(void) machen. Das ist unüblich. int main() ist ausreichend.

## Unnötige KOmmentare
Vermeiden Sie unnötige Kommentare. Der code sollte im besten Fall selbsterklärend sein. Besser sind sprechende Funktions- und Variablennamen. Also bei dem Ausdruck "x = 3.14;" nicht dazuschreiben, dass x 3 zugewiesen wird, sondern lieber "x = PI" schreiben und PI als Konstante definieren. Kommentare sind nicht refactoring safe und können im Laufe der Entwicklung im schlimmsten Fall falsche Schlüsse liefern.

## Globale Variablen
Bitte vermeiden Sie globale Variablen. Die können von allen Seiten aus manipuliert werden. Das heißt sie können theoretisch von einer komplett unabhängigen Stelle manipuliert werden. Z.B. aus einer anderen Funktion heraus. Es kann auch zu Fehlern kommen, wenn mehrere Programmierer in scheinbar unabhängigen Teilen des Programms globale Variablen verwenden. Wenn Sie später mehrere Dateien haben, kann es dann - je nachdem welche Programmteile zusammengeführt werden - zu Fehlern kommen, dass die Variable mehrmals deklariert wurde. Das heißt konkret: Deklarieren Sie alle Variablen in ihren Funktionen. Es gibt nur sehr wenige Ausnahmen, wo eine globale Variable wirklich sinnvoll ist - und das ist meistens dann so, wenn die gesamte Softwarearchitektur schon schlecht ist. Also designen Sie generell keine Funktionen, die globale Variablen nutzen.

# Variablennamen
Bitte verwenden Sie sprechende Variablennamen. Dinge wie val1, val2 usw. verraten nicht, für was die Variablen eigentlich da sind. Das macht es schwerer den Code zu verstehen und führt oft dazu, dass Sie Kommentare verwenden müssen. Namen wie "geschwindigkeit_mps" sind besser als einfach nur "g", oder für Schleifenzähler ist "row" und "column" für eine Tabelle ein besser Name als "i" und "j".

# Bitmasken
Bitte verwenden Sie keine Decimals für Bitmasken. Hex (0x) oder binary (0b) Konstanten sind da viel deutlicher.

# Character Konstanten
Verwenden Sie bitte char Konstanten für character.

# Design and Implementation should not overlap

Funktioniert, aber bitte Angabe beachten: Sie sollen das Struktogramm umsetzen. Das Prinzip nennt sich "Design and Implementation should not overlap". Schauen Sie mal auf die Clean Code Seite. (Ist aber nicht Bestandteil des Praktikums, aber eine gute Richtlinie zum Entwickeln).