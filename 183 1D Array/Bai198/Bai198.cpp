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

float TimMax (float a[], int n)
{
    float max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void LietKeViTriLonNhat (float a[], int n)
{
    float max = TimMax(a, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == max)
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
    cout << "\nVi tri ma gia tri tai do lon nhat la: ";
    LietKeViTriLonNhat (a, n);

    return 0;
}
