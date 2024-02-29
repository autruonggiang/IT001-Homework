#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 100
#define M 100

void ImportData(float[][M], int, int, char*);
void PrintMatrix(float[][M], int, int);
float SumRowInMatrix(float[][M], int, int, int);
void main()
{
    int nRow, nCol;
    int iRow;
    float A[N][M];

    printf("\nNumber of row: ");
    scanf("%d", &nRow);
    printf("\nNumber of column: ");
    scanf("%d", &nCol);
    do
    {
        printf("\nNumber of specified row: ");
        scanf("%d", &iRow);
    } while (iRow <= 0 || iRow > nRow);


    ImportData(A, nRow, nCol, "A");
    PrintMatrix(A, nRow, nCol);

    printf("\nSum all of elements in row (%d) matrix: %f",
        iRow,
        SumRowInMatrix(A, nRow, nCol, iRow));

    getch();
}

float SumRowInMatrix(float A[][M], int nRow, int nCol, int specRow)
{
    int iRow, iCol;
    float sum = 0;
    for (iRow = 0; iRow < nRow; iRow++)
    {
        for (iCol = 0; iCol < nCol; iCol++)
        {
            if ((iRow + 1) == specRow)
                sum += A[iRow][iCol];
        }
    }
    return sum;
}

void ImportData(float Matrix[][M], int nRow, int nCol, char* nameMatrix)
{
    int iRow, iCol;
    for (iRow = 0; iRow < nRow; iRow++)
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\n%s[%d][%d] = ", nameMatrix, iRow, iCol);
            scanf("%f", &Matrix[iRow][iCol]);
        }
}

void PrintMatrix(float Matrix[][M], int nRow, int nCol)
{
    int iRow, iCol;
    printf("\nA = ");
    for (iRow = 0; iRow < nRow; iRow++)
    {
        printf("\n");
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\t%.2f\t", Matrix[iRow][iCol]);
        }
    }
}