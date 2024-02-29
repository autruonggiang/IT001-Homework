#include <iostream>
#include <math.h>
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

int TimChuSoDauLe (int n)
{
    int dv;
	while (n >= 10)   
	{
    	dv = n % 10;
    	n = n / 10;
	}
	if (n % 2 == 0)
    	return 0;
	return 1;
}

int LietKeViTriChuSoDauLe (int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
       if (TimChuSoDauLe(a[i]) == 1)
       {
           cout << a[i] << " ";
       }
    }
   return 0;
}

int main()
{
    int n;
    int a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    cout << "\nCac so co chu so dau le la: ";
    LietKeViTriChuSoDauLe (a, n);
    
    return 0;
}

