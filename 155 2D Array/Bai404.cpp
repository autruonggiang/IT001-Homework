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

void rotate(int MTA[][MAX], int mA, int nA, int degree, int maxNumA) {
    int temp;
    int max = (mA>nA)? mA:nA;
    int MTB[max][max];
    int tempMT[max][max];
    
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            tempMT[i][j] = MTA[i][j];
        }
    }
    
    
    int row = mA, col = nA;
    int demRow, demCol;
    degree+=90;
    while(degree -= 90) {
        temp = row;
        row = col;
        col = temp;
        
        demRow = 0;
        for (int j = row-1; j >= 0; --j) {
            demCol = 0;
            for (int i = 0; i < col; ++i) {
                MTB[demRow][demCol] = tempMT[i][j];
                demCol++;
            }
            demRow++;
        }
        
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                tempMT[i][j] = MTB[i][j];
            }
        }
    }
    
    int length = len(maxNumA);
    draw(length, col);
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(length) << MTB[i][j] << "|";
        }
        cout << endl;
    }
    
    draw(length, col);
    
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
            //MTA[i][j] = i+j;

            if (i == 0 && j == 0) {maxNumA = MTA[i][j];}
            else {
                if (MTA[i][j] > maxNumA) {maxNumA = MTA[i][j];}
            }
            
            //cout << MTA[i][j] << " ";
        }
        //cout << endl;
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

    int degree;
    cout << "So goc can xoay (Boi cua 90): ";
    cin >> degree;
    
    rotate(MTA, mA, nA, degree, maxNumA);
    
    return 0;
}