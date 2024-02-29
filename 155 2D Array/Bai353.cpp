#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#include <cstdlib>
#include <ctime>

using namespace std;


#define ROW 100
#define COL 100


void nhapMang(int mt[][COL], int &m, int &n);
void xuatMang(int mt[][COL], int m, int n);
bool CheckMatrix(int a[][COL], int m, int x);

int main()
{
	int mt[ROW][COL], m, n;
	int nRow, nCol;


	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);

	int x;
    cout<<"Nhap vao so cot muon kiem tra: ";
    cin>>x;


	bool check = CheckMatrix(mt, nRow, x);
	if (check){
        cout<<"Cot "<<x<<" giam dan.";
	}
	else {
        cout<<"Cot "<<x<<" khong giam dan.";
	}
    
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

bool CheckMatrix(int a[][COL], int m, int x){
    for (int i = 0; i < m; i++){
        if (a[i][x] < a[i+1][x]){
            return false;
        }
    }
    
    return true;
}
