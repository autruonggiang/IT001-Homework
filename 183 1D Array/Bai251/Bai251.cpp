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
            cout << ("So phan tu khong hop le. Xin kiem tra lai !");
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
int KiemTraBangNhau(int a[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    int n, d;
    int a[MAX];
    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int flag = KiemTraBangNhau(a, n);
    if (flag == 1)
    {
        cout << "Cac phan tu trong mang bang nhau";
    }
    else
    {
        cout <<" cac phan tu trong mang khong bang nhau";
    }
    return 0;
}