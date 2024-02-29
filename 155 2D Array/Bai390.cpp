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

void lietkecot(int MTA[][MAX], int mA, int nA) {
    int maxCol[nA];
    int maxLenght = 0;
    int length;
    
    // Tao list rong
    for (int i = 0; i < nA; ++i) {
        maxCol[i] = 0;
    }
    
    for (int col = 0; col < nA; ++col) {
        for (int row = 0; row < mA; ++row) {
            length = len(MTA[row][col]);
                
            if(length > maxLenght) {
                for (int i = 0; i < nA; ++i) {
                    maxCol[i] = 0;
                }
                
                maxLenght = length;
                maxCol[col] = 1;
            } else if (length == maxLenght) {
                maxCol[col] = 1;
            }
        }
    }
    
    for (int i = 0; i < nA; ++i) {
        if (maxCol[i] == 1) {
            cout << i+1;
            if (i < nA-1) cout << ", ";
        }
    }
}

int main() {
    
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;
    
    // Tao ma tran A
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
            
            // cout << MTA[i][j] << " ";
        }
        // cout << endl;
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
    
    
    cout << "So cot co nhieu chu so nhat la: ";
    lietkecot(MTA, mA, nA);
    
    return 0;
}