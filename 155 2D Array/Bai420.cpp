#include <iostream>
#include <iomanip>
#include <math.h>
#define MAX 100

using namespace std;

void NhapMang(int a[][MAX], int &dong, int &cot)
{
    do
    {
        cout << "\nNhap vao so dong: ";
        cin >> dong;

        if (dong < 1 || dong > MAX)
        {
            cout << "\nSo dong khong hop le. Xin kiem tra lai !";
        }

    } while (dong < 1 || dong > MAX);

    do
    {
        cout << "\nNhap vao so cot: ";
        cin >> cot;

        if (cot < 1 || cot > MAX)
        {
            cout << "\nSo cot khong hop le. Xin kiem tra lai !";

        }

    } while (cot < 1 || cot > MAX);
    
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "\nNhap a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMang(int a[][MAX], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n\n";
    }
}

void GanBienVaoMang(int a[][MAX],int dong, int cot, int temp[], int &idx)
{
    int i = 0, j;            

    for (j = i; j < cot; j++) 
    {
        temp[idx++] = a[i][j];  
     }

    for (i++, j--; i < dong; i++)  
    {
        temp[idx++] = a[i][j];
    }

    for (i--, j--; j >= 0; j--)
    {
        temp[idx++] = a[i][j];
    }

    for (i--, j++; i > 0; i--)
    {
        temp[idx++] = a[i][j];
    }
}

void HoanVi(int &a, int &b)
{
    int tam = a;
    a = b;
    b = tam;
}

void SapXepMangTangDan(int temp[], int idx)
{
    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = i + 1; j < idx; j++)
        {
            if (temp[i] > temp[j])
            {
                HoanVi(temp[i], temp[j]);
            }
        }
    }
}

void GanMangVaoBien(int a[][MAX],int dong, int cot, int temp[])
{
    int i = 0, j, idx = 0;            

    for (j = i; j < cot; j++) 
    {
          a[i][j] = temp[idx++];   
     }

    for (i++, j--; i < dong; i++)  
    {
         a[i][j] = temp[idx++];
    }

    for (i--, j--; j >= 0; j--)
    {
         a[i][j] = temp[idx++];
    }
    
    for (i--, j++; i > 0; i--)
    {
         a[i][j] = temp[idx++];
    }
}

void SapXepCacGiaTriNamTrenBienTangDan(int a[][MAX], int dong, int cot)
{
    int temp[MAX], idx = 0;  
    GanBienVaoMang(a, cot, dong, temp, idx);  
    SapXepMangTangDan(temp, idx);  
    GanMangVaoBien(a, cot, dong, temp); 

}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    SapXepCacGiaTriNamTrenBienTangDan(a, dong, cot);
	cout << "\nMa tran sau khi sap xep: \n";
    XuatMang(a, dong, cot);

    return 0;
}
