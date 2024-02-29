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
void LietKeChanTrongXY (int a[], int x, int y, int n);


int main(){
	int a[MAX];
	int x,y,n;

	nhapMang(a, n);
	xuatMang(a, n);

	LietKeChanTrongXY(a,x,y,n);


	return 0;
}


void nhapMang(int a[], int &n)
{
	srand(time(NULL));

	cout << "Hay nhap so phan tu: ";
	cin >> n;

	//cout <<"Hay nhap phan tu vao mang: "<<endl;

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

void LietKeChanTrongXY (int a[], int x, int y, int n)
{
    cout<<"Moi nhap gia tri x: "<<endl;
    cin>>x;
    cout<<"Moi nhap gia tri y: "<<endl;
    cin>>y;
    cout<<"Cac so chan trong mang thuoc doan ["<<x<<", "<<y<<"] gom: ";
    for (int i=0; i<n; i++){
        if (a[i]>=x && a[i]<=y){
                if (a[i]%2==0){
                    cout<<a[i]<<", ";
                }
        }
    }
}
