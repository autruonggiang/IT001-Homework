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
int MinSumCol(int mt[][COL], int m, int n);

int main(){
	int mt[ROW][COL];
	int nRow, nCol;

	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);
	MinSumCol(mt,nRow, nCol);

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

int sum(int a[], int m)
{
    int sum = 0;
    for(int i = 0; i < m; i++){
        sum += a[i];
    }
    return sum;
}
int MinSumCol(int mt[][COL], int m, int n){
    int b[COL] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i] += mt[j][i];
        }
    }
    int Min = b[0];
    for(int i = 1; i < n; i++){
        Min = (Min < b[i]) ? Min : b[i];
    }
    for (int i = 0; i < n ;i++){
        if (Min == b[i]){
            cout<<"Cot "<<i+1<<" co tong nho nhat la: "<< Min;
        }
    }
}

