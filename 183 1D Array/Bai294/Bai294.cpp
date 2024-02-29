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

void subArray(int a[], int nA, int length) {
	for (int i = 0; i+length <= nA; ++i) {
		for (int j = i; j < i + length; ++j) {
			cout << a[j] << " ";
		}
		cout << endl;
	}
}

void solve(int a[], int nA) {
	
	cout << "Cac mang con co chieu dai hon 2 cua mang la: " << endl;
	for (int i = 2; i <= nA; ++i) {
		subArray(a, nA, i);
	}
		
}

int main() {
	
	int a[MAX];
	int nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}