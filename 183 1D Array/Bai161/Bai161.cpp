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
int dautientrendoanxy(int a[], int n, int x, int y);


int main(){
	int a[MAX];
	int n, x, y;

	cout<<"Moi nhap gia tri x: "<<endl;
	cin>>x;
	cout<<"Moi nhap gia tri y: "<<endl;
	cin>>y;

	nhapMang(a, n);
	xuatMang(a, n);

	int kq = dautientrendoanxy(a,n,x,y);
	cout<<"Gia tri dau tien nam trong doan["<<x<<","<<y<<"] la: "<<kq<<endl;

	return 0;
}


void nhapMang(int a[], int &n)
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


void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
        //cout << a[i] << " ";
        cout << "a[" << i << "] = " << a[i] << endl;
	}
        cout << endl;
}

int dautientrendoanxy(int a[], int n, int x, int y)
{
    int check = 0;
    int i=0;
    for(i=0; i<n;i++)
    {
         if ( a[i]>=x && a[i]<=y )
         {
              check++;
              break;
         }
    }
    if (check == 0)
           return x;
    return a[i];
}
