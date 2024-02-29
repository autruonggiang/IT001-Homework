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

void HoanVi (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SapXep (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                HoanVi (a[i], a[j]);
            }
        }
    }
}

void Tron2MangThanh1Mang (int a[], int b[], int c[], int na, int nb, int &nc)
{
    nc = na + nb;         
    SapXep(a, na);       
    SapXep(b, nb);       
    int vitriA = 0, vitriB = 0; 
    for (int i = 0; i < nc; i++)       
    {
        if (vitriA < na && vitriB < nb)   
        {
            if (a[vitriA] < b[vitriB])    
            {
                c[i] = a[vitriA++];          
            }
            else
            {
                c[i] = b[vitriB++];            
            }
        }
        else if(vitriB == nb)           
        {
            c[i] = a[vitriA++];        
        }
        else
        {
            c[i] = b[vitriB++];
        }
    }
}

int main()
{
    int na, nb, nc;
    int a[MAX], b[MAX], c[MAX];

	cout << "\nNhap vao mang A: ";
    NhapMang (a, na);
    XuatMang (a, na);

	cout << "\nNhap vao mang B: ";
    NhapMang (b, nb);
    XuatMang (b, nb);

    Tron2MangThanh1Mang (a, b, c, na, nb, nc);
    cout << "\nMang sau khi tron 2 mang A va B : ";
    XuatMang (c, nc);

    return 0;
}
