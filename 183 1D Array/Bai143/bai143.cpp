#include<iostream>
#include<stdio.h>
#include<conio.h>
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

int timchandau(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
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
    int chandau = timchandau(a, n);
    cout << "Gia tri chan dau la " << chandau;
    return 0;
}