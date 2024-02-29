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
int KiemTraDoiXung(int n);
int TongDoiXung(int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	int sum = TongDoiXung(a,n);
	cout<<"Tong cac so doi xung trong mang la: "<<sum;

	return 0;
}


void nhapMang(int a[], int &n)
{
	srand(time(NULL));

	cout << "Hay nhap so phan tu: ";
	cin >> n;

	cout <<"Hay nhap phan tu vao mang: "<<endl;

	for (int i = 0; i < n; i++)
	{
			//a[i] = rand()%(100-(-100)+1)+(-100);
			cin>>a[i];
	}
}


void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
        //cout << a[i] << " ";
        cout << "a[" << i << "] = " << a[i] << endl;
	}
        cout << endl;
}

int KiemTraDoiXung(int n)
{
    int dv, temp = n;
    int reNum = 0;
    while(temp != 0)
    {
        dv = temp % 10;
        reNum = reNum * 10 + dv;
        temp /= 10;
    }
    if(reNum == n)
    {
        return 1;
    }
    return 0;

}

int TongDoiXung(int a[], int n)
{
    int sum=0;
    for (int i = 0; i < n; i++){
        if (KiemTraDoiXung (a[i]) == 1){
            sum = sum + a[i];
        }
    }
    return sum;

}
