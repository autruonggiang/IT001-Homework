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
int CheckLienTiep0 (int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	if(CheckLienTiep0(a,n) == 1){
        cout<<"Mang co ton tai 2 gia tri 0 lien tiep. ";
    }
    else {
        cout<<"Mang khong ton tai 2 gia tri 0 lien tiep.";
    }

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

int CheckLienTiep0 (int a[], int n)
{
    int flag = 0;
    for (int i = 0; i<n; i++){
        if (a[i] == 0 && a[i+1] == 0){
            return 1;
            break;
        }
    }
    return -1;
}
