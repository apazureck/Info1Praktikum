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

Arrays (deutsch: *Felder*) sind eine Folge von gleichen Datentypen, die nacheinander im Arbeitsspeicher liegen. Damit kann man in einer Variable mit einem bestimmten Namen nicht nur einen Wert abspeichern, sondern beliebig viele, solange der Programmspeicher reicht und diese auch nacheinander darin Platz haben.

## Array erstellen

In C wird ein Array folgendermaßen deklariert:

```c
const LANGE = 6;
float array[LAENGE];
```

Mit diesem Code erhält man ein `float` Array mit dem Namen `array` mit der Länge 100. Dabei gibt man zuerst den Datentypen an, den alle Arraywerte haben sollen. Hier ist dieser `float`. Als nächstes gibt man den Namen des Arrays an, damit man später wieder auf die Werte, oder das ganze Array zugreifen kann. In diesem Fall heißt das Array einfach `array`. In den eckigen Klammern `[]` wird die Länge des Arrays angegeben.

Die Länge muss immer vor dem Kompilieren bekannt sein. Der Compiler muss wissen, wie viel Speicherplatz er für das Array reservieren muss. Im Speicher sieht das Array dann Folgendermaßen aus.

<div class="arrayexample">
<span>... Speicherzellen davor ...<b><br/>Index<br/>Wert<br/>Speicherplatz</b></span>
<span><code>float<br/>0<br/>?<br/>4 Byte</code></span>
<span><code>float<br/>1<br/>?</code></span>
<span><code>float<br/>2<br/>?</code></span>
<span><code>float<br/>3<br/>?</code></span>
<span><code>float<br/>4<br/>?</code></span>
<span><code>float<br/>5<br/>?</code></span>
<span>... Speicherzellen danach ...</span>
</div>

## Lesen und Schreiben von Werten in ein Array

Ist ein Array deklariert, so verhält es sich mit den Werten im Array genauso, wie auch mit den Werten von Variablen. Es wird das letzte Bitmuster in dem Datentypen interpretiert, welchen die Variable hat.

Daher muss man die Werte in einem Array erst zuweisen, sprich intialisieren. Um einen einzelnen Wert in einem Array zuzuweisen, schreibt man den Arraynamen und danach in eckigen Klammern den Index des zu setzenden Eintrags. Danach kann mit einem Zuweisungsoperator `=` der Wert an dem Index des Arrays gesetzt werden.

```c
float array[10];
array[0] = 1;
```

Hier gilt zu beachten, dass die Arrayeinträge - wie auch in dem Speicherausschnitt oben zu sehen - über einen sogenannten Index angesprochen werden. Dieser Index beginnt immer mit einer 0. Das `erste` Element in einem Array hat somit den Index `0`, das `zweite` den Index `1`, das `dritte` den Index `2`, usw.