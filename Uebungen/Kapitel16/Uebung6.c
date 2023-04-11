#include <stdio.h>
#include "../headers/constants.h"

int main(void)
{
    unsigned int zahl, error = 1, read = 1, quersumme = 0;
    char input;
    printf("Dieses Programm liest eine beliebig lange Zahl ein und gibt deren Quersumme aus.\n");
    printf("=======================\n\n");

    while (error)
    {
        printf("Geben Sie die Zahl ein, für die die Quersumme berechnet werden soll:\n\n");

        quersumme = 0;
        read = 1;
        while (read)
        {
            input = getchar();
            switch (input)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                zahl = input - '0';
                quersumme += zahl;
                break;
            case '\n':
                read = 0;
                error = 0;
                printf("Die Quersumme der Zahl ist: %u", quersumme);
                break;
            default:
                printf("Fehlerhafte Eingabe!\n\n");
                while (getchar() != '\n');
                {
                    
                }                
                read = 0;
                break;
            }
        }
    }

    
    return 0;
}