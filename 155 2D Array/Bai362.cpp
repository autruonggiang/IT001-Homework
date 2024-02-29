#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include<math.h>

using namespace std;


#define ROW 100
#define COL 100


void nhapMang(int mt[][COL], int &m, int &n);
void xuatMang(int mt[][COL], int m, int n);
void LietKeCacDongGiamDan(int a[][COL],int m,int n);

int main(){
	int mt[ROW][COL];
	int nRow, nCol;

	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);
	LietKeCacDongGiamDan(mt, nRow, nCol);

	return 0;
}

void nhapMang(int mt[][COL], int &m, int &n)
{
	srand(time(NULL));

	cout << "Nhap so dong : ";
	cin >> m;
	cout << "Nhap so cot : ";
	cin >> n;


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mt[i][j] = rand()%(100-(-100)+1)+(-100);
		}
	}
}


void xuatMang(int mt[][COL], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mt[i][j] << "\t";
		}
		cout << endl;
	}
}

void LietKeCacDongGiamDan(int a[][COL],int m,int n)
{
	int i, j, flag;
	for (i = 0; i < m; i++)
	{
		for (flag = 1,j = 0; j < n - 1; j++)
		{
			if (a[i][j] < a[i][j + 1])
			{
				flag = 0;
				break;
			}

		}
		if (flag == 1)
		{
			cout << "Dong "<< i+1 << " giam." << endl;
		} else {
			cout << "Dong "<< i+1 << " khong giam." << endl;
		}
	}
}
