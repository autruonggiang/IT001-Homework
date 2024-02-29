#include <iostream>
#include <math.h>
#define MAX 100

using namespace std;

void NhapMang (float a[], int &n)
{
    do
    {
        cout << "\nNhap so phan tu: ";
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "\nSo phan tu khong hop le. Hay kiem tra lai !";
        }
    } while (n <= 0 || n > MAX);
    
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap a[" << i + 1 << "]: ";
        cin >> a[i];
    }
}

void XuatMang (float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

float TimDuongDauTien (float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
         if (a[i] > 0)
         {
             return a[i];
         }
    }
    return -1;
}

float TimDuongNhoNhat (float a[], int n)
{
    float duongnhonhat = TimDuongDauTien (a, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] < duongnhonhat)
        {
            duongnhonhat = a[i];
        }
    }
    return duongnhonhat;
}

void LietKeViTriBgGiaTriDuongMin (float a[], int n)
{
    float DuongMin = TimDuongNhoNhat (a, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == DuongMin)
        {
            cout << i + 1 << " ";
        }
    }
}

int main()
{
    int n;
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    int vitriduongdau = TimDuongDauTien (a, n);
    if (vitriduongdau == -1)
    {
        cout << "\nMang khong co so duong !";
    }
    else
    {
    cout << "\nVi tri ma gia tri tai do bang gia tri duong nho nhat: ";
    LietKeViTriBgGiaTriDuongMin (a, n);
    }

    return 0;
}
