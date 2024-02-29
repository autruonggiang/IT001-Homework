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

void dau(int a[], int nA, int index) {
	int temp;
	for (int i = index; i > 0; --i) {
		temp = a[i-1];
		a[i-1] = a[i];
		a[i] = temp;
	}
}

void cuoi(int a[], int nA, int index) {
	int temp;
	for (int i = index; i < nA-1; ++i) {
		temp = a[i+1];
		a[i+1] = a[i];
		a[i] = temp;
	}
}

void giua(int a[], int nA, int index) {
	int temp;
	for (int i = index; i < nA-1; ++i) {
		if (a[i+1]%2 != 0) {
			temp = a[index];
			a[index] = a[i];
			a[i] = temp;
		}
	}
}

void solve(int a[], int nA) {
	
	for (int i = 0; i < nA; ++i) {
		if (a[i]%2 == 0)
			dau(a, nA, i);
	}
	for (int i = 0; i < nA; ++i) {
		if (a[i] == 0)
			giua(a, nA, i);
	}
	
	
	cout << "Chan dau, le cuoi, 0 giua la: " << endl;
	output(a, nA);
}

int main() {
	
	int a[MAX], nA;
	
	input(a, nA);
	solve(a, nA);
	
	
	return 0;
}