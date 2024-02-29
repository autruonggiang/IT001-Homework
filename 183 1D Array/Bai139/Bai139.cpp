#include<iostream>
#include<stdio.h>
#include<conio.h>
#define MAX 100
using namespace std;
void nhap(int a[], int& n)
{
    do
    {
        cout << "Nhap so phan tu: ";
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "So phan tu khong hop le.Xin kiem tra lai: ";
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
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

int timvitrihoanthiencuoi(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (kiemtrahoanthien(a[i]) == true)
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
    int vitrihoanthiencuoi = timvitrihoanthiencuoi(a, n);
    cout << "Vi tri hoan thien cuoi la " << vitrihoanthiencuoi;

    return 0;
}