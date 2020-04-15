`printf` gibt dem Programmierer bei der Formatierung weitere Möglichkeiten. Dies ist mit sogenannten `Flags` realisiert. Diese erlauben es weitere Formatierfunktionen auf der Konsole auszuführen. Dies ist sehr hilfreich, um zum Beispiel Tabellen zu realisieren, bei denen die Werte spaltenweise untereinander stehen sollen. Aber auch Vorzeichen und führende oder folgende Nullen sind damit möglich.

<details open>
<summary>Tabelle für Format Flags</summary>

| Flag | Bedeutung |
| - | - |
| `-` | Linksbündig justieren |
| `+` | Ausgabe des Vorzeichens `+` oder `-` |
| `Leerzeichen` | Ist ein Argument kein Vorzeichen, wird ein Leerzeichen mit ausgegeben. |
| `0` | Bei numerischer Ausgabe wird mit Nullen bis zur angegebenen Weite aufgefüllt. |
| `#` | Bei `o` bzw. `x` oder `X` (bspw. `%#X`) wird der Wert im Formatstring mit vorangestellter `0` bzw. `0x` ausgegeben. |
| `n` | Es werden mindestens n Stellen ausgegeben, auch wenn der Wert weniger als n Stellen besitzt. n ist eine Dezimalzahl. Zum Beispiel `%5d` -> n = 5 |
| `*` | Der Wert des vorhergehenden Arguments (ganzzahlig) legt die Weite fest; z.B. `printf("%*s", 20, "Test");`. Bei negativem Wert wird linksbündig justiert. |
| `.n` | Bei `%f`, bzw. `%lf` gibt es die Möglichkeit die Anzahl der gewünschten Nachkommastellen anzugeben. Der Standard ist 6 Nachkommastellen. Beispiel: `2.345f` ausgegeben mit `%.2f` wird zu `%2.35`. Die 5 wird aufgerundet. <font color="gray">*(Achtung! Dies variiert von Compiler zu Compiler / Programmiersprache zu Programmiersprache, je nachdem wie dort der Standard die Rundung festlegt!)*</font>

<div style="text-align: right">Quelle: <a href="http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/005_c_basisdatentypen_020.htm">Rheinwerk Openbooks: C von A - Z</a></div>
</details>

Der folgende Code zeigt einige Anwendungsbeispiele für Formatierungsflags:

<details open>
<summary>Beispiele zur Anwendung:</summary>
<script src="//onlinegdb.com/embed/js/ryxGaN1dU?theme=light"></script>
</details>

Die Flags lassen sich oft beliebig miteinander kombinieren, um das gewünschte Format zu erzeugen. Hier gilt es auf die Compilerwarnungen zu achten, ob die richtige Reihenfolge gewählt wurde.


