#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
using namespace std;
void nhap(int a[], int& n)
{
    do
    {
        cout << "Nhap so phan tu : ";
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "So phan tu khong hop le. Xin kiem tra lai !";
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
bool KiemTraNguyenTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i <= sqrt((float)n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int TimSoNguyenToDau(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (KiemTraNguyenTo(a[i]) == true)
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
    int nguyentodau = TimSoNguyenToDau(a, n);
    cout << "So nguyen to dau tien la: " <<  nguyentodau;
    return 0;
}