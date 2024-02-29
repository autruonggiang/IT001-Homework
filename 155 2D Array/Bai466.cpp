#include<iostream>
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#define MAX 100

using namespace std;

void draw(int length, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < length; ++j) {
            cout << "-";
        }
        cout << "+";
    }
    cout << endl;   
}

int len(int num) {
    
    int a = 1;
    while(num /= 10) {
        a++;
    }
    
    return a;
}

int input(int MTA[][MAX], int mA, int nA, bool bug = false) {
    
    srand(time(NULL));
    
    int maxNumA, temp;
    for (int i = 0; i < mA; ++i) { // row
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) { // col
            if (bug)
                MTA[i][j] = rand()%200-99;
            else
                cin >> MTA[i][j];

            if (i == 0 && j == 0) {maxNumA = MTA[i][j];}
            else {
                if (MTA[i][j] > maxNumA) {
                    maxNumA = MTA[i][j];
                } else if (MTA[i][j] < 0) {
                    temp = MTA[i][j];
                    temp *= -1;
                    if (len(temp) >= len(maxNumA)) {
                        maxNumA = temp * 10;
                    }
                }
            }
            
            if (bug)
                cout << MTA[i][j] << " ";
        }
        if (bug)
            cout << endl;
    }
    
    return maxNumA;
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while(true) {
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void drawMT(int MTA[][MAX], int mA, int nA, int maxNumA) {
    
    int length = len(maxNumA);
    
    draw(length, nA);
    
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            cout << setw(length) << MTA[i][j] << "|";
        }
        cout << endl;
    }
    
    draw(length, nA);
    
}

int sumMT(int MT[][MAX], int m, int n, int root[2], int size[2]) {
    
    int sum = 0;
    for (int i = root[0]; i < root[0] + size[0]; ++i) {
        if (i < m) {
            for (int j = root[1]; j < root[1] + size[1]; ++j) {
                if (j < n)
                    sum += MT[i][j];
            }            
        }
    }
    
    
    return sum;
}

void transform(int MTA[][MAX], int mA, int nA, int maxNumA) {
    int MT[MAX];
    
    int ptr = 0;
    for (int i = 0; i < mA; ++i) {
        for (int j = i; j >= 0; --j) {
            if (i != j) {
                MT[ptr] = MTA[i][j];
                ptr++;
            }
        }
    }
    
    quickSort(MT, 0, ptr-1);
    
    ptr = 0;
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i != j) {
                MTA[i][j] = MT[ptr];
                ptr++;
            }
        }
    }
    
    cout << "Ma tran sau khi sap xep lai:" << endl;
    drawMT(MTA, mA, nA, maxNumA);
}

int main() {
    
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A vuong m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;
    
    // Tao ma tran A
    int MTA[MAX][MAX];
    
    maxNumA = input(MTA, mA, nA);

    drawMT(MTA, mA, nA, maxNumA);
    transform(MTA, mA, nA, maxNumA);
    
    
    return 0;
}