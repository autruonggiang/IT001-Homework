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
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
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
        cout <<  a[i] << " ";
    }
}
int KiemTraNguyenTo(int x)   
{
    if (x < 2)
    {
        return 0;
    }
    else if (x > 2)
    {
        if (x % 2 == 0)
        {
            return 0;
        }
        for (int i = 3; i <= sqrt((float)x); i += 2)
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int KiemTraBiTrung(int a[], int n, int index)
{
    for (int i = index - 1; i >= 0; i--)
    {
        if (a[i] == a[index])
        {
            return 0; 
        }
    }
    return 1; 
}

int DemSoLuongSoNguyenToPhanBiet(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        int CheckTrung = KiemTraBiTrung(a, n, i);
        {
            if (CheckTrung == 1)  
            {
                if (KiemTraNguyenTo(a[i]) == 1)
                {
                    dem++;
                }
            }
        }
    }
    return dem;
}
int main()
{
    int n;
    int a[MAX];

    cout << "Nhap mang a: ";
    nhap(a, n);
    xuat(a, n);
    cout << endl;

    int dem = DemSoLuongSoNguyenToPhanBiet(a, n);
    cout << "So luong so nguyen to phan biet = " <<  dem;
    return 0;
}