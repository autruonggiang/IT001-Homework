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

int sum(int MTA[][MAX], int mA, int nA, int maxNumA) {    
    int sum = 0;
    for (int i = 0; i < mA; ++i) {
        if (i == 0 || i == mA - 10) {
            for (int j = 0; j < nA; ++j) {
                if (j == 0 || j == nA - 1) {
                    sum += MTA[i][j];
                }
            }
        }
    }
    
    return sum;
}

int main() {

    int mA, nA;
    int maxNumA;
    cout << "Ma tran A vuong m*n - hang*cot (VD: 5 3): ";
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

    cout << "Tong cac so chan tren bien cua ma tran tren la: ";

    cout << sum(MTA, mA, nA, maxNumA);


    return 0;
}
