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

int KiemTraDangSong (int a[], int n)
{
    int flag = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if ((a[i] < a[i - 1] && a[i] > a[i + 1]) || (a[i] > a[i - 1] && a[i] < a[i + 1]))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int n, d;
    int a[MAX];
    NhapMang (a, n);
    XuatMang (a, n);

    int flag = KiemTraDangSong (a, n);
    if (flag == 1)
    {
        cout << "\nCac phan tu trong mang co dang song.";
    }
    else
    {
    	cout << "\nCac phan tu trong mang khong co dang song !";
    }
    
    return 0;
}

