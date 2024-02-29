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
void LietKeChiSo(int mt[][COL], int m, int n);

int main()
{
	int mt[ROW][COL], m, n;


	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

	LietKeChiSo(mt, m, n);
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

void LietKeChiSo(int mt[][COL], int m, int n)
{
    bool check,flag=1;
    for(int i = 0; i < m; i++)
    {
        check = 1;
        for(int j = 0; j < m; j++)
        {
            if(mt[i][j] % 2 != 0)
            {
                check = 0;
                break;
            }
        }
        if(check)
        {
            flag=0;
            cout<<"Dong "<<i<<" toan chan"<<endl;
        }

    }
    if(flag){
        cout<<"Khong co dong nao toan chan";
    }
}
