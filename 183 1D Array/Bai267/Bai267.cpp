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
		for (int i = 0; i < n; ++i) {
			a[i] = rand()%200-99;
		}
	}
	
	output(a, n);
}

void sort(int a[], int nA) {
	
	int temp;
	bool run = true;
	while(run) {
		run = false;
		
		for (int i = 0; i < nA-1; ++i) {
			if (a[i] < a[i+1]) {
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				run = true;
			}
		}
	}
	
}

void solve(int a[], int nA) {
		
	sort(a, nA);
	
	cout << "Sorted decrease array: " << endl;
	output(a, nA);
}

int main() {
	
	srand(time(NULL));
	int a[MAX], nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}