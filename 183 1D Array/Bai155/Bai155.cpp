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

void TaoMang (float a[], int n, float b[], int x)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = abs(x - a[i]);
    }
}

float TimMax (float b[], int n)
{
    int Max = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] > Max)
        {
            Max = b[i];
        }
    }
    return Max;
}

void XuatKetQua (float a[], float b[], int n)
{
    cout << "\nGia tri trong mang xa gia tri x nhat la: ";
    int Max = TimMax (b, n);
    for (int i = 0; i < n; i++)
    {
        if (b[i] == Max)    
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{
    int n;
    float a[MAX];
    float b[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    float x;
    cout << "\nNhap vao gia tri x: ";
    cin >> x;

    TaoMang (a, n, b, x);
    cout << "\nKhoang cach tu x = " << x << " den cac phan tu trong mang la:\n";
    XuatMang (b, n);
    XuatKetQua (a, b, n);

    return 0;
}
