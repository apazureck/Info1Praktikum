Ein deutliches Symptom schlecht wandelbaren Codes sind tiefe Hierarchien funktionaler Abhängigkeit. Sie reduzieren die Verständlichkeit und erschweren automatisierte Tests wie Refactoring.

Das **I**ntegration **O**peration **S**egregation **P**rinciple (IOSP) hilft Ihnen mit zwei Regeln dabei Ihren Code einfach zu strukturieren. Dabei besagt jede Regel, was eine Funktion enthalten darf:

1. Eine *Integration* darf nur andere Funktionen aufrufen.
2. Eine *Operation* darf nur Logik enthalten. Das heißt Schleifen, Strukturen, wie `if` und `switch`, Variablenzuweisungen und andere Operatoren.

Um das zu verdeutlichen, hier ein kleines Beispiel aus der Übung 15 mit der harmonischen Reihe:

```c
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    int run = TRUE;
    unsigned int input;

    printf("Harmonische Reihe\n");
    printf("========================================\n");
    printf("Druecke 'q' zum beenden.\n");

    while (run)
    {
        printf("\nBis zu welchem n soll die harmonische Reihe berechnet werden? ");
        int inputok = scanf("%u", &input);

        // Check input
        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                break;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        double summe = 0;
        for(int i = 1; i<= input; i++)
            summe += 1.0 / i;
        
        printf("  Summe bis 1/%u: %f\n", input, summe);
    }

    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
    return 0;
}
```

