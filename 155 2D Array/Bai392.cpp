#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <memory.h>
#define N 100
#define M 100

void NhapMang(int[][M], int, int, char*);
void XuatMang(int[][M], int, int, char);
void Hoandong(int[][M], int, int, int, int);


void main()
{
    int aRow, aCol;
    int A[N][M];
    int row1, row2;

    printf("\nNumber of row: ");
    scanf("%d", &aRow);
    printf("\nNumber of column: ");
    scanf("%d", &aCol);

    NhapMang(A, aRow, aCol, "A");
    XuatMang(A, aRow, aCol, 'A');

    printf("\nNumber of row1 (0 ~ %d): ", aRow - 1);
    scanf("%d", &row1);
    printf("\nNumber of row2 (0 ~ %d): ", aRow - 1);
    scanf("%d", &row2);

    Hoandong(A, aRow, aCol, row1, row2);

    printf("\nPermuted matrix\n");
    XuatMang(A, aRow, aCol, 'P');

    getch();
}
void Hoandong(int A[][M], int aRow, int aCol, int row1, int row2)
{
    int iARow, iACol;
    int tmp;

    if (row1 < 0 || row1 >= aRow ||
        row2 < 0 || row2 >= aRow ||
        row1 == row2)
    {
        return;
    }
    for (iACol = 0; iACol < aCol; iACol++)
    {
        tmp = A[row1][iACol];
        A[row1][iACol] = A[row2][iACol];
        A[row2][iACol] = tmp;
    }
}
void NhapMang(int Matrix[][M], int nRow, int nCol, char* nameMatrix)
{
    int iRow, iCol;
    for (iRow = 0; iRow < nRow; iRow++)
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\n%s[%d][%d] = ", nameMatrix, iRow, iCol);
            scanf("%d", &Matrix[iRow][iCol]);
        }
}
void XuatMang(int Matrix[][M], int nRow, int nCol, char name)
{
    int iRow, iCol;
    printf("\n%c = ", name);
    for (iRow = 0; iRow < nRow; iRow++)
    {
        printf("\n");
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\t%d\t", Matrix[iRow][iCol]);
        }
    }
}