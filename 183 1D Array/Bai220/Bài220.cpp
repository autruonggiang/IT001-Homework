#include <iostream>
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

int DemSoLuotGiaTriTanCungLa5 (int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 10 == 5)
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    int n;
    int a[MAX];
    int x;

    NhapMang (a, n);
    XuatMang (a, n);

    int TanCung5 = DemSoLuotGiaTriTanCungLa5 (a, n);
    cout << "\nSo luong gia tri tan cung bang 5 la: " << TanCung5;
    
    return 0;
}
