#include <iostream>
#include <math.h>
#define MAX 100

using namespace std;

void NhapMang (float a[], int &n)
{
    do
    {
    	cout << "Nhap so luong phan tu mang: ";
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

void HoanVi (float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

void SapXepSoDuongTangDan (float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > 0 && a[i] > a[j])
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
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    SapXepSoDuongTangDan (a, n);
    cout << "\nMang sau khi sap xep so duong tang dan: ";
    XuatMang (a, n);

    return 0;
}
