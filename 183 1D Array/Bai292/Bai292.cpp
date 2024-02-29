#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

using namespace std;

void output(float a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void input (float a[], int &n, bool bug = false) {
	
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
			a[i] = ((rand()%200-99)*1.0)/(rand()%10+10*1.0);
		}
	}
	
	cout << "Mang A la: " << endl;
	output(a, n);
}

float round(float num) {
	
	int a = num;
	if (num - a >= 0.5) {
		return a+1;
	} else if (0 <= num - a && num - a < 0.5) {
		return a;
	} else if (num - a > -0.5) {
		return a;
	} else {
		return a-1;
	}
}

void solve(float a[], int nA) {
	
	for (int i = 0; i < nA; ++i) {
		a[i] = round(a[i]);
	}
	
	cout << "Dao nguoc thu tu min, max: " << endl;
	output(a, nA);
	
}

int main() {
	
	float a[MAX];
	int nA;
	
	input(a, nA, true);
	solve(a, nA);
	
	
	return 0;
}