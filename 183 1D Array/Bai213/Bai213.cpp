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

float TinhTBCongCacSoLonHonX (float a[], int n, int x)
{
    int Tong = 0;
    float dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            Tong += a[i];
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "\nMang khong co so thoa yeu cau !";
        return 0;
    }
    return Tong/dem;
}

int main()
{
    int n;
    float a[MAX];
    int x;

    NhapMang (a, n);
    XuatMang (a, n);

    cout << "\nNhap x: ";
    cin >> x;
    float TBC = TinhTBCongCacSoLonHonX (a, n, x);
    cout << "\nTrung binh cong cac so duong = " << TBC;

    return 0;
}
