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
int CheckRow(int mt[], int n);
int CountRow(int mt[][COL], int n);
int main(){
	int mt[ROW][COL];
	int m, n, x;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

    int dem = CountRow(mt, n);
    cout<<"So dong trong ma tran giam la: "<<dem;

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
			//mt[i][j] = rand()%(100-(-100)+1)+(-100);
			cin>>mt[i][j];
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

int CheckRow(int mt[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        if(mt[i] < mt[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int CountRow(int mt[ROW][COL], int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if( CheckRow(mt[i], n) == 1)
        {
            dem++;
        }
    }
    return dem;
}


