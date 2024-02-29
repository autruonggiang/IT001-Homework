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

int timvitrichandau(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            return i;
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
    int vitrichandau = timvitrichandau(a, n);
    cout << "Vi tri chan dau la: " << vitrichandau;
    return 0;
}