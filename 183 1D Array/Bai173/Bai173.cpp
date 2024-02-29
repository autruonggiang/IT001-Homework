#include <iostream>
#include <math.h>
#define MAX 100

using namespace std;

void NhapMang (int a[], int &n)
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

void XuatMang (int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void DemChuSo (int a[], int n, int b[])
{
    for (int i = 0; i < n; i++)
    {
        int themang = abs(a[i]);
        while (themang != 0)
        {
            int ChuSo = themang % 10;
            themang /= 10;

            b[ChuSo]++;
        }
    }
}

int TimChuSoXuatItNhat (int a[], int n, int b[])
{
    int ChuSoMin = abs(a[0] % 10);
    for (int i = 0; i < 10 ; i++)
    {
        if (b[i] != 0)
        {
            ChuSoMin = (b[ChuSoMin] < b[i]) ? ChuSoMin : i;
        }
    }
    return ChuSoMin;
 }

int main()
{
    int n;
    int a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    int b[10] = {0};
    DemChuSo (a, n, b);
    for (int i = 0; i < 10; i++)
    {
        if (b[i] != 0)
        {
            cout << "\nChu so " << i << " xuat hien " << b[i] << " lan.";

        }
    }

    int ChuSoMin = TimChuSoXuatItNhat (a, n, b);
        cout << "\nChu so xuat hien it nhat la: " << ChuSoMin;

    return 0;
}
