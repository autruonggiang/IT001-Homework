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

void SapXepCheoPhuGiamDan(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int max = a[i][n - 1 - i];
            if (a[j][j - 1 - i] > max)
            {
                max = a[j][n - 1 - j];
                a[j][n - 1 - j] = a[i][n - 1 - i];
                a[i][n - 1 - i] = max;  
            }
        }
    }
}

int main()
{
    int a[MAX][MAX], n;
    NhapMaTran(a,n);
    XuatMaTran(a,n);
    SapXepCheoPhuGiamDan(a, n);
    cout << "\nSap xep duong cheo phu giam dan: \n";
    XuatMaTran(a, n);

    return 0;
}
