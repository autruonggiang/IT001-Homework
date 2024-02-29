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
int CheckHoanThien(int n);
void CheckDieuKien (int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	CheckDieuKien(a,n);

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

int CheckHoanThien(int n)
{
    int tong = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            tong += i;
        }
    }
    if(tong == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void CheckDieuKien (int a[], int n)
{
    int flag = 0;
    for (int i = 0; i<n; i++){
        if (CheckHoanThien(a[i]) == 1 && a[i] > 256){
            flag = 1;
        }
    }
    if(flag == 0){
        cout<<"Mang khong ton tai so thoa dieu kien.";
    }
    else{
        cout<<"Mang ton tai so hoan thien >256. ";
    }

}
