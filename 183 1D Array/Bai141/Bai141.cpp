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

int TimVTDuongNhoNhat (float a[], int n)
{
    int i;
    int min;
    int dem = 0 ;
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)  
        {
            dem++;      
            min = i;     
            break;      
        }
    }  
    if (dem == 0)     
        return -1;
    for (i = i + 1; i < n; i++)
    {
        if ((a[i] > 0) && (a[i] < a[min]))
        {
           min = i;
        }
    }
    return min;
}

int main()
{
    int n;
    float a[MAX];

    NhapMang (a, n);
    XuatMang (a, n);

    int vitriduongnhonhat = TimVTDuongNhoNhat (a, n);
    cout << "\nVi tri gia tri duong nho nhat la: " << vitriduongnhonhat + 1;

    return 0;
}
