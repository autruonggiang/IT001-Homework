#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;
void nhap(int a[], int& n)
{
    srand(time(NULL));

    cout << "Nhap so phan tu: ";
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - (-100) + 1) + (-100);
    }
}


void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int TinhTongCacPhanTuCucTri(int a[], int n)
{
    int Tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && a[i] != a[i + 1])   
        {
            Tong += a[i];
        }
        else if (i == n - 1 && a[i] != a[i - 1])  
        {
            Tong += a[i];
        }
        else if ((a[i] < a[i + 1] && a[i] < a[i - 1]) || (a[i] > a[i + 1] && a[i] > a[i - 1]))
        {
            Tong += a[i];
        }
    }
    return Tong;
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int Tong = TinhTongCacPhanTuCucTri(a, n);
    cout << "Tong = " << Tong;
    return 0;
}