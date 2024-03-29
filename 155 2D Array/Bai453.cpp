﻿#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
using namespace std;
void NhapMaTran(int a[][MAX], int& n)
{
    do
    {
        cout << "Nhap n : ";
        cin >> n;
        if (n < 1 || n > MAX)
        {
            cout << "So phan tu khong hop le.Xin kiem tra lai !";
        }
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap vao a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
}

int DemSoLuongSoDuongTrenDuongCheoChinh(int a[][MAX], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] > 0)
        {
            dem++;
        }
    }
    return dem;
}
int main()
{
    int a[MAX][MAX], n;
    NhapMaTran(a, n);
    XuatMaTran(a, n);

    int dem = DemSoLuongSoDuongTrenDuongCheoChinh(a, n);
    cout << "So luong so duong tren duong cheo chinh = " << dem;
    return 0;
}