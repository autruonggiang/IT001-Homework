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
int DemSoPhanTuKeNhauThoaDK(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] * a[i - 1] > 0 && abs(a[i - 1]) < abs(a[i]))
        {
            dem++;
        }
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
    int dem = DemSoPhanTuKeNhauThoaDK(a, n);
    cout << "So luong phan tu ke nhau ma so dung sau cung dau so dung truoc va co tri tuyet doi lon hon = " << dem;
    return 0;
}