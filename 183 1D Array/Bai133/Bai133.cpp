#include <iostream>
using namespace std;

int main () {
	int n;
	cout << endl << "Nhap so phan tu: ";
	cin >> n;
	float a[n];
	for (int i=0; i<n; i++){
		cout << endl << "Nhap a[" << i+1 << "]: ";
		cin >> a[i];
	}
	for (int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Cac vi tri chua gia tri am trong mang mot chieu so thuc la: ";
	for (int i=0; i<n; i++){
		if (a[i]<0) {
			cout << i+1 << " ";
		}
	}
}