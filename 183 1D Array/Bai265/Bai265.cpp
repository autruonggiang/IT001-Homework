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
	
	cout << "Do dai cua mang: ";
	cin >> n;
	
	if (!bug) {
		for (int i = 0; i < n; ++ i) {
			cout << "Gia tri cua a[" << i << "]: ";
			cin >> a[i];
		}
	} else {
		a[0] = rand()%200-99;
		for (int i = 1; i < n; ++i) {
			a[i] = rand()%200 + a[i-1];
		}
	}
	
	output(a, n);
}

void sort(int a[], int nA, int b[], int nB, int c[]) {
	
	for (int i = 0; i < nA; ++i) {
		c[i] = a[i];
	}
	
	for (int i = nA; i < nB+nA; ++i) {
		c[i] = b[i - nA];
	}
	
	int temp;
	bool run = true;
	while(run) {
		run = false;
		
		for (int i = 0; i < nA+nB-1; ++i) {
			if (c[i] < c[i+1]) {
				temp = c[i];
				c[i] = c[i+1];
				c[i+1] = temp;
				run = true;
			}
		}
	}
	
}

void solve(int a[], int nA, int b[], int nB) {
		
	int c[MAX];
	
	sort(a, nA, b, nB, c);
	
	cout << "Merged A and B: " << endl;
	output(c, nA+nB);
}

int main() {
	
	srand(time(NULL));
	int a[MAX], b[MAX], nA, nB;
	
	input(a, nA, true);
	input(b, nB, true);
	solve(a, nA, b , nB);
	
	
	return 0;
}