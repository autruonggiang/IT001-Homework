#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100

void NhapMang(int a[][MAX], int &dong, int &cot)
{
    do
    {
        printf("\nNhap vao so dong: ");
        scanf("%d",&dong);

        if(dong < 1 || dong > MAX)
        {
            printf("\nSo dong khong hop le. Xin kiem tra lai !");
        }

    }while(dong < 1 || dong > MAX);

    do
    {
        printf("\nNhap vao so cot: ");
        scanf("%d",&cot);

        if(cot < 1 || cot > MAX)
        {
            printf("\nSo cot khong hop le. Xin kiem tra lai !");

        }

    }while(cot < 1 || cot > MAX);
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            printf("\nNhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void XuatMang(int a[][MAX], int dong, int cot)
{
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n\n");
    }
}

int TimMaxTrongMaTran(int a[][MAX], int dong, int cot) 
{ 
    int Max = a[0][0]; 
    for (int i = 0; i < dong; i++) 
    { 
        for(int j = 0; j < cot; j++) 
        { 
            Max = (a[i][j] > Max) ? a[i][j] : Max; 
        } 
    } 
    return Max; 
} 

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    int max = TimMaxTrongMaTran(a, dong, cot);
    printf("\nPhan tu lon nhat trong ma tran = %d", max);
    getch();
    return 0;
}
