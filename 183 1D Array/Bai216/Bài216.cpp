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

int DemSoChan (int a[], int n)
{
     int dem = 0;
     for (int i = 0; i < n; i++)
     {
         if(a[i] % 2 == 0)
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

    int SoChan = DemSoChan (a, n);
    cout << "\nSo luong so chan la: " << SoChan;
    
    return 0;
}
