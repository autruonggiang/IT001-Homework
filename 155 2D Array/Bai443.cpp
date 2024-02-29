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
int MaxTren(int mt[][COL], int n);

int main(){
	int mt[ROW][COL];
	int m, n;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

	int M=MaxTren(mt,n);
    cout<<"Phan tu lon nhat trong ma tran tam giac tren: "<<M;

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

int MaxTren(int mt[][COL], int n)
{
	int Max=mt[0][0];
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(mt[i][j]>Max)
				Max=mt[i][j];
	return Max;
}
