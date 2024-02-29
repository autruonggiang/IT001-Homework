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
float dautien(float a[] , int n);


int main(){
	float a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	float x = dautien (a,n);
	cout<<"So dau tien lon hon gia tri 2003 la: "<<x<<endl;
	if (x==0){
        cout<<"Khong co gia tri lon hon 2003.";
	}
	return 0;
}

void nhapMang(float a[], int &n)
{
	srand(time(NULL));

	cout << "Nhap so phan tu: ";
	cin >> n;


	for (int i = 0; i < n; i++)
	{
			a[i] = rand()%(10000-(-10000)+1)+(-10000);
	}
}


void xuatMang(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
        cout << a[i] << " ";
	}
        cout << endl;
}

float dautien(float a[] , int n)
{
   for(int i = 0 ; i < n; i++)
   {
      if(a[i] > 2003)
      {
         return a[i];
      }
   }
   return 0;
}
