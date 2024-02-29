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
        cout << "Nhap so phan tu: ";
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "So phan tu khong hop le.Xin kiem tra lai !";
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

void HoanVi(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void SapXepTangDan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                HoanVi(a[i], a[j]);
            }
        }
    }
}

void KiemTraBCoPhaiLaHoanViCuaA(int a[], int b[], int na, int nb)
{
    if (na != nb)
    {
        cout << "Khong phai hoan vi";      
        return;
    }
    SapXepTangDan(a, na);           
    SapXepTangDan(b, nb);           
    for (int i = 0; i < na; i++)
    {
        if (a[i] != b[i])
        {
            cout << "Khong phai hoan vi";
            return;
        }
    }
    cout << "b la hoan vi cua a ";
    return;
}
int main()
{
    int na, nb;
    int a[MAX], b[MAX];

    nhap(a, na);
    xuat(a, na);
    cout << endl;
    nhap(b, nb);
    xuat(b, nb);
    cout << endl;
    KiemTraBCoPhaiLaHoanViCuaA(a, b, na, nb);
    return 0;
}