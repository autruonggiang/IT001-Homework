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
int chancuoi (int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);
    chancuoi(a, n);

    cout<<"So chan cuoi cung cua mang la: "<<chancuoi(a, n);

	return 0;
}

void nhapMang(int a[], int &n)
{
	srand(time(NULL));

	cout << "Nhap so phan tu: ";
	cin >> n;


	for (int i = 0; i < n; i++)
	{
			a[i] = rand()%(100-(-100)+1)+(-100);
	}
}


void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
        cout << a[i] << " ";
	}
        cout << endl;
}

int chancuoi (int a[], int n)
{
    for (int i = n-1; i >= 0; i--){
        if (a[i] % 2 == 0){
            return a[i];
        }
    }
    return -1;

}
