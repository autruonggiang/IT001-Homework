#include<iostream>
#include<stdio.h>
#include<conio.h>
#define MAX 100
using namespace std;
void nhap(float a[], int& n)
{
    do
    {
        cout << "Nhap so phan tu: ";
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

int timvitrinhonhat(float a[], int n)
{
    int vtnn = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[vtnn])
        {
            vtnn = i;
        }
    }
    return vtnn;
}
int main()
{
    int n;
    float a[MAX];
    nhap(a, n);
    xuat(a, n);

    int vtnn = timvitrinhonhat(a, n);
    cout << endl;
    cout << "Vi tri chua phan tu nho nhat la: " << vtnn;
    return 0;
}