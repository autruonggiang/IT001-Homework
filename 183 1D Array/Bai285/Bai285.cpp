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

void rev(int a[], int nA) {
	
	int b[MAX];
	
	int ptr = 0;
	for (int i = nA-1; i >= 0; --i) {
		b[ptr] = a[i];
		ptr++;
	}
	
	for (int i = 0; i < nA; ++i) {
		a[i] = b[i];
	}
	
}

void revPo(int a[], int nA) {
	
	int b[MAX];
	
	int ptr = 0;
	for (int i = nA-1; i >= 0; --i) {
		if (a[i] > 0) {
			b[ptr] = a[i];
			ptr++;
		}
	}
		
	ptr = 0;
	for (int i = 0; i < nA; ++i) {
		if (a[i] > 0) {
			a[i] = b[ptr];
			ptr++;
		}
	}
	
}

void solve(int a[], int nA) {
	
	revPo(a, nA);
	
	cout << "Dao nguoc so duong: " << endl;
	output(a, nA);
}

int main() {
	
	int a[MAX], nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}