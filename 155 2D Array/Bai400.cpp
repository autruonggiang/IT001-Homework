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
void xoaDong(int mt[][COL], int &m, int n, int vitri);

int main(){
	int mt[ROW][COL];
	int nRow, nCol, vitri;

	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);

	int iRow;
    do{
        cout<<"Nhap vao vi tri hang can xoa: "<<endl;
        cin>>iRow;

        if(iRow < 0 || iRow > nRow - 1)
        {
            cout<<"Vi tri xoa khong ton tai.";
        }
    }while(iRow < 0 || iRow > nRow - 1);

    xoaDong(mt, nRow, nCol, vitri);
    cout<<"Ma tran sau khi da xoa dong la: "<<endl;
	xuatMang(mt, nRow, nCol);

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

void xoaDong(int mt[][COL], int &m, int n, int vitri)
{
    for(int i = vitri; i < m - 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mt[i][j] = mt[i + 1][j];
        }
    }
    m--;
}

