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

int DemPhanTuLonNhatDungSau (int a[], int n)
{
    int dem = 0;
    for (int i = 1; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j] || a[i] == a[j])
            {
                flag = 0;
            }
        }
        if (flag == 1)
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
    NhapMang (a, n);
    XuatMang (a, n);

    

    int dem = DemPhanTuLonNhatDungSau (a, n);
    cout << "\nGia tri trong mang thoa: lon hon tat ca cac gia tri dang truoc no = " << dem;
    
	return 0;
}
