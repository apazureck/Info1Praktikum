<style>
.flex {
    display: flex;
    flex-direction: column;
    float: right;
    padding: 0 20px 0 0;
}
.emptybox {
    border-width: 1px;
    border-color: cornflowerblue;
    border-style: solid;
    padding: 5px; 
}
.filledbox {
    background: cornflowerblue;
    color: black;
    text-align: center;
}

.bitpatternbox {
    display: flex;
}
.bitpatternbox code {
    letter-spacing: 2px;
}
.byte {
    border-style: solid;
    border-width: 1px;
    border-color: cornflowerblue;
    width: 80px;
    text-align: center;
    height: 50px;
}
.floatbox {
    position: relative;
    text-align: center;
}

.listspan {
    float:left;
    width:25px;
}
</style>

<div class="flex">
<div class="filledbox">
Floating Point
</div>
<div class="emptybox">
<span class="listspan">10.</span> long double<br/>
<span class="listspan">9.</span> double<br/>
<span class="listspan">8.</span> float<br/>
</div>
<div class="filledbox">
Integer
</div>
<div class="emptybox">
<span class="listspan">7.</span> long long<br/>
<span class="listspan">6.</span> long<br/>
<span class="listspan">5.</span> int<br/>
<span class="listspan">4.</span> short<br/>
</div>
<div class="filledbox">
Character
</div>
<div class="emptybox">
<span class="listspan">2.</span> char
</div>
<div class="filledbox">
Boolean
</div>
<div class="emptybox">
<span class="listspan">1.</span> bool
</div>
</div>

In C gibt es verschiedene numerische Datentypen. In einigen Fällen ist es daher nötig diese Datentypen zu konviertieren, ohne dass diese ihren Wert verlieren. Nimmt man zum Beispiel die Integerzahl 52 und speichert diese als `int` Datentyp ab, so ergibt sich folgendes Bitmuster:

<div class="bitpatternbox">
<div class="byte">
Byte 4<br/>
<code>00000000</code>
</div>
<div class="byte">
Byte 3<br/>
<code>00000000</code>
</div>
<div class="byte">
Byte 2<br/>
<code>00000000</code>
</div>
<div class="byte">
Byte 1<br/>
<code>00110100</code>
</div>
</div>

<div class="bitpatternbox">
<div class="floatbox" style="background:darkSeaGreen;width:10px;color:black;margin-left:0px">
V
</div>
<div class="floatbox" style="background:khaki;width:80px;color:black">
Exponent
</div>
<div class="floatbox" style="background:orangeRed;width:230px;color:black">
Mantisse
</div>
</div>

Würde man dieses Bitmuster einfach nehmen und dem Computer miteilen, dass dies eine `float` Zahl ist, so ergibt sich der Wert `7.286752e-44`. Da man beim Programmieren in den meisten Fällen den eigentlichen **Wert** der Variablen erhalten möchte und nicht dessen Bitmuster, führt C im Hintergrund sogenannte *implizite Typenumwandlungen* (engl. *implicit Typecasts*) durch, wenn zwei Werte unterschiedlichen Typs miteinander verrechnet werden.

### Implizite Typenumwandlung

Dabei hat C eine klare Hierarchie. Wird zum Beispiel ein `char` in einer Operation mit einem `int` verwendet, so wird der `char`-Wert zuerst in einen `int`-Wert umgewandelt und dann wird die Rechenoperation durchgeführt. Genauso verhält es sich mit `int`s und `float`s, wie in der Tabelle oben links zu sehen ist. Wenn zwei unterschiedliche Datentypen miteinander interagieren, so wird immer der "*größere*" Datentyp genommen.

```c
int integer = 5;
float floating = 45, result;

        // Dieses int wird zuerst in ein float umgewandelt
result = integer * floating;
```

Die verdeutlicht sich auch im resultierenden Assemblercode. Im Folgenden ist auf der linken Seite der C-Code und rechts der resultierende Assembler Code. Die rot hinterlegte Multiplikation resultiert in einer vorangehenden Konvertierung in Zeile `7`. Danach werden erst die Move- und Multiplikationsbefehle ausgeführt.

<iframe width="100%" height="450px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(fontScale:14,j:1,lang:___c,selection:(endColumn:22,endLineNumber:1,positionColumn:22,positionLineNumber:1,selectionStartColumn:22,selectionStartLineNumber:1,startColumn:22,startLineNumber:1),source:'void+implicitTypecast()+%7B%0A++++int+integer+%3D+5%3B%0A++++float+floating+%3D+45,+result%3B%0A%0A++++//+Dieses+char+wird+zuerst+in+ein+int+umgewandelt%0A++++result+%3D+integer+*+floating%3B%0A%7D'),l:'5',n:'0',o:'C+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:cg93,filters:(b:'0',binary:'1',commentOnly:'0',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'1',trim:'1'),fontScale:14,j:1,lang:___c,libs:!(),options:'',selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1),l:'5',n:'0',o:'x86-64+gcc+9.3+(Editor+%231,+Compiler+%231)+C',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

