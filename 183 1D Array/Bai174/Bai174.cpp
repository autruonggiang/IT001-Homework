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
    cout << "\nCac cap gia tri (a, b) thoa DK a <= b , khac nhau tung doi mot: ";
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j] || a[i] == a[j])
            {
                cout << "\nCap (" << a[i] << "," << a[j] << ") vi tri " << i +1 << "," << j + 1;
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
    LietKe(a, n);

    return 0;
}
