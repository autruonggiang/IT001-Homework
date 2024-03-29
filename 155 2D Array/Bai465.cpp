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
void SapXep(int mt [][COL],int m, int n);

int main(){
	int mt[ROW][COL];
	int m, n, x;

	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

	SapXep(mt,m,n);
    cout<<"Ma tran da duoc sap xep lai nhu sau: "<<endl;
    xuatMang(mt,m,n);

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

void SapXep(int mt [][COL],int m, int n){
    int x=0,y=0,z;
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mt[i][j]%2==0){
                z=mt[i][j];
                mt[i][j]=mt[x][y];
                mt[x][y]=z;
                if (y<n){
                    y++;
                }
                else {
                    y=0;
                    x++;
                }
            }
        }
    }
}
