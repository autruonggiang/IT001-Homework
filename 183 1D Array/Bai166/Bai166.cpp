#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;
void nhap(int a[], int& n)
{
    srand(time(NULL));

    cout << "Nhap so phan tu: ";
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - (-100) + 1) + (-100);
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int gia_tri(int a[], int n) {
	for (int i = 0; i < n; i++) {
		float b = log10(a[i]);
		float c = log10(2);
		float k = b / c;
		float k2 = (int)k;
		if (k != 0 && k - k2 == 0) {
			int d = pow(2, k);
			if (d % 2 == 0) return a[i];
		}
	}
	return 0;
}
int main(int argc, char** argv) {
	int a[100], n;

	nhap(a, n);
	cout << "\nMang vua nhap la: ";
	xuat(a, n);
	cout << "\nVay gt can tim la: " << gia_tri(a, n);
	return 0;
}