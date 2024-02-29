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

int near(int a[], int n, int index) {
	
	int sum = 0;
	int	start = (index - 1 >= 0) ? index - 1: 0,
		end = (index + 2 <= n)? index + 2: n;
	for (int i = start; i < end; ++i) {
		if (i != index) {
			sum += a[i];
		}
	}
	
	return sum;
}

void solve(int a[], int n) {
	
	int b[MAX];
	
	for (int i = 0; i < n; ++i) {
		b[i] = near(a, n, i);
	}
	
	cout << "Mang B la tong lan can cua A la: " << endl;
	output(b, n);
}

int main() {
	
	int a[MAX], n;
	
	input(a, n, true);
	solve(a, n);
	
	
	return 0;
}