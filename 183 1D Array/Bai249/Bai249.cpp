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
        cout << "Nhap vao a[" << i << "]: ";
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
int KiemTraGiamDan(int a[], int n)
{
    int flag = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main()
{
    int n;
    int a[MAX];
    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int flag = KiemTraGiamDan(a, n);
    if (flag == 1)
    {
        cout << "Mang giam dan";
    }
    else
    {
        cout << "Khong thoa DK";
    }
    return 0;
}