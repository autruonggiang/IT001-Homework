#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

void nhap(int a[][50], int& n, int& m)
{
    cout << "nhap so dong: ";
    cin >> n;
    cout << "nhap so cot: ";
    cin >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "phan tu thu a[" << i << "]" << "[" << j << "]: ";
            cin >> a[i][j];
        }
}

void xuat(int a[][50], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void KiemTraDongTang(int a[][50], int n, int m)
{
    int co = 0, i;
    cout << "vui long nhap dong: ";
    cin >> i;
    for (int j = 0; j < m - 1; j++)
    {
        if (a[i][j] > a[i][j + 1]) {
            co = 1;
            break;
        }
    }
    if (co == 1) cout << "dong khong tang";
    else cout << "dong tang ";
}

int main()
{
    int a[50][50], n, m;
    nhap(a, n, m);
    xuat(a, n, m);
    KiemTraDongTang(a, n, m);
    return 0;
}