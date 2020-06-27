Arrays (deutsch: *Felder*) sind eine Folge von gleichen Datentypen, die nacheinander im Arbeitsspeicher liegen. Damit kann man in einer Variable mit einem bestimmten Namen nicht nur einen Wert abspeichern, sondern beliebig viele, solange der Programmspeicher reicht und diese auch direkt nacheinander darin Platz haben.

## Array erstellen

In C wird ein Array folgendermaßen deklariert:

```c
const LANGE = 6;
float array[LAENGE];
```

Mit diesem Code erhält man ein `float` Array mit dem Namen `array` mit der Länge `6`. Dabei gibt man zuerst den **Datentypen** an, den alle Arraywerte haben sollen. Hier ist dieser `float`. Als nächstes gibt man den **Namen** des Arrays an, damit man später wieder auf die Werte, oder das ganze Array, zugreifen kann. In diesem Fall heißt das Array einfach `array`. In den eckigen Klammern `[]` wird die **Länge** des Arrays angegeben.

Die Länge muss immer vor dem Kompilieren bekannt sein. Der Compiler muss wissen, wie viel Speicherplatz er für das Array reservieren muss. Im Speicher sieht das Array dann Folgendermaßen aus:

<div class="arrayexample">
<span>... Speicherzellen davor ...<b><br/>Index<br/>Wert<br/>Speicherplatz</b></span>
<span><code>float<br/>0<br/>?<br/>4 Byte</code></span>
<span><code>float<br/>1<br/>?<br/>4 Byte</code></span>
<span><code>float<br/>2<br/>?<br/>4 Byte</code></span>
<span><code>float<br/>3<br/>?<br/>4 Byte</code></span>
<span><code>float<br/>4<br/>?<br/>4 Byte</code></span>
<span><code>float<br/>5<br/>?<br/>4 Byte</code></span>
<span>... Speicherzellen danach ...</span>
</div>

In der Darstellung steht oben der Datentyp. In der zweiten Zeile der Index, in der dritten Zeile der Wert und in der vierten der Speicherplatzbedarf. Das Array hat immer eine Startaddresse. Dies zeigt auf den ersten Arrayeintrag.

Der erste Eintrag hat den Index 0. Indizes in Arrays fangen immer mit 0 an und enden bei `Arraylänge - 1`.

Dadurch ergibt sich auch der Speicherplatz eines Arrays. Das Array belegt immer `sizeof(<Datentyp>) * Arraylänge` an Arbeitsspeicher. Das Beispielarray mit der Länge `6` hat also einen Speicherplatzbedarf von `6 * 4 Byte = 24 Byte`.

Die Werte sind, wie auch bei Variablen nicht automatisch initialisiert. Das heißt, was vorher in diesem Speicherbereich stand wird für das Programm entsprechend dem gegebenen Datentypen interpretiert. Daher muss ein Array unbedingt vor dem ersten Lesen beschrieben werden.

<style>
div.arrayexample {
    text-align: center;
    width: 100%;
    overflow: hidden;
    margin-top: 5px;
    display: flex;
    justify-content: space-between; 
}

div.arrayexample span:first-child {
    min-width: 180px;
}

div.arrayexample span:last-child {
    min-width: 180px;
}

div.arrayexample span {
    min-width: 50px;
    border:solid 1px green;
    margin-left: 3px;
    padding: 5px;
}

</style>