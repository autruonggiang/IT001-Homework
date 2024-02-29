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
int KiemTraToanLe(int n)
{
    int dv;
    while (n != 0)
    {
        dv = n % 10;
        if (dv % 2 == 0)
            return 0;
        n = n / 10;
    }
    return 1;
}

void LietKeSoToanChuSoLe(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (KiemTraToanLe(a[i]) == 1)
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    cout << "Cac so toan chu so le la : ";
    LietKeSoToanChuSoLe(a, n);
    return 0;
}