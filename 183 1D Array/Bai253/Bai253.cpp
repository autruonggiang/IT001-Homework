#include <iostream>
#define MAX 100

using namespace std;

void NhapMang (int a[], int &n)
{
    do
    {
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

int KiemTraMangANamTrongMangB (int a[], int b[], int n, int m)
{
    int flag = 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                dem++;
            }
        }
    }
    if (dem == n)
    {
        flag = 1;    
    }
    return flag;
}

int main()
{
    int n, m;
    int a[MAX];
    cout << "\nNhap so phan tu mang A: ";
    NhapMang (a, n);
    XuatMang (a, n);

    int b[MAX];
	cout << "\nNhap so phan tu B: ";
    NhapMang (b, m);
    XuatMang (b, m);

    int flag = KiemTraMangANamTrongMangB (a, b, n, m);
    if (flag == 1)
    {
        cout << "\nTat ca cac phan tu trong mang A deu nam trong mang B.";
    }
    else
    {
    	cout << "\nCac phan tu trong mang A khong nam trong B !";
    }
    
    return 0;
}
