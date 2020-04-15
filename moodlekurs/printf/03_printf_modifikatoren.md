Bei den formatierten Ausgaben werden immer bestimmte Standard-Datentypen verwendet. Dies kann dazu führen, dass nicht die erwartete Ausgabe auf dem Bildschirm erscheint.

Zum Beispiel kann man erwarten, dass folgender Code:

```c
short toShift = 0xABCD;
printf("Shifted %X 8 to the left: %X", toShift, toShift << 8);
```

diese Ausgabe erzeugt:

```shell
Shifted ABCD 8 Bits to the left: CD00
```

Jedoch wird folgende Ausgabe erzeugt:

```shell
Shifted FFFFABCD 8 Bits to the left: FFABCD00
```

Dies kommt daher, dass `printf` aus der `short` Variablen mit 4 Bytes automatisch eine `int` Variable mit 8 Bytes macht. Dieser Vorgang heißt **Autopromotion**. Um dies zu verhindern, kann man sogenannte Modifier mit angeben.

<details open>
<summary>Tabelle für Modifier</summary>

| Modifier | Beschreibung |
| - | - |
| `h` | Die Umwandlungszeichen `d`, `i`, `o`, `u`, `x`, `X` werden als `short int`-bzw. `unsigned short int`-Wert behandelt. |
| `l` | Die Umwandlungszeichen `d`, `i`, `o`, `u`, `x`, `X` werden als `long int`- bzw. `unsigned long int`-Wert behandelt. Wird hingegen `e`, `f` oder `g` verwendet, werden die Umwandlungszeichen als `double`-Wert behandelt. |
| `L` | Die Umwandlungszeichen `e`, `E`, `f`, `g`, `G` werden als `long double`-Wert behandelt. Die Umwandlungszeichen `d`, `i`, `o`, `u`, `x`, `X` hingegen werden als `long long`-Wert behandelt. |
| `hh` | Wie `h`, nur dass die Umwandlungszeichen `d`, `i`, `o`, `u`, `x`, `X` als `signed char`- bzw. `unsigned char`-Wert behandelt werden. |

<div style="text-align: right">Quelle: <a href="http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/005_c_basisdatentypen_020.htm">Rheinwerk Openbooks: C von A - Z</a></div>

</details>

Die gewünschte Ausgabe im obigen Beispiel kann also erreicht werden, wenn man den `h` Modifier benutzt:

```c
short toShift = 0xABCD;
printf("Shifted %hX 8 to the left: %hX", toShift, toShift << 8);
```

gibt demnach jetzt auch das gewünschte Ergebnis aus:

```shell
Shifted ABCD 8 Bits to the left: CD00
```