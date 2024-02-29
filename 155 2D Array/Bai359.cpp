#include <iostream>
#include <iomanip>
#define MAX 100

using namespace std;

void NhapMang(int a[][MAX], int &dong, int &cot)
{
    do
    {
        cout << "\nNhap vao so dong: ";
        cin >> dong;

        if(dong < 1 || dong > MAX)
        {
            cout << "\nSo dong khong hop le. Xin kiem tra lai! ";
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

    }while(cot < 1 || cot > MAX);
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            cout << "\nNhap a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMang(int a[][MAX], int dong, int cot)
{
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            cout << a[i][j] << " ";
        }
            cout << "\n\n";
    }
}

void LietKeDongChuaGiaTriAm(int a[][MAX], int dong, int cot)
{
    int flag;
    for (int i = 0; i < dong; i++)
    {
        flag = 0;
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] < 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
    	cout << "\nDong a[" << i + 1 << "] co chua so am "; 
        }    
    }
}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    LietKeDongChuaGiaTriAm(a, dong, cot);
    return 0;
}
