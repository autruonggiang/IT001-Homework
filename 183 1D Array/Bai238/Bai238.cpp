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

int TimTanSuatXuatHienMax (int a[], int n)
{
    int Max = 1; 
    for (int i = 0; i < n; i++)
    {
        int dem = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                dem++;
            }
        }
        if (dem > Max)
        {
            Max = dem;
        }
    }
    return Max;
}

int KiemTraBiTrung (int a[], int n, int index)
{
    for (int i = index - 1; i >= 0; i--)
    {
        if (a[i] == a[index])
        {
            return 0; 
        }
    }
    return 1;
}

int DemTanSuatXuatHien (int a[], int n, int index)
{
    int dem = 1; 
    for (int i = index + 1; i < n; i++)
    {
        if (a[i] == a[index])
        {
            dem++;
        }
    }
    return dem;
}

void LietKeCacSoXuatHienNhieuNhat (int a[], int n)
{
    int TanSuatMax = TimTanSuatXuatHienMax (a, n);
    for (int i = 0; i < n; i++)
    {
        int CheckTrung = KiemTraBiTrung (a, n, i);
        if (CheckTrung == 1)  
        {
            int TanSuat = DemTanSuatXuatHien (a, n, i);

            if (TanSuat == TanSuatMax)
            {
                cout << "\nPhan tu xuat hien nhieu nhat la: " << a[i];
            }
        }
    }
    cout << "\n=> So lan xuat hien la: " << TanSuatMax;
}

int main()
{
    int n;
    int a[MAX];
    NhapMang (a, n);
    XuatMang (a, n);
    LietKeCacSoXuatHienNhieuNhat (a, n);

    return 0;
}
