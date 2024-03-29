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

void delI(int a[], int nA, int index) {
	
	int b[MAX];
	
	int down = 0;
	for (int i = 0; i < nA; ++i) {
		if (i != index) {
			b[i-down] = a[i];
		} else {
			down++;
		}
	}
	
	nA -= down;
	for (int i = 0; i < nA; ++i) {
		a[i] = b[i];
	}
}

void delN(int a[], int &nA, int num) {
	
	int b[MAX];
	
	int down = 0;
	for (int i = 0; i < nA; ++i) {
		if (a[i] != num) {
			b[i-down] = a[i];
		} else {
			down++;
		}
	}
	
	nA -= down;
	for (int i = 0; i < nA; ++i) {
		a[i] = b[i];
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

bool SCP(int num) {
	
	for (int i = 1; i*i <= num; ++i) {
		if (i*i == num)
			return true;
	}
	
	return false;
}

bool SNT(int num) {
	
	if (num <=0)
		return false;
	
	for (int i = 2; i < num; ++i) {
		if (num%i == 0)
			return false;
	}
	
	return true;
}

void solve(int a[], int nA) {
	
	int b[MAX], nB = nA;
	
	for (int i = 0; i < nA; ++i) {
		b[i] = a[i];
	}
	
	for(int i = 0; i < nB; ++i) {
		if (SNT(b[i]))
			delN(a, nA, b[i]);
	}
	
	cout << "Mang sau khi xoa cac so nguyen to: " << endl;
	output(a, nA);
}

int main() {
	
	int a[MAX], nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}