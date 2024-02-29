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

bool check(int a[], int nA, int b[], int nB, int index) {
	
	if (index+nA <= nB) {
		for (int i = index; i < index+nA; ++i) {
			if (a[i - index] != b[i]) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}


void solve(int a[], int nA, int b[], int nB) {
	
	int count = 0;
	for (int i = 0; i < nB; ++i) {
		if (check(a, nA, b, nB, i)) {
			count++;
			break;
		}
	}
	
	if (count == 0)
		cout << "Mang A khong la mang con cua B";
	else
		cout << "Mang A la mang con cua B";
}

int main() {
	
	int a[MAX], nA;
	int b[MAX], nB;
	
	input(a, nA, true);
	input(b, nB, true);
	solve(a, nA, b, nB);
	
	
	return 0;
}