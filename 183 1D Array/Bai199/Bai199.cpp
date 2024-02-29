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

bool KiemTraNguyenTo (int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i <= sqrt((float)n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void LietKeViTriNguyenTo (int a[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (KiemTraNguyenTo(a[i]) == true)
        {
            flag = 1;
            cout << i + 1 << " ";
        }
    }
    if (flag == 0)
    {
        cout << "\nKhong co so nguyen to !";
    }
}

int main()
{
    int n;
    int a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);
    cout << "\nVi tri cac so nguyen to la: ";
    LietKeViTriNguyenTo (a, n);

    return 0;
}
