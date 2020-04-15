Mit `printf` lassen sich Zahlen und Zeichen auf der Konsole formatiert ausgeben. `printf` ist eine sogenannte **Funktion**, die wir im späteren Verlauf noch genauer betrachten werden. Sie ist in der Datei `stdio.h`, was ausgesprochen für _Standard Input and Output_ steht, definiert.

Die Datei `stdio.h` ist eine Standardbibliothek von C und daher bei allen Compilern verfügbar. Deswegen wird sie auch mit spitzen Klammern eingebunden: `<stdio.h>`. Wird sie nicht eingebunden, so findet der Compiler auch die Funktion `printf` nicht! Das heißt in der Praxis: Wenn Ihnen Ihr Compiler mitteilt, dass er `printf` nicht kennt, haben Sie in der Regel einfach vergessen diese Datei zu referenzieren. Alternativ wäre die Installation ihres Compilers defekt.

`printf` benötigt mehrere Parameter, um seine Arbeit richtig zu tun. Parameter werden in runden Klammern übergeben und mit Kommas getrennt:

```c
printf(/*<Parameter 1>*/, /*Parameter 2*/, /*Parameter 3*/, /*...*/);
```

### Der Formatstring

Bei `printf` ist der erste Parameter immer der sogenannte **Formatstring**. Ein `string` ist eine **Zeichenkette**; das heißt sie besteht aus mehreren `char`, die nacheinander im Speicher liegen. Wenn Sie in C eine `string` Konstante erstellen wollen, müssen Sie _doppelte Anführungszeichen_ verwenden.

<details open>
<summary>Formatbezeichner für <b>printf</b></summary>

| Bezeichner     | Beschreibung                                                                                          |
| -------------- | ----------------------------------------------------------------------------------------------------- |
| `%d`, `%i`     | vorzeichenbehaftete ganze Dezimalzahl                                                                 |
| `%lld`, `%lli` | vorzeichenbehaftete ganze Dezimalzahl (`long long`)                                                   |
| `%o`           | vorzeichenlose ganze Oktalzahl                                                                        |
| `%u`           | vorzeichenlose ganze Dezimalzahl                                                                      |
| `%llu`         | vorzeichenlose ganze Dezimalzahl (`unsigned long long`)                                               |
| `%x`, `%X`     | vorzeichenlose ganze Hexzahl *(a,b,c,d,e,f)* bei `x`; *(A,B,C,D,E,F)* bei `X`                         |
| `%llx`, `%llX` | vorzeichenlose ganze Hexzahl *(a,b,c,d,e,f)* bei `x`; *(A,B,C,D,E,F)* bei `X` (`unsigend long long`)  |
| `%f`           | Gleitpunktzahl in Form von ddd.dddddd                                                                 |
| `%e`, `%E`     | Gleitpunktzahl in Form von `d.ddde+-dd` bzw. `d.dddE+-dd`. Der Exponent enthält mindestens 2 Ziffern. |
| `%a`           | wie %f (neu ab C99)                                                                                   |
| `%g`, `%G`     | float ohne Ausgabe der nachfolgenden Nullen                                                           |
| `%c`           | Form von einem Zeichen (`unsigned char`)                                                              |
| `%s`           | Form einer Zeichenkette                                                                               |
| `%%`           | das Zeichen `%`                                                                                       |

<div style="text-align: right">Quelle: <a href="http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/005_c_basisdatentypen_020.htm">Rheinwerk Openbooks: C von A - Z</a></div>
</details>

Somit kann man Text mit Variablen oder Konstanten aus C kombinieren:

<script src="//onlinegdb.com/embed/js/SynoE71dI?theme=light"></script>

Wenn man diese Formatbezeichner verwendet, benötigt man auch immer die gleiche Anzahl an wieteren Übergabeparametern. Wie im folgenden Beispiel muss man, wenn man drei `%d` ausgaben verwendet auch drei Variablen `..., 1, 2, 3` mit übergeben. Die ganzen Parameter werden einfach mit `,` getrennt. Man kann beliebig viele Parameter übergeben, aber der erste Parameter muss immer der **Formatstring** sein.

```c
printf("%d, %d, %d", 1, 2, 3);
```