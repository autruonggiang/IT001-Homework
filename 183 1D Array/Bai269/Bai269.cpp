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

void solve(int a[], int nA) {
	
	int num;
	cout << "So ban muon them vao: ";
	cin >> num;
	
	int c[MAX];
	int down = 0;
	bool add = true;
	for (int i = 0; i < nA; ++i)  {
		if (i == 0) {
			if (num < a[i] && add) {
				c[i] = num;
				c[i+1] = a[i];
				down = -1;
				add = false;
			} else {
				c[i-down] = a[i];
			}
		} else if (i == nA - 1 && add) {
			if (num > a[i]) {
				c[i] = a[i];
				c[i+1] = num;
				add = false;
			} else {
				c[i-down] = a[i];
			}
		}
		if (num < a[i+1] && num > a[i] && add) {
			c[i] = a[i];
			c[i+1] = num;
			c[i+2] = a[i+1];
			down = -1;
			add = false;
		} else {
			c[i-down] = a[i];
		}
		// cout << i << ", " << add << ", " << c[i-down]<< endl;
		
	}
	
	output(c, nA+1);
}

int main() {
	
	srand(time(NULL));
	int a[MAX], nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}