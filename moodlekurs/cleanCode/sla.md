Um Ihre Funktionen lesbar zu halten, sollten Sie es vermeiden Low-Level Operationen, wie Bitoperationen, Vergleichsoperationen, oder logischen Operationen, usw. mit Aufrufen anderer Funktionen zu mischen. Dieses Konzept nennt man **S**ingle **L**evel of **A**bstraction (**SLA**).

Lagern Sie diese am Besten in eigene Funktionen aus. Das hilft anderen Ihren Code besser zu verstehen. Verdeutlichen soll dies das Beispiel aus [Separation of Concerns](https://elearning.ohmportal.de/mod/page/view.php?id=361670):

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

Hier lassen sich die Vergleiche in den `if`s in eigene Funktionen auslagern:

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

    if(parameterCountIsInvalid(inputParamCount)) {
        printf("Sie haben kein korrektes Alter eingegeben!\n");
        return -1;
    }

    // 3. Kontrolliere Eingabeparameter

    if(isUserNotOfLegalAge(userAge)) {
        printf("Sie sind zu jung!\n");
        return -2;
    }
}

int parameterCountIsinvalid(int inputParameterCount) {
    return inputParamCount != VALID_INPUT_PARAMETERS;
}

int isUserNotOfLegalAge(int userAge) {
    return userAge < LEGAL_AGE_IN_YEARS;
}
```

Jetzt ist die `main`-Funktion auf einem höheren Abstraktionsnievau. Es werden keine direkten Vergleiche mehr gemacht, sondern nur noch Funktionen aufgerufen. Man kann auch noch das `scanf` "webastrahieren". Somit wird die `main`-Funktion klar lesbar. Die Absticht des Autors ist auch für Nicht-C-Kenner klar ersichtlich:

```c

int main() {
    // Initialisieren
    const int VALID_INPUT_PARAMETERS = 1;
    const int LEGAL_AGE_IN_YEARS = 18;

    int userAge = 0;
    int inputParamCount = -1;

    // 1. Lies Benutzereingabe ein
    
    userAge = getUserAge();


    // 3. Kontrolliere Eingabeparameter

    if(isUserNotOfLegalAge(userAge)) {
        printf("Sie sind zu jung!\n");
        return -2;
    }
}

int parameterCountIsinvalid(int inputParameterCount) {
    return inputParamCount != VALID_INPUT_PARAMETERS;
}

int isUserNotOfLegalAge(int userAge) {
    return userAge < LEGAL_AGE_IN_YEARS;
}

int getUserAge() {
    int userAge = 0;
    printf("Geben Sie ihr Alter ein: ");
    inputParamCount = scanf("%d", &userAge);

    if(parameterCountIsInvalid(inputParamCount)) {
        printf("Sie haben kein korrektes Alter eingegeben!\n");
        return -1;
    }
    return userAge;
}
```

Jetzt ist die `main`-Funktion auf einem noch höheren Abstraktionsnievau, da sie sich nicht einmal mehr mit dem Einlesen beschäftigen muss, sondern einfach nur das Alter abfragt und danach prüft, ob die Person schon erwachsen ist. Alle Prüfungen, ob der Wert korrekt eingelesen werden konnte, sind nun in der Funktion `getUserAge`.

<a href="https://clean-code-developer.de/die-grade/orangener-grad/#Single_Level_of_Abstraction_SLA">Quelle: Clean Code Developer - Single Level of Abstraction (SLA)</a>