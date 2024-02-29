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

int KiemTraNguyenTo (int n)
{
    if (n < 2)
    {
        return 0;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return 0;
        }
        for (int i = 3; i <= sqrt((float)n); i+= 2)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void HoanVi (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SapXepNguyenToTangDan (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (KiemTraNguyenTo(a[i]) == 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (KiemTraNguyenTo(a[j]) == 1 && a[i] > a[j])
                {
                    HoanVi (a[i], a[j]);
                }
            }

        }
    }
}

int main()
{
    int n;
    int a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    SapXepNguyenToTangDan (a, n);
    cout << "\nMang sau khi sap xep nguyen to tang dan: ";
    XuatMang (a, n);

    return 0;
}
