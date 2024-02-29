#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define MAX 1000

using namespace std;

void nhapMang(int a[], int &n);
void xuatMang(int a[], int n);
int KiemTraSNT(int n);
int DemSNT(int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	int sl = DemSNT(a,n);
	cout<<"So luong so nguyen to trong mang la: "<<sl;

	return 0;
}


void nhapMang(int a[], int &n)
{
	srand(time(NULL));

	cout << "Hay nhap so phan tu: ";
	cin >> n;

	//cout <<"Hay nhap phan tu vao mang: "<<endl;

	for (int i = 0; i < n; i++)
	{
			a[i] = rand()%(100-(-100)+1)+(-100);
			//cin>>a[i];
	}
}


void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
        cout << a[i] << " ";
        //cout << "a[" << i << "] = " << a[i] << endl;
	}
        cout << endl;
}

int KiemTraSNT(int n)
{
    if (n < 2)
    {
        return 0;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return 0;
        }
        for (int i = 3; i <= sqrt((float)n); i += 2)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int DemSNT(int a[], int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(KiemTraSNT(a[i]) == 1)
        {
            dem++;
        }
    }
    return dem;
}
