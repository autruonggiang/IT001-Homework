#include<iostream>
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

bool CD(int MTA[][MAX], int mA, int nA, int x, int y) {
    
    int root[] = {x, y};
    int num = MTA[x][y];
    x = (root[0]-1 < 0)? 0: root[0]-1;
    y = (root[1]-1 < 0)? 0: root[1]-1;
    
    int xMax, yMax;
    xMax = (root[0]+1 >= mA)? mA-1: root[0]+1;
    yMax = (root[1]+1 >= nA)? nA-1: root[1]+1;

    for (int i = x; i <= xMax; ++i) {
        for (int j = y; j <= yMax; ++j) {
            if (i != root[0] || j != root[1]) {
                if (MTA[i][j] >= MTA[root[0]][root[1]])
                    return false;
            }
        }
    }
    
    return true;
}

void countCD(int MTA[][MAX], int mA, int nA, int maxNumA) {
    
    drawMT(MTA, mA, nA, maxNumA);
    
    int count = 0;
    
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            if (CD(MTA, mA, nA, i, j)) {
                count++;
            }
        }
    }
    
    cout << "So phan tu cuc dai cua ma tran la: " << count << endl;
    
}

int main() {
	
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;

    int MTA[MAX][MAX];
    // int sum = 0;
    maxNumA = input(MTA, mA, nA);
    countCD(MTA, mA, nA, maxNumA);
    
    return 0;
}