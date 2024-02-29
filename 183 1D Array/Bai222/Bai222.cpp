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

int DemPhanTuLonHonHayNhoHonPhanTuXungQuanh (float a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && a[i] != a[i + 1]) 
        {
            dem++;
        }
        else if (i == n - 1 && a[i - 1] != a[i])  
        {
            dem++;
        }
        else if ((a[i - 1] > a[i] && a[i] < a[i + 1]) || (a[i - 1] < a[i] && a[i] > a[i + 1]))
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    int n;
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);
    int dem = DemPhanTuLonHonHayNhoHonPhanTuXungQuanh (a, n);
    cout << "\nSo luong phan tu lon hon hoac nho hon phan tu xung quanh: " << dem;

    return 0;
}
