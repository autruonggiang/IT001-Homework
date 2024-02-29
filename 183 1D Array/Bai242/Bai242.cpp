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
void CheckTonTaiChan (int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	CheckTonTaiChan(a,n);

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

void CheckTonTaiChan (int a[], int n)
{
    int flag = 0;
    for (int i = 0; i<n; i++){
        if (a[i]%2 == 0){
            flag = 1;
        }
    }
    if(flag == 0){
        cout<<"Mang khong ton tai gia tri chan.";
    }
    else{
        cout<<"Mang co ton tai gia tri chan. ";
    }

}
