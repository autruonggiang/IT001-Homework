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
int Check5x(int n);
int Tong5x(int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);
	Check5x(n);

	int tong = Tong5x(a,n);
	cout<<"Tong cac phan tu co so hang chuc la 5 trong mang la: "<<tong;

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

int Check5x(int n)
{
    int hc;
    n = abs(n);
    n /= 10;
    hc = n%10;
    if(hc == 5)
    {
        return 1;

    }
    return 0;
}

int Tong5x(int a[], int n)
{
    int sum=0;
    for ( int i = 0; i < n; i++){

        if(Check5x(a[i]) == 1){
            sum = sum + a[i];
        }
    }
    return sum;
}
