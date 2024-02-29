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
int CheckSoNguyenTo(int n);
int SoNguyenToLonNhat(int a[],int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	int kq = SoNguyenToLonNhat(a,n);
	cout<<"So nguyen to lon nhat trong mang = "<<kq;



	return 0;
}

void nhapMang(int a[], int &n)
{
	srand(time(NULL));

	cout << "Hay nhap so phan tu: ";
	cin >> n;

	//cout <<"Hay nhap phan tu vao mang: ";

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

int CheckSoNguyenTo(int n)
{
     if (n<=1)
         return 0;
     for (int i=2; i<n; i++)
         if(n%i==0)
             return 0;
     return 1;
}
int SoNguyenToLonNhat(int a[],int n)
{
    int dem=0;
    int max;
    for(int i=0; i<n; i++)
    {
        if(CheckSoNguyenTo(a[i])==1)
        {
            dem ++;
            max = a[i];
            break;
        }
    }
    if (dem ==0){
        cout<<"Khong co so nguyen to. ";
        return 0;
    }
    for (int i=i+1; i<n; i++)
    {
        if ((CheckSoNguyenTo(a[i])==1) && (max<a[i]))
        {
            max = a[i];
        }
    }
    return max;
}
