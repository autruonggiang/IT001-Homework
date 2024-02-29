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

void LietKeCacGiaTriCucDai (float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1] && a[i - 1] < a[i])
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{
    int n;
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);
    cout << "\nCac phan tu cuc dai la: ";
    LietKeCacGiaTriCucDai (a, n);

    return 0;
}
