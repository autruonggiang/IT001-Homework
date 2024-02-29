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

void solve(int a[], int nA) {
	
	bool check = false;
	
	int ptr;
	for (int i = 0; i < nA; ++i) {
		if (a[i] == 1) {
			check = true;
			ptr = i;
			break;
		}
	}
	
	int temp;
	for (int i = ptr; i > 0; --i) {
		temp = a[i-1];
		a[i-1] = a[i];
		a[i] = temp;
	}
	
	if (check)
		cout << "Mang sau khi dua so 1 ve dau: " << endl;
	else
		cout << "Mang khong co so 1: " << endl;
	output(a, nA);
}

int main() {
	
	int a[MAX], nA;
	
	input(a, nA);
	solve(a, nA);
	
	
	return 0;
}