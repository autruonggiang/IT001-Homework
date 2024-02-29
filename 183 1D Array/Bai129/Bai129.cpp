#include <iostream>
#define MAX 100

using namespace std;

void NhapSoNguyen (int a[], int &n)
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

void XuatSoNguyen (int a[], int n)
{
	cout << "\nDay so nguyen thu duoc: " << endl;
    for (int i = 0; i < n; i++)
    {
    	cout << a[i] << " ";
    }
}

int main ()
{
	int a[MAX];
	int n;
	NhapSoNguyen (a, n);
	XuatSoNguyen (a, n);
	return 0;
}

