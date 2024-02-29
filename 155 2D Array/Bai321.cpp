#include <iostream>
#include <iomanip>
using namespace std;
 
int main() 
{
	int i, j, row, col, a[100][100];
	
	cout << "TINH TICH CAC GIA TRI LE TRONG MA TRAN SO NGUYEN.\n";
	
	do
	{
		cout << "Nhap so hang cua ma tran: ";
		cin >> row;
		
		if (row < 0)
		{
			cout << "So khong hop le. Vui long nhap lai !";
		}
	} while (row < 0);
		
	do
	{
		cout << "Nhap so cot cua ma tran: ";
		cin >> col;
		
		if (col < 0)
		{
			cout << "So khong hop le. Vui long nhap lai !";
		}
	} while (col < 0);
 
	cout << "Nhap ma tran: ";
	for (i = 0; i < row; i++) 
	{
    	for (j = 0; j < col; j++) 
		{
        cout << "Nhap phan tu a[" << i << "][" << j << "] : ";
        cin >> a[i][j];
    	}
	}
   
	int Tich = 1;
	int n = row * col;
	for (int i = 0; i < n; i++) 
	{
		if (a[i / col][i % col] % 2 != 0)
		{
    		Tich = Tich * a[i / col][i % col];
    	}
	}
 
	cout << "Tich cac gia tri cua ma tran so nguyen la: " << Tich;
	return (0);
}
