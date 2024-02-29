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

float TimX (float a[], int n)
{
    float x = a[0];
    for (int i = 1; i < n; i++)
    {
         x = (x > (fabs)(a[i])) ?  x  :  (fabs)(a[i]);
    }
     return x;
}

int main()
{
    int n;
    float a[MAX];
    float b[MAX];

	NhapMang (a, n);
    XuatMang (a, n);
    float x = TimX (a, n);
    cout << "\nGia tri x = " << x << " thoa dieu kien doan [" << -x << ", " << x << "] chua tat ca cac gia tri trong mang.";
    
    return 0;
}
