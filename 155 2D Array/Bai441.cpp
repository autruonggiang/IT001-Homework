#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
using namespace std;
void NhapMaTran(int a[][MAX], int& n)
{
    do
    {
        cout << "\nNhap n: ";
        cin >> n;
        if (n < 1 || n > MAX)
        {
            cout << "\nSo phan tu khong hop le. Xin kiem tra lai !";
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
        cout << ("\n\n");
    }
}

int TinhTongCacPhanTuTrenDuongCheoPhu(int a[][MAX], int n)
{
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i][n - 1 - i];
    }
    return S;
}
int main()
{
    int a[MAX][MAX], n;
    NhapMaTran(a, n);
    XuatMaTran(a, n);

    int tong = TinhTongCacPhanTuTrenDuongCheoPhu(a, n);
   cout << "\nTong cac phan tu tren duong cheo phu = " << tong;
    return 0;
}