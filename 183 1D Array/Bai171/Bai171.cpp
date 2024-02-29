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

int TimSoNhoNhat (int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];  
        }
    }
    return min;
}

bool KiemTraUocSoChung (int a[], int n, int UocSo)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % UocSo != 0)
        {
            return false;
        }
    }
    return true;
}

int TimUocSoLonNhatCuaMang(int a[], int n)
{
    for (int UocSo = TimSoNhoNhat(a, n); UocSo >= 1; UocSo--)  
    {
        if (KiemTraUocSoChung(a, n, UocSo) == true)
        {
            return UocSo;
        }
    }
    return 1;
}

int main()
{
    int n;
    int a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    int Kq = TimUocSoLonNhatCuaMang (a, n);
    cout << "\nUoc So chung lon nhat cua mang la: " << Kq;

    return 0;
}
