#include <iostream>
#define MAX 100

using namespace std;

void NhapSoThuc (float a[], int &n)
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

void XuatSoThuc (float a[], int n)
{
	cout << "\nDay so thuc thu duoc: " << endl;
    for (int i = 0; i < n; i++)
    {
    	cout << a[i] << " ";
    }
}

int main ()
{
	float a[MAX];
	int n;
	NhapSoThuc (a, n);
	XuatSoThuc (a, n);
	return 0;
}

