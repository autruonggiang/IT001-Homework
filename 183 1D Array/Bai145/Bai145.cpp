#include<iostream>
#include<stdio.h>
#include<conio.h>
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
        a[i] = rand() % 100 + 1;
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

bool kiemtrahoanthien(int n)
{
    int i = 1;
    int S = 0;
    while (i < n)
    {
        if (n % i == 0)
        {
            S = S + i;
        }
        i++;
    }
    if (S == n)
        return true;
    else
        return false;
}

int timsohoanthiendau(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (kiemtrahoanthien(a[i]) == true)
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
    cout << endl;
    int sohoanthiendau = timsohoanthiendau(a, n);
    cout << "So hoan thien dau la " << sohoanthiendau;
    return 0;
}