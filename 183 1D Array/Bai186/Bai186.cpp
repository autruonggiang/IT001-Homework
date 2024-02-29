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

float TimAmDau (float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            return a[i];
        }
    }
    return -1;
}

void LietKeViTriBangGiaTriAmDau (float a[], int n)
{
    float AmDau = TimAmDau(a, n);
    for(int i = 0; i < n; i++)
    {
        if(a[i] == AmDau)
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
    cout << "\nVi tri ma gia tri tai do bang gia tri am dau: ";
    LietKeViTriBangGiaTriAmDau (a, n);

    return 0;
}

