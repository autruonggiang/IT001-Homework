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

void TimDoan (float a[], int n)
{
    float max = a[0];
    float min = a[0];
    for (int i = 0; i < n; i++)
    {
        max = (a[i] > max) ? a[i] : max;
        min = (a[i] < min) ? a[i] : min;
    }
    cout << "\n[" << min << " , " << max << "] la doan chua cac gia tri trong mang.\n";
}

int main()
{
    int n;
    float a[MAX];
    float b[MAX];

    NhapMang (a, n);
    XuatMang (a, n);
    TimDoan (a, n);
    
    return 0;
}
