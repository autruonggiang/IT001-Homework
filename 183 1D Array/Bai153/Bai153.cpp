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

int TimViTriChanDau(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            return i;
        }
    }
    return -1;
}

int TimChanNhoNhat (int a[], int n, int ViTriChanDau)
{
    int ChanMin = a[ViTriChanDau];
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] < ChanMin)
        {
            a[i] = ChanMin;
        }
    }
    return ChanMin;
}

int main()
{
    int n;
    int a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    int ViTriChanDau = TimViTriChanDau(a, n);

    if (ViTriChanDau == -1)
    {
        cout << "\nMang khong co so chan.";
    }
    else
    {
        int ChanMin = TimChanNhoNhat (a, n, ViTriChanDau);
        cout << "\nGia tri chan be nhat la: " << ChanMin;
    }

    return 0;
}
