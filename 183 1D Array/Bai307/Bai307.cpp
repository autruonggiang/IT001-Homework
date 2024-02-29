#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

using namespace std;

void output(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void input (int a[], int &n, bool bug = false) {
	
	srand(time(NULL));
	
	cout << "Do dai cua mang: ";
	cin >> n;
	
	if (!bug) {
		for (int i = 0; i < n; ++ i) {
			cout << "Gia tri cua a[" << i << "]: ";
			cin >> a[i];
		}
	} else {
		for (int i = 0; i < n; ++i) {
			a[i] = rand()%200-99;
		}
	}
	
	cout << "Mang A la: " << endl;
	output(a, n);
}

void solve(int a[], int n) {
	
	int b[MAX];
	
	int dem = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i]%2 == 1 || a[i]%2 == -1) {
			b[dem] = a[i];
			dem++;
		}
	}
	
	cout << "Mang B la cac gia tri le cua A la: " << endl;
	output(b, dem);
}

int main() {
	
	int a[MAX], n;
	
	input(a, n, true);
	solve(a, n);
	
	
	return 0;
}