Dies enthält zur Zeit viele Operationen, wie `while`, `if` und Variablenzuweisungen. Lower Level Systemfunktionen, wie `printf`, zählen wir jetzt großzügig auch zu unseren Operationen. Beim Bestimmen, was in diesem Fall eine Operation sein soll, kann man auch das [Single Level of Abstraction](https://elearning.ohmportal.de/mod/page/view.php?id=361693) Prinzip heranziehen.

Im ersten Schritt machen wir aus der `main` Funktion eine *Integration*. Dazu fassen wir alle Dinge vor unserer Schleife in der Funktion `printIntro` zusammen. Den Code nach der Schleife in die Funktion `cleanUp`. Die Schleife selbst lagern wir in die Funktion `runHarmonicRowProgram` aus. Somit ruft unsere `main` Funktion jetzt nur noch andere Methoden auf:

```c
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void printIntro();
void runHarmonicRowProgram();
void cleanUp();

/*--- Funktionsdefinitionen ------------------------------------------*/
int main(void)
{
    printIntro();

    runHarmonicRowProgram();

    cleanUp();
    
    return 0;
}

void printIntro() {
    printf("Harmonische Reihe\n");
    printf("========================================\n");
    printf("Druecke 'q' zum beenden.\n");
    
}

void cleanUp() {
    printf("Die Anwendung wurde vom Benutzer beendet.");
    fflush(stdin);
    getchar();
}

void runHarmonicRowProgram() {
    
    int run = TRUE;
    unsigned int input;
    
    while (run)
    {
        printf("\nBis zu welchem n soll die harmonische Reihe berechnet werden? ");
        int inputok = scanf("%u", &input);

        // Check input
        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                break;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        double summe = 0;
        for(int i = 1; i<= input; i++)
            summe += 1.0 / i;
        
        printf("  Summe bis 1/%u: %f\n", input, summe);
    }
}
```

Mit unseren C Bordmitteln lassen sich bei diesem Code keine weiteren, gänzlichen Integrationen herstellen. Aber es ist möglich Funktionen nahe dran zu bringen. Dazu können wir zuerst den Teil der Funktion `runHarmonicRowProgram`, der die harmonische Reihe berechnet, auszulagern. So erhalten wir dafür eine saubere *Operation* `calculateHarmonicRow`:

```c
void runHarmonicRowProgram() {
    
    int run = TRUE;
    unsigned int input;
    
    while (run)
    {
        printf("\nBis zu welchem n soll die harmonische Reihe berechnet werden? ");
        fflush(stdin);
        int inputok = scanf("%u", &input);

        // Check input
        if (!inputok)
        {
            char quit = getchar();
            if (quit == 'q' || quit == 'Q')
                break;
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        summe = calculateHarmonicRow(input);
        
        printf("  Summe bis 1/%u: %f\n", input, summe);
    }
}

double calculateHarmonicRow(int input) {
    double summe = 0;
    for(int i = 1; i<= input; i++)
        summe += 1.0 / i;
    return summe;
}
```

Danach kann man noch den Input Check zusammenfassen. Es gibt eine Operation, um festzustellen, ob der Benutzer das Programm beenden will. Dies kann man in die Operation `shouldQuit` auslagern:

```c
void runHarmonicRowProgram() {
    
    int run = TRUE;
    unsigned int input;
    
    while (run)
    {
        printf("\nBis zu welchem n soll die harmonische Reihe berechnet werden? ");
        fflush(stdin);
        int inputok = scanf("%u", &input);

        // Check input
        if (!inputok)
        {
            if (shouldQuit())
                break;
            
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
            continue;
        } // no else needed, as code does either break or continue to next loop

        // Calculation:
        summe = calculateHarmonicRow(input);
        
        printf("  Summe bis 1/%u: %f\n", input, summe);
    }
}

double calculateHarmonicRow(int input) {
    double summe = 0;
    for(int i = 1; i<= input; i++)
        summe += 1.0 / i;
    return summe;
}

int shouldQuit() {
    char quit = getchar();
    return quit == 'q' || quit == 'Q';
}
```

Des weiteren lassen sich keine weiteren sauberen Operationen mehr herauslösen. Aber wenn man [Single Level of Abstraction](https://elearning.ohmportal.de/mod/page/view.php?id=361693) und [Separation of Concerns](https://elearning.ohmportal.de/mod/page/view.php?id=361670) beachtet, lohnt es sich den Code noch weiter umzubauen.

### Separation of Concerns

Wenn man den Inhalt der `while` Schleife näher betrachtet, stellt man fest, dass dort drei Aufgaben erledigt werden.

1. Benutzereingaben werden eingelesen
2. Benutzereingaben werden validiert
3. Harmonische Reihe wird berechnet

Die Berechnung der harmonischen Reihe wurde schon in eine eigene Funktion ausgelagert. Beim Einlesen und Auswerten, kann man das Gleiche tun:

```c
void runHarmonicRowProgram() {
    
    int run = TRUE;
    unsigned int input;
    
    while (run)
    {
        int inputOk = readInput(&input);

        run = validateInput(inputOk);

        if(inputOk)
            calculateHarmonicRowAndPrintResult(input);
        
    }
}
```
Somit erhält man die obige, knappe Funktion mit dem eigentlichen Programm. Diese lässt sich sehr gut lesen, ohne dass sie viele Kommentare benötigt. Die eigentlichen Aufgaben (Concerns) haben wir in spezialisierte Funktionen ausgelagert:

```c
double calculateHarmonicRow(int input) {
    double summe = 0;
    for(int i = 1; i<= input; i++)
        summe += 1.0 / i;
    return summe;
}

int shouldQuit() {
    char quit = getchar();
    return quit == 'q' || quit == 'Q';
}

int readInput(unsigned int* input) {
    printf("\nBis zu welchem n soll die harmonische Reihe berechnet werden? ");
    fflush(stdin);
    return scanf("%u", input) == 1;
}

int validateInput(int inputOk) {
    int run;
    
    if (!inputOk)
    {
        run = !shouldQuit();
        
        if(run)
            printf("Eingabe ist keine gueltige positive Ganzzahl!\n");
    }
    return run;
}

void calculateHarmonicRowAndPrintResult(unsigned int input) {
    double summe = calculateHarmonicRow(input);
    printf("  Summe bis 1/%u: %f\n", input, summe);
}
```