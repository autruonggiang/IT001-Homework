#include <iostream>
#include<math.h>
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

int KiemTraMangDoiXung (float a[], int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n - i - 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int n;
    float a[MAX];
    NhapMang (a, n);
    XuatMang (a, n);

    int flag = KiemTraMangDoiXung (a, n);
    if (flag == 1)
    {
        cout << "\nMang doi xung !";
    }
    else
    {
    	cout << "\nMang khong doi xung !";
    }
    
	return 0;
}
