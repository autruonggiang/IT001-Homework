#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define MAX 100

using namespace std;

void nhapMang(float a[], int &n);
void xuatMang(float a[], int n);
float CuoiCung(float a[] , int n);


int main(){
	float a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	float x = CuoiCung(a,n);
	cout<<"So am cuoi cung lon hon -1 la: "<<x<<endl;
	if (x==0){
        cout<<"Khong co gia tri thoa man dieu kien.";
	}
	return 0;
}


void nhapMang(float a[], int &n)
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


void xuatMang(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
        //cout << a[i] << " ";
        cout << "a[" << i << "] = " << a[i] << endl;
	}
        cout << endl;
}
float CuoiCung(float a[] , int n)
{
   for(n=n-1;n>=0;n--)
   {
      if(a[n] > -1 && a[n] < 0)
      {
         return a[n];
      }
   }
   return -1.0;
}
