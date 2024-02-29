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
bool KiemTraSoNguyenTo(int n);
void LietKeViTri(int a[], int n);

int main(){
	int a[MAX];
	int n;

	nhapMang(a, n);
	xuatMang(a, n);

	KiemTraSoNguyenTo(n);
	LietKeViTri(a,n);


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

bool KiemTraSoNguyenTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i <= sqrt((float)n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void LietKeViTri(int a[], int n)
{
    cout<<"Vi tri so nguyen to trong mang gom: ";
    int check=0;
    for(int i=0;i<n;i++){
        if(KiemTraSoNguyenTo(a[i]) == true){
            check =  1;
            cout<<i<<", ";
        }
    }
    if (check == 0){
        cout<<"Mang khong ton tai so nguyen to.";
    }
}
