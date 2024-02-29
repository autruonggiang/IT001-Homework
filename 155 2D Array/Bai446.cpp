#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100

using namespace std;

void NhapMaTran(int a[][MAX], int &n)
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
            cout << "\nNhap vao a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n\n";
    }
}

int TimGiaTriLonNhatTrenDuongCheoPhu(int a[][MAX], int n)
{
    int Max = a[0][n - 1];
    for (int i = 0; i < n; i++)
    {
        Max = (a[i][n - 1 - i] > Max) ? a[i][n - 1 - i] : Max;
    }
    return Max;
}

int main()
{
    int a[MAX][MAX], n;
    NhapMaTran(a,n);
    XuatMaTran(a,n);

    int Max = TimGiaTriLonNhatTrenDuongCheoPhu(a, n);
    cout << "\nGia tri lon nhat tren duong cheo phu = " << Max;

    return 0;
}
