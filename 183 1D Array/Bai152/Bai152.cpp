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
int CheckSoHoanThien(int n);
int SoHoanThienNhonhat(int a[],int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	int kq = SoHoanThienNhonhat(a,n);
	cout<<"So hoan thien nho nhat trong mang la: "<<kq;

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
        cout << endl;
}

int CheckSoHoanThien(int n)
{
   int tong=0;
   for (int i=1 ; i<n; i++)
       if(n%i==0)
          tong = tong + i;
   if (tong == n)
      return 1;
   return 0;
}
int SoHoanThienNhonhat(int a[],int n)
{
   int check =0;
   int min;
   for(int i=0; i<n; i++)
   {
       if(CheckSoHoanThien(a[i])==1)
       {
           check ++;
           min = a[i];
           break;
       }
   }
   if (check ==0){
       cout<<"Mang khong ton tai so hoan thien. "<<endl;
       return 0;
   }
   for (int i=i+1; i<n; i++)
   {
       if ((CheckSoHoanThien(a[i])==1) && (min>a[i]))
       {
           min = a[i];
       }
   }
   return min;
}
