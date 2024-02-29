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
        a[i] = rand() % 300 + 1;
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int TimViTriLeDauTien(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            return i;
        }
    }
    return -1;
}
int TimSoLeNhoNhat(int a[], int n, int ViTriDauTien)
{
    int MinLe = a[ViTriDauTien];

    for (int i = ViTriDauTien + 1; i < n; i++)
    {
        if (a[i] % 2 != 0 && a[i] < MinLe)
        {
            MinLe = a[i];
        }
    }
    return MinLe;
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);

    int ViTriLeDauTien = TimViTriLeDauTien(a, n);
    if (ViTriLeDauTien == -1)
    {
        printf("\nMang khong ton tai so le");
    }
    else
    {
        int MinLe = TimSoLeNhoNhat(a, n, ViTriLeDauTien);
        int SoChanThoa = MinLe - 1;
        cout << endl;
        cout << "lon nhat nho hon toan bo gia tri le trong mang la " << SoChanThoa;
    }
    return 0;
}