#include <stdio.h>
#include <math.h>

int main()
{
    char characterToEncode, xNotOk = 1, readCount, checkNewline;
    int x = 0;

    printf("Dieses Programm verschluesselt eine Zeichenkette.\n");
    printf("================================================\n\n");

    printf("Um wie viel soll die Zeichenkette verschoben werden (1 - 25)?\n\n");

    xNotOk = 1;
    while (xNotOk)
    {
        readCount = scanf("%d%c", &x, &checkNewline);
        if (readCount != 2 || checkNewline != '\n' || x < 1 || x > 25)
        {
            printf("Bitte geben Sie eine ganze Zahl zwischen 1 und 25 ein!\n\n");
            while (checkNewline != '\n')
                checkNewline = getchar();
        }
        else
        {
            xNotOk = 0;
        }
    }

    printf("\nAlle Buchstaben und Zahlen werden um %d Stellen verschoben.\n\n", x);

    printf("Geben Sie die Zeichenkette ein, die verschluesselt werden soll:\n\n");

    scanf("%c", &characterToEncode);

    printf("\nDie verschluesselte Zeichenkette lautet:\n\n");

    while (characterToEncode != '\n')
    {
        if (characterToEncode >= 'a' && characterToEncode <= 'z')
        {
            characterToEncode = characterToEncode + x;
            if (characterToEncode > 'z')
            {
                characterToEncode = characterToEncode - 26;
            }
        }
        if (characterToEncode >= 'A' && characterToEncode <= 'Z')
        {
            characterToEncode = characterToEncode + x;
            if (characterToEncode > 'Z')
            {
                characterToEncode = characterToEncode - 26;
            }
        }
        if (characterToEncode >= '0' && characterToEncode <= '9')
        {
            characterToEncode = characterToEncode + x;
            while (characterToEncode > '9')
            {
                characterToEncode = characterToEncode - 10;
            }
        }
        printf("%c", characterToEncode);
        scanf("%c", &characterToEncode);
    }

    return 0;
}