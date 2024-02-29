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

void HoanVi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void HoanVi2Dong(int a[][MAX], int n, int dong1, int dong2)
{
    if((dong1 >= 0 && dong1 < n) && (dong2 >= 0 && dong2 < n))
    {
        for(int j = 0; j < n; j++)
        {
            HoanVi(a[dong1][j], a[dong2][j]);
        }
    }
}

int main()
{
    int a[MAX][MAX], n, dong1, dong2;
    NhapMaTran(a,n);
    XuatMaTran(a,n);
    do
    {
        cout << "\nNhap dong 1: 1+";
        cin >> dong1;

        if (dong1 < 0 || dong1 >= n)
        {
            cout << "\nDong khong hop le. Xin nhap lai !";
        }
    } while (dong1 < 0 || dong1 >= n);

    do
    {
        cout << "\nNhap dong 2: 1+";
        cin >> dong2;

        if (dong2 < 0 || dong2 >= n)
        {
            cout << "\nDong khong hop le. Xin nhap lai !";
        }
    } while (dong2 < 0 || dong2 >= n);

    HoanVi2Dong(a, n, dong1, dong2);

    cout << "\nMa tran sau khi hoan vi dong " << dong1 + 1 << " va dong " << dong2 + 1 << " \n";
    XuatMaTran(a, n);

    return 0;
}
