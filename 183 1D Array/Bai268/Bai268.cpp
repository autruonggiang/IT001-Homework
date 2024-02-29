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
			a[i] = rand()%2;
		}
	}
	
	output(a, n);
}

bool check(int num) {
	if (num % 2 == 0)
		return true;
	return false;
}

void sort(int a[], int nA) {
	
	int b[MAX];
	
	int dem = 0;
	for (int i = 0; i < nA; ++i) {
		if (check(a[i])) {
			b[dem] = a[i];
			dem++;
		}
	}
	
	for (int i = 0; i < nA; ++i) {
		if (!check(a[i])) {
			b[dem] = a[i];
			dem++;
		}
	}
	
	for (int i = 0; i < nA; ++i) {
		a[i] = b[i];
	}
	
}


void solve(int a[], int nA) {
	
	sort(a, nA);
	
	cout << "Tao mang chan le: " << endl;
	output(a, nA);
}

int main() {
	
	srand(time(NULL));
	int a[MAX], nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}