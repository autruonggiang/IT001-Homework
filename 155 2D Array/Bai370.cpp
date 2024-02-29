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
        	cout << "\nSo cot khong hop le. Xin kiem tra lai!";

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

int TimAmDauTien(int a[][MAX], int dong, int cot) 
{ 
    for (int i = 0; i < dong; i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            if (a[i][j] < 0) 
            { 
                return a[i][j]; 
            } 
        } 
    } 
    return 0; 
} 
int TimGiaTriAmLonNhat(int a[][100], int cot, int dong) 
{ 
    int AmMax = TimAmDauTien(a, cot, dong); 
    if (AmMax == 0) 
    { 
        return 0; 
    } 
    for (int i = 0; i < dong;i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            if (a[i][j] < 0) 
            { 
                AmMax = (AmMax > a[i][j]) ? AmMax : a[i][j]; 
            } 
        } 
    } 
    return AmMax; 
} 
int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    int AmMax = TimGiaTriAmLonNhat(a, dong, cot);
    
    cout << "\nGia tri am lon nhat trong ma tran = " << AmMax;
    
    return 0;
}
