#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include<math.h>

using namespace std;


#define ROW 100
#define COL 100


void nhapMang(float mt[][COL], float &m, float &n);
void xuatMang(float mt[][COL], float m, float n);
double SumTren(float mt[][COL], float n);

int main(){
	float mt[ROW][COL];
	float m, n, x;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

	double kq=SumTren(mt,n);
    cout<<"Tong cua cac phan tu thuoc tam giac tren cua ma tran = "<<kq;

	return 0;
}

void nhapMang(float mt[][COL], float &m, float &n)
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


void xuatMang(float mt[][COL], float m, float n)
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
double SumTren(float mt[][COL], float n)
{
	double sum=0;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1;j++)
			if(i<j)
				sum=sum+mt[i][j];
	return sum;
}
