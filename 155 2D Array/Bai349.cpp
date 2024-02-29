#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


#define ROW 100
#define COL 100


void nhapMang(int mt[][COL], int &m, int &n);
void xuatMang(int mt[][COL], int m, int n);
int CheckNum(int mt[][COL], int m, int n);
int CheckMatrix(int mt[][COL], int m, int n);

int main()
{
	int mt[ROW][COL];
	int m,n;


	nhapMang(mt, m, n);
	xuatMang(mt, m, n);

	int check=CheckMatrix(mt,m,n);
	if (check==1){
        cout<<"Ma tran co ton tai so hoan thien";
	}
	else {
        cout<<"Ma tran khong ton tai so hoan thien";
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
int CheckNum(int n){
    int tong =0;
    for (int i=1; i<n; i++){
        if(n%i==0){
            tong=tong+i;
        }
    }
    if (tong==n){
        return 1;
    }
    return 0;
}

int CheckMatrix(int mt[][COL], int m, int n){
    int check = 0;
    for (int i = 0; i<m; i++){
        for (int j=0; j<n; j++){
            if (CheckNum(mt[i][j])==1){
                check=1;
            }

        }
    }
    return check;
}
