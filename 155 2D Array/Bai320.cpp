#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
	int i, j, row, col, a[100][100];
	
	cout << "TINH TONG CAC SO DUONG TRONG MA TRAN SO THUC.\n";
	
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
   
	float sum = 0;
	int n = row * col;
	for (int i = 0; i < n; i++) 
	{
		if (a[i / col][i % col] > 0)
		{
    		sum = sum + a[i / col][i % col];
    	}
	}
 
	cout << "Tong tat ca cac phan tu duong cua ma tran so thuc la: " << sum;
	return (0);
}
