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
int TongCheoChinh(int mt[][COL], int n);

int main(){
	int mt[ROW][COL];
	int m, n;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);
	int kq = TongCheoChinh(mt,n);
    cout<<" Tong cua cac phan tu tren duong cheo chinh = "<<kq;

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


int TongCheoChinh(int mt[][COL], int n)
{
    int Sum = 0;
    for (int i = 0; i < n; i++)
    {
        Sum += mt[i][i];
    }
    return Sum;
}
