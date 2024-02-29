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

int TinhTongCacPhanTuLonHon (float a[], int n)
{
    int Tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > abs(a[i + 1]))
        {
            Tong += a[i];
        }
    }
    return Tong;
}

int main()
{
    int n;
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);
    int tong = TinhTongCacPhanTuLonHon (a, n);
    cout << "\nTong bang: " << tong;

    return 0;
}
