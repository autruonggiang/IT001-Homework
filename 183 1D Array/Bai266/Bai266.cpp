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

void add(int a[], int nA, int c[], int num, int index) {
	
	int down = 0;
	for (int i = 0; i < nA+1; ++i) {
		if (i == index) {
			c[i] = num;
			down++;
		} else {
			c[i] = a[i-down];
		}
	}
	
}

void solve(int a[], int nA) {
	
	int c[MAX];
	
	int num, index;
	cout << "Them gia tri x tai vi tri n (VD: 5 3): ";
	cin >> num >> index;
	
	add(a, nA, c, num, index);
	
	cout << "Them " << num << " vao vi tri " << index << ": " << endl;
	output(c, nA+1);
}

int main() {
	
	srand(time(NULL));
	int a[MAX], nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}