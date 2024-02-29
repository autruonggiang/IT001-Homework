#include<iostream>
#include<iomanip>
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

int count(int MTA[][MAX], int mA, int nA, int x, int y) {
    
    int sum = 0;
    for (int i = x - 1; i < x + 2; ++i) {
        for (int j = y - 1; j < y + 2; ++j) {
            if (i >= 0 && j >= 0) {
                if (i != x || j != y) {
                    if (MTA[i][j] > 0)
                        sum++;
                }
            }
        }
    }
    return sum;
}

void createB(int MTA[][MAX], int mA, int nA, int maxNumA) {

    int MTB[MAX][MAX];
    int length = len(maxNumA);
    
    
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            MTB[i][j] = count(MTA, mA, nA, i, j);
        }
    }
    
    
    draw(length, nA);

    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            cout << setw(length) << MTB[i][j] << "|";
        }
        cout << endl;
    }

    draw(length, nA);
}

int main() {

    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;

    int MTA[MAX][MAX];
    for (int i = 0; i < mA; ++i) { // row
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) { // col
            cin >> MTA[i][j];
            // MTA[i][j] = i+j;

            if (i == 0 && j == 0) {maxNumA = MTA[i][j];}
            else {
                if (MTA[i][j] > maxNumA) {maxNumA = MTA[i][j];}
            }
        }
    }


    int length = len(maxNumA);
    draw(length, nA);

    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            cout << setw(length) << MTA[i][j] << "|";
        }
        cout << endl;
    }

    draw(length, nA);

    cout << "Ma tran B la: " << endl;

    createB(MTA, mA, nA, maxNumA);


    return 0;
}
