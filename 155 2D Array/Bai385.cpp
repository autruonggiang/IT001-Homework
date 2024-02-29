#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <memory.h>
#define N 100
#define M 100
void Nhapmang(int[][M], int, int, char*);
void Xuatmang(int[][M], int, int, char);
int* Hanglonnhat(int[][M], int, int, int*);



void main()
{
    int Hang, Cot;
    int A[N][M];
    int* res;
    int sz = 0;
    int idx;

    printf("\nSo Hang: ");
    scanf("%d", &Hang);
    printf("\nSo Cot: ");
    scanf("%d", &Cot);

    Nhapmang(A, Hang, Cot, "A");
    Xuatmang(A, Hang, Cot, 'A');

    res = Hanglonnhat(A, Hang, Cot, &sz);

    printf("\nNhung Hang lon nhat la: \n");
    for (idx = 0; idx < sz; idx++)
    {
        printf("Hang: %d\n", res[idx] + 1);
    }

    getch();
}
int* Hanglonnhat(int A[][M], int Hang, int Cot, int* sz)
{
    int iHang, iCot;
    int cnt = 0;
    int idx = 0;
    int max;
    int* sum;
    int* max_arr;

    sum = (int*)malloc(Hang * sizeof(int));
    if (!sum)
    {
        printf("Khong chay duoc");
        return NULL;
    }
    memset(sum, 0x00, Hang * sizeof(int));

    for (iHang = 0; iHang < Cot; iHang++)
    {
        for (iCot = 0; iCot < Cot; iCot++)
        {
            *(sum + iHang) += A[iHang][iCot];
        }
    }

    max = sum[0];
    for (idx = 1; idx < Hang; idx++)
    {
        if (max < sum[idx])
        {
            max = sum[idx];
        }
    }

    for (idx = 0; idx < Hang; idx++)
    {
        if (max == sum[idx])
        {
            cnt++;
        }
    }

    *sz = cnt;

    max_arr = (int*)malloc((*sz) * sizeof(int));
    if (!max_arr)
    {
        printf("Khong chay duoc");
        return NULL;
    }
    memset(max_arr, 0x00, (*sz) * sizeof(int));

    cnt = 0;
    for (idx = 0; idx < Hang; idx++)
    {
        if (max == sum[idx])
        {
            max_arr[cnt++] = idx;
        }
    }

    free(sum);

    return max_arr;

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
