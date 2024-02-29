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
int DemPhanTuChiXuatHien1Trong2Mang(int a[], int b[], int na, int nb)
{
    int flag, dem = 0;
    for (int i = 0; i < na; i++)
    {
        flag = 1;
        for (int j = 0; j < nb; j++)
        {
            if (a[i] == b[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            dem++;
        }
    }
    for (int i = 0; i < nb; i++)
    {
        flag = 1;
        for (int j = 0; j < na; j++)
        {
            if (b[j] == a[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            dem++;
        }
    }
    return dem;
}
int main()
{
    int na, nb;
    int a[MAX], b[MAX];

    cout << "Nhap mang a : ";
    nhap(a, na);
    xuat(a, na);
    cout << endl;
    cout << "Nhap mang b : ";
    nhap(b, nb);
    xuat(b, nb);
    cout << endl;
    int dem = DemPhanTuChiXuatHien1Trong2Mang(a, b, na, nb);
    cout << "So phan tu chi xuat hien 1 trong 2 mang la : " << dem;
    return 0;
}