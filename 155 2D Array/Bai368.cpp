#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

using namespace std;

void NhapMang(int a[][MAX], int &dong, int &cot)
{
    do
    {
        cout << "\nNhap vao so dong: ";
        cin >> dong;

        if (dong < 1 || dong > MAX)
        {
            cout << "\nSo dong khong hop le. Xin kiem tra lai !";
        }

    } while (dong < 1 || dong > MAX);

    do
    {
        cout << "\nNhap vao so cot: ";
        cin >> cot;

        if (cot < 1 || cot > MAX)
        {
            cout << "\nSo cot khong hop le. Xin kiem tra lai !";

        }

    } while (cot < 1 || cot > MAX);
    
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "\nNhap a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMang(int a[][MAX], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n\n";
    }
}

int TimMaxThu2TrongMaTran(int a[][MAX], int dong, int cot) 
{ 
    int Max = a[0][0]; 
    for (int i = 0; i < dong; i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            Max = (a[i][j] > Max) ? a[i][j] : Max; 
        } 
    } 
    int Max2 = a[0][0]; 
    for (int i = 0; i < dong; i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            if (Max2 < Max && a[i][j]!= Max && Max2 < a[i][j]) 
            { 
                Max2 = a[i][j]; 
            } 
        } 
    } 
    return Max2; 
} 

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    int max = TimMaxThu2TrongMaTran(a, dong, cot);
    cout << "\nPhan tu lon thu 2 trong ma tran = " << max;

    return 0;
}
