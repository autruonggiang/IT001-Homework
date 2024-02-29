
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
float lonnhat (float a[], int n);

int main(){
	float a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	lonnhat(a, n);

    float Max = lonnhat(a,n);
	cout<<"So lon nhat trong mang la: " << Max;

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
		//cout << endl;
	}
        cout << endl;
}

float lonnhat (float a[], int n)
{
    float Max = a[0];
    for(int i=0; i<n; i++){
        if (a[i]>Max){
            Max = a[i];
        }
    }
    return Max;
}


