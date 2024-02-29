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
int KiemTraCapSoCong(int a[], int n, int& d)
{
    d = a[1] - a[0];
    int flag = 1;
    for (int i = 2; i < n - 1; i++)
    {
        if ((a[i + 1] - a[i]) != d)
        {
            flag = 0;
            break;
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
    int flag = KiemTraCapSoCong(a, n, d);
    if (flag == 1)
    {
        cout << "Cac phan tu trong mang lap thanh cap so cong voi cong sai d = " << d;
    }
    else
    {
        cout << "Mang khong tao thanh cap so cong";
    }
    return 0;
}