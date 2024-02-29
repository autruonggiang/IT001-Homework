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
        a[i] = rand() % 300+1;
    }
}


void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int DemSoLuongPhanTuKeNhauMaCa2DeuChan(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i + 1] % 2 == 0)
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
    int dem = DemSoLuongPhanTuKeNhauMaCa2DeuChan(a, n);
    cout << "So luong phan tu ke nhau ma ca 2 deu chan = " << dem;
    return 0;
}