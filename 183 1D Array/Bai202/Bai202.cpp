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
int TimDauLe(int n);
int TongDauLe(int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);
	TimDauLe(n);

	int tong = TongDauLe(a,n);
	cout<<"Tong cac phan tu co chu so dau le trong mang la: "<<tong;

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

int TimDauLe(int n)
{
    int dv;
    n = abs(n);
    while(n >= 10)
    {
        dv = n % 10;
        n /= 10;
    }
    if(n % 2 == 0)
    {
        return 1;

    }
    return 0;
}

int TongDauLe(int a[], int n)
{
    int sum=0;
    for ( int i = 0; i < n; i++){

        if(TimDauLe(a[i]) == 0){
            sum = sum + a[i];
        }
    }
    return sum;
}
