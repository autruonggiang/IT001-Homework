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
void TachChuSo(int n, int b[]);
void FindNum(int mt[][COL],int m, int n);

int main(){
	int mt[ROW][COL];
	int nRow, nCol;

	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);
	FindNum(mt, nRow, nCol);

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

void TachChuSo(int n, int b[])
{
    int ChuSo;
    n = abs(n);
    do
    {
        ChuSo = n % 10;
        b[ChuSo]++;
        n /= 10;
    }while(n > 0);
}


void FindNum(int mt[][COL],int m, int n){
    int b[10] = {0};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            TachChuSo(mt[i][j], b);
        }
    }
    int nMax = 0;
    for(int i = 0; i < 10; i++)
    {
        if(b[nMax] < b[i])
        {
            nMax = i;
        }
    }
    cout<<"Cac chu so xuat hien nhieu nhat la: ";
    for(int i = 0; i < 10; i++)
    {
        if(b[nMax] == b[i])
        {
            cout<<i<<", ";
        }
    }
}
