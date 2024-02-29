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
int CheckMax(int a[][COL], int nRow, int nCol, int m, int n);
void CountMax(int mt[][COL], int nRow, int nCol);

int main(){
	int mt[ROW][COL];
	int m, n;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

    CountMax(mt, m, n);

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


int CheckMax(int mt[][COL], int nRow, int nCol, int m, int n){
    int flag = 1;
    for(int i = -1; i <= 1; i++){
        for(int j=-1;j<=1;j++){
            if (m+i >= 0 && n+j>=0 && m+i<nRow && n+j<nCol && !(i==0 && j==0)){
                if(mt[m][n]<=mt[m+i][n+j]){
                    flag=0;
                }
            }
        }
    }
return flag;
}

void CountMax(int mt[][COL], int nRow, int nCol){
    int dem=0;
    for(int i=0;i<nRow;i++){
        for (int j=0;j<nCol;j++){
            if(CheckMax(mt,nRow,nCol,i,j)==1){
                dem++;
            }
        }
    }
    cout<<"So phan tu cuc dai la: "<<dem;
}
