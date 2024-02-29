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

void max1D(int a[], int n, int jump, int pos[]) {
	
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum = 0;
		if (i+jump <= n) {
			for (int j = i; j < i + jump; ++j) {
				sum += a[j];
			}
			if (i == 0) {
				pos[0] = sum;
				pos[1] = i;
				pos[2] = i+jump;
			}
			else if (sum > pos[0]) {
				pos[0] = sum;
				pos[1] = i;
				pos[2] = i+jump;
			}
		}
	}
}


void solve(int a[], int n) {
		
	int start = 0,
		end = 1;
	int max = a[0];
	int pos[3];
	for (int i = 1; i <= n; ++i) {
		max1D(a, n, i, pos);
		if (pos[0] > max) {
			max = pos[0];
			start = pos[1];
			end = pos[2];
		}
		
	}
	
	cout << "Mang con co tong lon nhat cua A la: " << endl;
	for (int i = start; i < end; ++i) {
		cout << a[i] << " ";
	}
}

int main() {
	
	int a[MAX], n;
	
	input(a, n, true);
	solve(a, n);
	
	
	return 0;
}