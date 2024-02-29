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

void del(int a[], int nA, int b[], int index) {
	
	int down = 0;
	for (int i = 0; i < nA; ++i) {
		if (i != index) {
			b[i-down] = a[i];
		} else {
			down = 1;
		}
	}
}


void solve(int a[], int nA) {
	
	int b[MAX];
	int index;
	cout << "Chi so muon xoa: ";
	cin >> index;
	
	del(a, nA, b, index);
	
	output(b, nA-1);
}

int main() {
	
	int a[MAX], nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}