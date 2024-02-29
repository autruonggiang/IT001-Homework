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

double TinhKgCachTBGiuaCacGiaTriTrongMang (float a[], int n)
{
    int Tong = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Tong += abs(a[i] - a[i + 1]);
            y++;
        }
    }
    return pow (Tong, 1.0/y);
}

int main()
{
    int n;
    float a[MAX];
    int x;

    NhapMang (a, n);
    XuatMang (a, n);

    float KgCach = TinhKgCachTBGiuaCacGiaTriTrongMang (a, n);
    cout << "\nKhoang cach trung binh giua cac gia tri trong mang = " << KgCach;

    return 0;
}
