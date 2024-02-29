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
float duongdautien (float a[], int n);


int main(){
	float a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

    float first = duongdautien(a,n);
    cout<<"Gia tri duong dau tien cua mang la: "<<first;
	return 0;
}

void nhapMang(float a[], int &n)
{
	srand(time(NULL));

	cout << "Nhap so phan tu: ";
	cin >> n;


	for (int i = 0; i < n; i++)
	{
			a[i] = rand()%(100-(-100)+1)+(-100);
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

float duongdautien (float a[], int n)
{
    for (int i=0; i<n; i++){
        if (a[i]>0){
            return a[i];
        }
    }
    return -1;
}
