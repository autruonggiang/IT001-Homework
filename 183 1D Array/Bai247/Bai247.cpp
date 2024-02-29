#include <iostream>
#include<math.h>
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

int KiemTraTinhChatLe (int a[], int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] + a[i + 1] % 2) == 0)
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
    int a[MAX];
    NhapMang (a, n);
    XuatMang (a, n);

    int flag = KiemTraTinhChatLe (a, n);
    if (flag == 1)
    {
        cout << "\nMang co tinh chat le !";
    }
    else
    {
    	cout << "\nMang khong co tinh chat le !";
    }
    
	return 0;
}
