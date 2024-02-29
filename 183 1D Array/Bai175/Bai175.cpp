#include <iostream>
#include <math.h>
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

void LietKe (float a[], int n)
{
    int i, j;
    float khoangCachGanNhat = (abs)(a[0] - a[1]);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            if ((abs)(a[i] - a[j]) < khoangCachGanNhat)
            {
                khoangCachGanNhat = (abs)(a[i] - a[j]);
            }
        }
    }
    cout << "\nNhung cap gia tri gan nhau nhat: \n";

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            if ((abs)(a[i] - a[j]) == khoangCachGanNhat)
            {
                cout << "\t(" << a[i] << "," << a[j] << ") vi tri " << i + 1 << "," << j + 1 << "\n";
            }
        }
    }
}

int main()
{
    int n;
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);
    LietKe (a, n);

    return 0;
}
