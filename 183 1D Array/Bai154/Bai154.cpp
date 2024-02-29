#include <iostream>
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

int TimVTAmDau (float a[], int n)
{
    int vitri = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            vitri = i;
            break;
        }
    }
    return vitri;
}

float VTAmLonNhat (float  a[], int n, int vitriamdau)
{
    for (int i = vitriamdau + 1; i < n; i++)
    {
        if (a[i] < 0 && a[i] > a[vitriamdau])
        {
            vitriamdau = i;
        }
    }
    return vitriamdau;
}

int main()
{
    int n;
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    int vitriamdau = TimVTAmDau (a, n);
    if (vitriamdau == -1)
    {
        cout << "\nMang khong co so am.";
    }
    else
    {
        int vitri = VTAmLonNhat (a, n, vitriamdau);
        cout << "\nVi tri phan tu am lon nhat trong mang la: " << vitri + 1;
    }

    return 0;
}
