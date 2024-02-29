#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include<math.h>

using namespace std;


#define ROW 100
#define COL 100


void nhapMang(int mtA[][COL], int &m, int &n);
void xuatMang(int mtA[][COL], int m, int n);
void changeB(int mtA[][COL], int m, int n, int mtB[][COL]);

int main(){
	int mtA[ROW][COL],mtB[ROW][COL];
	int m, n;

	nhapMang(mtA, m, n);
	xuatMang(mtA, m, n);
	changeB(mtA,m,n,mtB);
	cout<<"Ma tran B la:"<<endl;
	xuatMang(mtB, m, n);


	return 0;
}

void nhapMang(int mtA[][COL], int &m, int &n)
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
			mtA[i][j] = rand()%(100-(-100)+1)+(-100);
		}
	}
}


void xuatMang(int mtA[][COL], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mtA[i][j] << "\t";
		}
		cout << endl;
	}
}

void changeB(int mtA[][COL], int m, int n, int mtB[][COL])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mtB[i][j] = abs(mtA[i][j]);
        }
    }
}
