#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;

void nhap(int a[], int& n)
{
    do
    {
        cout << "Nhap so phan tu : ";
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "So phan tu khong hop le.Xin kiem tra lai !";
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}
void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int SoGanh(int x)
{
    int SoDao = 0;
    int themang = x;
    while (themang != 0)
    {
        SoDao = SoDao * 10 + themang % 10;
        themang /= 10;
    }
    if (x == SoDao)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TimSoGanhDauTien(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (SoGanh(a[i]) == 1)
        {
            return a[i];
        }
    }
    return -1;
}

int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);

    int GanhDau = TimSoGanhDauTien(a, n);
    cout << "So ganh dau tien la : " << GanhDau;
    return 0;
}
