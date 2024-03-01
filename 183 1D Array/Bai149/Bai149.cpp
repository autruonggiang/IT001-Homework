#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define MAX 100

using namespace std;

void nhapMang(int a[], int &n);
void xuatMang(int a[], int n);
int timsohoanthiencuoi(int a[], int n);
int checknum(int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

    cout<<"So hoan thien cuoi cung cua mang la: "<<timsohoanthiencuoi(a, n);

	return 0;
}

void nhapMang(int a[], int &n)
{
	//srand(time(NULL));

	cout << "Hay nhap so phan tu: ";
	cin >> n;

	cout <<"Hay nhap phan tu vao mang: ";

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
        //cout << endl;
}

int checknum(int n)
{
   int tong=0;
   for (int i=1 ; i<n; i++)
       if(n%i==0)
          tong = tong + i;
   if (tong == n)
      return 1;
   return 0;
}
int timsohoanthiencuoi(int a[],int n)
{
   for(int i=n-1; i>=0; i--)
       if(checknum(a[i])==1)
          return a[i];
   return -1;
}