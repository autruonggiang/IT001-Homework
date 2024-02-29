#include <iostream>
#include<math.h>
using namespace std;
void nhap(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhap a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuat(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\t" << a[i];
	}
}

int gia_tri(int a[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		float b = log10(a[i]);
		float c = log10(5);
		float k = b / c;
		float d = (int)k;
		if (k != 0 && k - d == 0) {
			int e = pow(5, d);
			if (e % 5 == 0) {
				if (a[i] > max) max = a[i];
			}
		}
	}
	return max;
}
int main(int argc, char** argv) {
	int a[100], n;
	cout << "Nhap n: ";
	cin >> n;

	nhap(a, n);
	cout << "\nMang vua nhap la: ";
	xuat(a, n);
	cout << "\nKL: Vay gia tri can tim la: " << gia_tri(a, n);
	return 0;
}