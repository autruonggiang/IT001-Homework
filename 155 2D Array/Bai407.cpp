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
void HoanVi(int &a, int &b);
void Tangdan(int mt[][COL], int m, int n, int x);

int main(){
	int mt[ROW][COL];
	int m, n, x;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

	do{
        cout<<"Nhap dong muon sap xep: "<<endl;
        cin>>x;
        if(x < 0 || x > m - 1)
        {
            cout<<"Dong khong ton tai. ";
        }
    }while(x < 0 || x > m - 1);

    Tangdan(mt, m, n, x-1);
    cout<<"Ma tran sau khi sap xep:"<<endl;
    xuatMang(mt, m, n);

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

void HoanVi(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void Tangdan(int mt[][COL], int m, int n, int x)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(mt[x][i] > mt[x][j])
            {
                HoanVi(mt[x][i], mt[x][j]);
            }
        }
    }
}
