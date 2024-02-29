#include<iostream>
#include<stdio.h>
#include<conio.h>
#define MAX 100
using namespace std;
void nhap(float a[], int& n)
{
    do
    {
        cout << "Nhap so phan tu : ";
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "So phan tu khong hop le.Xin kiem tra lai !";
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}

void xuat(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
float nhonhat(float a[], int n)
{
    float min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
int main()
{
    int n;
    float a[MAX];
    nhap(a, n);
    xuat(a, n);
    cout << endl;
    float min = nhonhat(a, n);
    
    cout << "Phan tu nho nhat trong mang la " << min;
    return 0;
}