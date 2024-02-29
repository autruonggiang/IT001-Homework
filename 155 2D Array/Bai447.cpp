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
int FindMaxNum(int mt[][COL], int n);
int FindFirstNum(int mt[][COL], int n);
int CheckNum(int n);


int main(){
	int mt[ROW][COL];
	int m, n;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

int M = FindMaxNum(mt, n);
    cout<<"So nguyen to lon nhat trong ma tran = "<< M;
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

int CheckNum(int n)
{
    if(n < 2)
    {
        return 0;
    }
    else if(n > 2)
    {
        if(n % 2 == 0)
        {
            return 0;
        }
        for(int i = 3; i <= sqrt((float)n); i++)
        {
            if(n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int FindFirstNum(int mt[][COL], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(CheckNum(mt[i][j]) == 1)
            {
                return mt[i][j];
            }
        }
    }
    return 0;
}

int FindMaxNum(int mt[][COL], int n)
{
    int Max = FindFirstNum(mt, n);
    if(Max == 0)
    {
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(CheckNum(mt[i][j]) == 1)
            {
                Max = (mt[i][j] > Max) ? mt[i][j] : Max;
            }
        }
    }
    return Max;
}
