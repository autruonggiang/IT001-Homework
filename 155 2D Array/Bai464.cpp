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

void TinhTongCacDong(int a[][MAX], int n, int b[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i] += a[i][j];
        }
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
    if ((dong1 >= 0 && dong1 < n) && (dong2 >= 0 && dong2 < n))
    {
        for (int j = 0; j < n; j++)
        {
            HoanVi(a[dong1][j], a[dong2][j]);
        }
    }
}

void SapXepCacDongDuaVaoTongCacPhanTuTrong1Dong(int a[][MAX], int n)
{
    int b[MAX] = {0};
    TinhTongCacDong(a, n, b);
    for (int i = 0; i < n - 1; i++)  
    {   
        for (int j = i + 1; j < n; j++)   
        {    
            if (b[i] > b[j])    
            {
                HoanVi2Dong(a, n, i, j);
                HoanVi(b[i], b[j]);
            }
        }
    }
}
int main()
{
    int a[MAX][MAX], n, dong1, dong2;
    NhapMaTran(a,n);
    XuatMaTran(a,n);
    SapXepCacDongDuaVaoTongCacPhanTuTrong1Dong(a, n);
    cout << "\nMa tran sau khi sap xep: \n";
    XuatMaTran(a,n);

    return 0;
}
