#include <iostream>
#define MAX 100

using namespace std;

void NhapMang (int a[], int &n)
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

void XuatMang (int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void HoanVi (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SapXepSoDuongTangDanVaSoAmGiamDanViTriTuongDoiKoDoi (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 0 && a[j] > 0 && a[i] > a[j])
            {
                HoanVi (a[i], a[j]);
            }
            else if (a[i] < 0 && a[j] < 0 && a[i] < a[j])
            {
                HoanVi (a[i], a[j]);
            }
        }
    }
}

int main()
{
    int n;
    int a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    SapXepSoDuongTangDanVaSoAmGiamDanViTriTuongDoiKoDoi (a, n);
    cout << "\nMang sau khi sap xep so duong tang dan, so am giam dan\n nhung vi tri tuong doi giua cac so ko thay doi: ";
    XuatMang (a, n);

    return 0;
}


