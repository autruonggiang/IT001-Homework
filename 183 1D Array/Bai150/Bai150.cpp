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
int SoAmLonNhat(int a[],int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);


    float kq = SoAmLonNhat(a,n);
    cout<<"So am lon nhat la: "<< kq;

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

int SoAmLonNhat(int a[],int n) {

    int max=0;
    int check=0;

    for(int i=0; i<n; i++) {
        if(a[i]<0) {
            check++;
            max = a[i];
            break;
        }
    }
    if (check==0){
        cout<<"Mang khong ton tai so am. ";
        return 0;
    }
    for(int i=0; i<n; i++) {
        if(a[i]<0 && a[i]>max){
            max = a[i];
        }
    }
    return max;
}
