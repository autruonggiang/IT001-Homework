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

bool max1D(int a[], int n, int jump, int pos[], int M) {
	
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum = 0;
		if (i+jump <= n) {
			for (int j = i; j < i + jump; ++j) {
				sum += a[j];
			}
			pos[0] = sum;
			pos[1] = i;
			pos[2] = i+jump;
			
			if (M == pos[0]) {
				return true;
			}
		}
	}
		
	return false;
}


void solve(int a[], int n) {
	
	
	int M;
	cout << "Nhap gia tri M: ";
	cin >> M;
		
	int pos[3];
	bool check = false;
	for (int i = 1; i <= n; ++i) {
		check = max1D(a, n, i, pos, M);
		if (check)
			break;
		
	}
	
	if (check) {
		cout << "Mang con cua A co tong bang M la: " << endl;
		for (int i = pos[1]; i < pos[2]; ++i) {
			cout << a[i] << " ";
		}
	} else {
		cout << "Khong co mang con nao cua A bang M";
	}
}

int main() {
	
	int a[MAX], n;
	
	input(a, n, true);
	solve(a, n);
	
	
	return 0;
}