### Explizite Typenumwandlung

<style>
.flex {
    display: flex;
    flex-direction: column;
    float: right;
    padding: 0 20px 0 0;
}
.emptybox {
    border-width: 1px;
    border-color: cornflowerblue;
    border-style: solid;
    padding: 5px; 
}
.filledbox {
    background: cornflowerblue;
    color: black;
    text-align: center;
}

.listspan {
    float:left;
    width:25px;
}
</style>

<div class="flex">
<div class="filledbox">
Floating Point
</div>
<div class="emptybox">
<span class="listspan">10.</span> long double<br/>
<span class="listspan">9.</span> double<br/>
<span class="listspan">8.</span> float<br/>
</div>
<div class="filledbox">
Integer
</div>
<div class="emptybox">
<span class="listspan">7.</span> long long<br/>
<span class="listspan">6.</span> long<br/>
<span class="listspan">5.</span> int<br/>
<span class="listspan">4.</span> short<br/>
</div>
<div class="filledbox">
Character
</div>
<div class="emptybox">
<span class="listspan">2.</span> char
</div>
<div class="filledbox">
Boolean
</div>
<div class="emptybox">
<span class="listspan">1.</span> bool
</div>
</div>

In manchen Fällen kann der Compiler keinen impliziten Typecast durchführen, oder es nimmt einen falschen Typen an. Daher kann man in C auch explizit einen Typecast anordnen. Dies geschieht, indem man vor die Variable oder Konstante in Klammern den Typen angibt, in den gecastet werden soll.

> `(<Zieltyp>)<Variable, Konstante oder Ausdruck>`

#### Ein Beispiel

```c
short s = 5;
int   i = (int)s * 3;
float f = (float)i / (float)21;
```

Im obigen Beispiel wird die `short` Variable `s` zu `int` gecastet und dann mit der `int` Konstanten `3` multipliziert. Der Typecast wird hier zuerst ausgeführt, da eine hohe Priorität besitzt. Danach wird die `int` Variable `i` zu float gecastet. Auch die Konstante `21` wird zu float gecastet. Danach wird die Variable `i` mit der (jetzt `float` Konstanten `21` dividiert.

#### Ein Beispiel zur praktischen Anwendung

Ein klassisches Beispiel ist die `integer` Division:

```c
 2 int first = 5, second = 10;
 3 double result;
 4
 5 result = first / second;
```

In diesem Fall wird der Compiler zuerst eine Integer Division durchführen. Dies kann man sich auch noch einmal verdeultichen, indem man den resultierenden Assemblercode ansieht:

```assembly
 8       idiv    DWORD PTR [rbp-8]
 9       cvtsi2sd        xmm0, eax
```

Es wird zuerst eine Integer Division durchgeführt (`idiv`) und danach das Ergebnis zu `double` konviertiert (`cvtsi2sd`). Dies führt dazu, dass das Ergebnis bei dieser Division `0` wird und dadurch auch die Variable `result`.

Anders verhält es sich, wenn eine der `int` Variablen (`first` oder `second`) vorher explizit umgewandelt wird:

```c
12 result = first / (double)second;
```

Dies führt zu folgendem Assemblercode, der zuerst beide `int` Variablen in `double` typecastet. Danach wird die Floatingpoint Divsion durchgeführt.

```assembly
19      cvtsi2sd        xmm0, DWORD PTR [rbp-4]
20      cvtsi2sd        xmm1, DWORD PTR [rbp-8]
21      divsd   xmm0, xmm1
```

Hier der komplette Assemblercode zum nachschlagen:

<iframe width="100%" height="620px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(fontScale:14,j:1,lang:___c,selection:(endColumn:2,endLineNumber:13,positionColumn:2,positionLineNumber:13,selectionStartColumn:2,selectionStartLineNumber:13,startColumn:2,startLineNumber:13),source:'void+integerDivision()+%7B%0A++++int+first+%3D+5,+second+%3D+10%3B%0A++++double+result%3B%0A%0A++++result+%3D+first+/+second%3B%0A%7D%0A%0Avoid+explicitTypecast()+%7B%0A++++int+first+%3D+5,+second+%3D+10%3B%0A++++double+result%3B%0A%0A++++result+%3D+first+/+(double)second%3B%0A%7D'),l:'5',n:'0',o:'C+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:cg93,filters:(b:'0',binary:'1',commentOnly:'0',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'1',trim:'1'),fontScale:14,j:1,lang:___c,libs:!(),options:'',selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1),l:'5',n:'0',o:'x86-64+gcc+9.3+(Editor+%231,+Compiler+%231)+C',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>