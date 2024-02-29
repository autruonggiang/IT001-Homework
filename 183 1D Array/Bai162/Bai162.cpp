#include <iostream>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define MAX 1000

using namespace std;

void nhapMang(float a[], int &n);
void xuatMang(float a[], int n);
int TimViTriThoaDieuKien(float a[], int n);


int main(){
	float a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	int kq = TimViTriThoaDieuKien(a,n);
	cout<<"Vi tri thoa dieu kien de bai la: "<<kq<<endl;

	return 0;
}


void nhapMang(float a[], int &n)
{
	//srand(time(NULL));

	cout << "Hay nhap so phan tu: ";
	cin >> n;

	cout <<"Hay nhap phan tu vao mang: "<<endl;

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


int TimViTriThoaDieuKien(float a[], int n)
{
   int i=1;
   for (;i<n-1;i++){
       if (a[i]== a[i-1]*a[i+1] ){
          return i;
       }
   }
   return -1;
}
