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

void HoanVi2Cot(int a[][MAX], int n, int cot1, int cot2)
{
    if ((cot1 >= 0 && cot1 < n) && (cot2 >= 0 && cot2 < n))
    {
        for (int i = 0; i < n; i++)
        {
            HoanVi(a[i][cot1], a[i][cot2]);
        }
    }
}

int main()
{
    int a[MAX][MAX], n, cot1, cot2;
    NhapMaTran(a,n);
    XuatMaTran(a,n);
    do
    {
        cout << "\nNhap cot 1: 1+";
        cin >> cot1;

        if (cot1 < 0 || cot1 >= n)
        {
            cout << "\nCot khong hop le. Xin nhap lai !";
        }
    } while (cot1 < 0 || cot1 >= n);

    do
    {
        cout << "\nNhap cot 2: 1+";
        cin >> cot2;

        if(cot2 < 0 || cot2 >= n)
        {
            cout << "\nCot khong hop le. Xin nhap lai !";
        }
    } while (cot2 < 0 || cot2 >= n);

    HoanVi2Cot(a, n, cot1, cot2);

    cout << "\nMa tran sau khi hoan vi cot " << cot1 + 1 << " va cot " << cot2 + 1 << " \n";
    XuatMaTran(a, n);

    return 0;
}
