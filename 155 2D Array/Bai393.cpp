#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <memory.h>
#define N 100
#define M 100

void NhapMang(int[][M], int, int, char*);
void XuatMang(int[][M], int, int, char);
void Hoancot(int[][M], int, int, int, int);


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

    Hoancot(A, aRow, aCol, row1, row2);

    printf("\nPermuted matrix\n");
    XuatMang(A, aRow, aCol, 'P');

    getch();
}
void Hoancot(int A[][M], int aRow, int aCol, int col1, int col2)
{
    int iARow, iACol;
    int tmp;

    if (col1 < 0 || col1 >= aCol ||
        col2 < 0 || col2 >= aCol ||
        col1 == col2)
    {
        return;
    }
    for (iARow = 0; iARow < aRow; iARow++)
    {
        tmp = A[iARow][col1];
        A[iARow][col1] = A[iARow][col2];
        A[iARow][col2] = tmp;
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