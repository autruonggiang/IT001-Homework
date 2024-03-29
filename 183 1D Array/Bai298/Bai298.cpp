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

bool increase(int a[], int nA) {
	for (int i = 0; i < nA; ++i) {
		if (a[i] > a[i+1])
			return false;
	}
	
	return true;
}

int maxArray(int a[], int nA) {
	
	int max = a[0];
	for (int i = 1; i < nA; ++i) {
		if (a[i] > max)
			max = a[i];
	}
	
	return max;
}

bool in(int a[], int nA, int num) {
	
	for (int i = 0; i < nA; ++i) {
		if (a[i] == num)
			return true;
	}
	
	return false;
}

int sumArray(int a[], int nA) {
	int sum = 0;
	for (int i = 0; i < nA; ++i) {
		sum += a[i];
	}
	
	return sum;
}

int subArray(int a[], int nA, int length) {
	
	int b[MAX], ptr;
	
	int count = 0;
	for (int i = 0; i+length <= nA; ++i) {
		ptr = 0;
		for (int j = i; j < i + length; ++j) {
			b[ptr] = a[j];
			ptr++;
		}
		
		if (increase(b, ptr)) {
			count++;
		}
	}
	
	return count;
}

void solve(int a[], int nA) {
	
	int count = 0;
	for (int i = 2; i <= nA; ++i) {
		count += subArray(a, nA, i);
	}
	
	cout << "Co so luong mang con tang co do dai lon hon 1 la: " << count;
}

int main() {
	
	int a[MAX];
	int nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}