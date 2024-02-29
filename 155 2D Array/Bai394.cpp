#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <memory.h>
#define N 100
#define M 100

void Nhapmang(int[][M], int, int, char*);
void Xuatmang(int[][M], int, int, char);
void Dichuyen(int[][M], int, int);


void main()
{
    int aHang, aCot;
    int A[N][M];
    int cot1, cot2;

    printf("\nSo Hang: ");
    scanf("%d", &aHang);
    printf("\nSo Cot: ");
    scanf("%d", &aCot);

    Nhapmang(A, aHang, aCot, "A");
    Xuatmang(A, aHang, aCot, 'A');

    Dichuyen(A, aHang, aCot);

    printf("\nMa tran chuyen dich\n");
    Xuatmang(A, aHang, aCot, 'P');

    getch();
}

void Dichuyen(int A[][M], int aHang, int aCot)
{
    int iAHang, iACot;
    int tmp;
    int* pTmp;
    pTmp = (int*)malloc(aCot * sizeof(int));
    if (!pTmp)
    {
        printf("Khong chay duoc\n");
        return;
    }
    memset(pTmp, NULL, aCot * sizeof(int));
    for (iACot = 0; iACot < aCot; iACot++)
    {
        pTmp[iACot] = A[aHang - 1][iACot];
    }
    for (iAHang = aHang - 1; iAHang > 0; iAHang--)
    {
        for (iACot = 0; iACot < aCot; iACot++)
        {
            A[iAHang][iACot] = A[iAHang - 1][iACot];
        }
    }
    for (iACot = 0; iACot < aCot; iACot++)
    {
        A[0][iACot] = pTmp[iACot];
    }
    free(pTmp);

}

void Nhapmang(int Matrix[][M], int nHang, int nCot, char* tenmatran)
{
    int iHang, iCot;
    for (iHang = 0; iHang < nHang; iHang++)
        for (iCot = 0; iCot < nCot; iCot++)
        {
            printf("\n%s[%d][%d] = ", tenmatran, iHang, iCot);
            scanf("%d", &Matrix[iHang][iCot]);
        }
}
void Xuatmang(int Matrix[][M], int nHang, int nCot, char ten)
{
    int iHang, iCot;
    printf("\n%c = ", ten);
    for (iHang = 0; iHang < nHang; iHang++)
    {
        printf("\n");
        for (iCot = 0; iCot < nCot; iCot++)
        {
            printf("\t%d\t", Matrix[iHang][iCot]);
        }
    }
}
