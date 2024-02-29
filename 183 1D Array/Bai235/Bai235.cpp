#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;
void NhapMang(int a[], int& n)
{
    do
    {
        cout << ("\nNhap so phan tu: ");
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << ("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i <<"]: ";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void LietKePhanTuXuatHien1Trong2Mang(int a[], int b[], int na, int nb)
{
    int i, j, flag;
    for (i = 0; i < na; i++)
    {
        flag = 1;
        for (j = 0; j < nb; j++)
        {
            if (a[i] == b[j])
            {
                flag = 0;
               
                break;
            }
        }
        if (flag == 1)
            cout << a[i] << " ";
    }
    for (i = 0; i < nb; i++)
    {
        flag = 1;
        for (j = 0; j < na; j++)
        {
            if (b[i] == a[j])
            {
                flag = 0;
                
                break;
            }
        }
        if (flag == 1)
            cout << b[i] << " ";
    }
}
int main()
{
    int na, nb;
    int a[MAX], b[MAX];

    cout << "Nhap mang a : ";
    NhapMang(a, na);
    XuatMang(a, na);
    cout << endl;
    cout << "Nhap mang b : ";
    NhapMang(b, nb);
    XuatMang(b, nb);
    cout << endl;
    cout << ("\nCac phan tu xuat hien 1 trong 2 mang: ");
    LietKePhanTuXuatHien1Trong2Mang(a, b, na, nb);
    return 0;
}