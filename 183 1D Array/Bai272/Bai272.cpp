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

void delI(int a[], int nA, int b[], int index) {
	
	int down = 0;
	for (int i = 0; i < nA; ++i) {
		if (i != index) {
			b[i-down] = a[i];
		} else {
			down = 1;
		}
	}
}

void delN(int a[], int nA, int b[], int num, int &nB) {
	
	int down = 0;
	for (int i = 0; i < nA; ++i) {
		if (a[i] != num) {
			b[i-down] = a[i];
		} else {
			down++;
			nB--;
		}
	}
}

int maxArray(int a[], int nA) {
	
	int max = a[0];
	for (int i = 1; i < nA; ++i) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	
	return max;
}

void solve(int a[], int nA) {
	
	int b[MAX], nB = nA;
	
	int maxNum = maxArray(a, nA);
	delN(a, nA, b, maxNum, nB);
	
	cout << "Mang sau khi xoa gia tri lon nhat: " << endl;
	output(b, nB);
}

int main() {
	
	int a[MAX], nA;
	
	input(a, nA);
	solve(a, nA);
	
	
	return 0;
}