#include<iostream>
#include<iomanip>
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
    
    int maxNumA;
    for (int i = 0; i < mA; ++i) { // row
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) { // col
            if (bug)
                MTA[i][j] = i+j;
            else
                cin >> MTA[i][j];

            if (i == 0 && j == 0) {maxNumA = MTA[i][j];}
            else {
                if (MTA[i][j] > maxNumA) {maxNumA = MTA[i][j];}
            }
            
            if (bug)
                cout << MTA[i][j] << " ";
        }
        if (bug)
            cout << endl;
    }
    
    return maxNumA;
}

bool SHT(int num) {
    
    int temp;
    
    int i = 2;
    while(true) {
        temp = pow(2, i-1) * (pow(2, i) - 1);
        if (temp > num)
            break;
        else if (temp == num)
            return true;
        
        i++;
    }
    
    return false;
}

void check(int MTA[][MAX], int mA, int nA, int maxNumA) {
    
    drawMT(MTA, mA, nA, maxNumA);
    
    int up = true;
    // Lap ma tran
    for (int row = 0; row < mA; ++row) { // Hang
        up = true;
        for (int col = 0; col < nA - 1; ++col) { // Cot
            if (MTA[row][col+1] - MTA[row][col] < 0) {
                up = false;
                break;
            }
        }   
        if (!up)
            cout << "Hang " << row + 1 << " khong tang dan." << endl;
        else 
            cout << "Hang " << row + 1 << " tang dan." << endl;
    }    
    
}

int main() {
	
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;

    int MTA[MAX][MAX];
    // int sum = 0;
    maxNumA = input(MTA, mA, nA);
    //drawMT(MTA, mA, nA, maxNumA);
    check(MTA, mA, nA, maxNumA);
    
    return 0;
}