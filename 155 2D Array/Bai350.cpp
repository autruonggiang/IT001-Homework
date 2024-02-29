#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


#define ROW 100
#define COL 100


void nhapMang(int mt[][COL], int &m, int &n);
void xuatMang(int mt[][COL], int m, int n);
int CheckMatrix(int mt[][COL], int m, int n);

int main()
{
	int mt[ROW][COL];
	int nRow, nCol;
	int m,n;


	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);

	bool checkMt;
	checkMt = CheckMatrix(mt, nRow,nCol);
	if (checkMt == true){
        cout<<"Ma tran co ton tai so le";
	}
	else {
        cout<<"Ma tran khong ton tai so le";
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


int CheckMatrix(int a[][COL], int m, int n){
    int check = 0;
    for (int i = 0; i<m; i++){
        for (int j=0; j<n; j++){
            if (a[i][j]%2 != 0){
                check=1;
            }

        }
    }
    return check;
}
