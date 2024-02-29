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
int DemSoLuongPhanTuKeNhauMaCa2TraiDau(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] * a[i + 1] < 0)
        {
            dem++;
        }
    }
    if (dem != 0)
    {
        dem++;
    }
    return dem;
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int dem = DemSoLuongPhanTuKeNhauMaCa2TraiDau(a, n);
    cout << "So luong phan tu ke nhau ma ca 2 trai dau = " << dem;
    return 0;
}