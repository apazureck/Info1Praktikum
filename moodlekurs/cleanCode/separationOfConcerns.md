Ein Codeabschnitt (also eine Funktion, oder später auch Klassen) sollten sich immer um eine bestimmte Aufgabe (Concern) kümmern. Nachdem es in C keine Klassen gibt interessiert es uns erst einmal nicht. Zu Separation of Concerns in Funktionen sagt Clean Code zum Beispiel:

> *"Innerhalb einer Methode sollte beispielsweise klar erkennbar sein, dass es mehrere Concerns gibt. Ferner sollten die Concerns nicht irgendwie über die Methode verstreut sein, sondern so gruppiert, dass klar ist, was zu einem Concern gehört."*

Anmerkung: **Methode** meint hier eine Funktion auf einer Klasse. Nachdem es in unserem Fall in C keine Klassen gibt, können Sie das Wort einfach durch Funktion ersetzen. Wir kennen bis Dato genau eine Funktion: Die `main` Funktion.

Wenn Sie zum Beispiel Benutzereingaben einlesen und checken wollen, können Sie das in mehreren Schritten tun:

1. Einlesen mit `scanf`
2. Kontrollieren des Rückgabewerts
3. Kontrollieren der Eingabeparameter

Dies kann in Ihrem Code zum Beispiel mit Kommentaren realisiert werden:

```c
int main() {
    // Initialisieren
    const int VALID_INPUT_PARAMETERS = 1;
    const int LEGAL_AGE_IN_YEARS = 18;

    int userAge = 0;
    int inputParamCount = -1;

    // 1. Lies Benutzereingabe ein
    
    printf("Geben Sie ihr Alter ein: ");
    inputParamCount = scanf("%d", &userAge);

    // 2. Checke Rückgabeparameter

    if(inputParamCount != VALID_INPUT_PARAMETERS) {
        printf("Sie haben kein korrektes Alter eingegeben!\n");
        return -1;
    }

    // 3. Kontrolliere Eingabeparameter

    if(userAge < LEGAL_AGE_IN_YEARS) {
        printf("Sie sind zu jung!\n");
        return -2;
    }
}
```

Hier sind nun alle Aufgaben (Concerns) optisch klar von einander getrennt. Sie greifen auch nicht ineinander über. Erst wenn das Einlesen komplett beendet wurde wird die Anzahl der Eingabeparameter geprüft. Erst wenn die Eingabeparameter geprüft wurden, wird auf das richtige Alter geprüft, usw.

Es ist natürlich auch hilfreich die Blöcke gleich in eigene Funktionen auszulagern. Dazu aber später mehr, wenn Sie lernen, wie man eigene Funktionen erstellt...

<a href="https://clean-code-developer.de/die-grade/orangener-grad/#Separation_of_Concerns_SoC" style="float:right">Quelle: Clean Code Developer - Separation of Concerns</a>