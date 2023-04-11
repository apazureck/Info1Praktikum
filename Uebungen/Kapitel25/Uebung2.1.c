/**********************************************************************\
* Kurzbeschreibung: Uebung: 17.1; Punkte: 0
*
* Datum:       Autor:               Grund der Aenderung:
* 01.06.2017   Andreas Pazureck     Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/constants.h"
#include "Uebung2.1.h"

int main(void)
{
    int sizearr1[2], sizearr2[2];

    do
    {
        getSizeForArray(1, sizearr1);
        getSizeForArray(2, sizearr2);
        if (sizearr1[1] != sizearr2[0])
            printf("Spalten der ersten Matrix muessen gleich den Zeilen der 2. Matrix sein!\n");
    } while (sizearr1[1] != sizearr2[0]);

    double matrix1[sizearr1[0] * sizearr1[1]], matrix2[sizearr2[0] * sizearr2[1]], result[sizearr1[0] * sizearr2[1]];
    printf("Eingabe der 1. Matrix\n");
    getMatrixValues(matrix1, sizearr1);
    printf("Eingabe der 2. Matrix\n");
    getMatrixValues(matrix2, sizearr2);

    printf("1. Matrix\n");
    printmatrix(matrix1, sizearr1);

    printf("2. Matrix\n");
    printmatrix(matrix2, sizearr2);

    matrixmultiplication(matrix1, sizearr1, matrix2, sizearr2, result);

    int sizeresult[2] = {sizearr1[0], sizearr2[1]};
    printf("Ergebnismatrix\n");
    printmatrix(result, sizeresult);

    fflush(stdin);
    getchar();
}

void getSizeForArray(int arraynumber, int sizearray[2])
{
    int inputinvalid;
    char c;

    do
    {
        printf("Zeilen,Spalten der %d. Matrix: ", arraynumber);
        inputinvalid = scanf("%d,%d%c", &sizearray[0], &sizearray[1], &c) != 3 || c != '\n';
        fflush(stdin);
        inputinvalid |= sizearray[0] < 1;
        inputinvalid |= sizearray[1] < 1;
        if (inputinvalid)
            printf("Eingabe ungueltig.\n");
    } while (inputinvalid);
}

void getMatrixValues(double matrix[], int size[2])
{
    for (int i = 0; i < size[0]; i++)
        for (int j = 0; j < size[1]; j++)
        {
            int inputinvalid;
            double element;
            char c;
            do
            {
                printf("Element %d,%d: ", i + 1, j + 1);
                inputinvalid = scanf("%lf%c", &element, &c) != 2 || c != '\n';
                fflush(stdin);
            } while (inputinvalid);
            matrix[i * size[1] + j] = element;
        }
}

void printmatrix(double matrix[], int size[2])
{
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
            printf("%8.2f", matrix[i * size[1] + j]);
        printf("\n");
    }
}

void matrixmultiplication(double a[], int sa[2], double b[], int sb[2], double c[])
{
    int rowA, colA, rowB, rs = sa[0] * sb[1];
    int ressize[2] = { sa[0], sb[1] };

    for (rowA = 0; rowA < rs; rowA++)
        c[rowA] = 0;

    // Zeilen Matrix A
    for (rowA = 0; rowA < sa[0]; rowA++)
        // Zeilen Matrix B
        for (rowB = 0; rowB < sb[1]; rowB++)
            // Spalten Matrix A = Zeilen Matrix B
            for (colA = 0; colA < sb[0]; colA++)
                c[rowA * ressize[1] + rowB] += a[rowA * sa[1] + colA] * b[colA * sb[1] + rowB];
}