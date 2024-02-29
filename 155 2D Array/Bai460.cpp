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

void SapXepCheoChinhTangDan(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int min = a[i][i];      
            if (a[j][j] < min)
            {
                min = a[j][j];
                a[j][j] = a[i][i];
                a[i][i] = min;  
            }
        }
    }
}

int main()
{
    int a[MAX][MAX], n;
    NhapMaTran(a,n);
    XuatMaTran(a,n);
    SapXepCheoChinhTangDan(a, n);
    cout << "\nSap xep duong cheo chinh tang dan: \n";
    XuatMaTran(a, n);

    return 0;
}
