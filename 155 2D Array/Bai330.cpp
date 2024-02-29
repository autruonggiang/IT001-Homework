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

void drawMT(float MTA[][MAX], int mA, int nA, int maxNumA) {
    
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

int input(float MTA[][MAX], int mA, int nA, bool bug = false) {
    
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


void transform(float MTA[][MAX], int mA, int nA, int maxNumA) {
    
    drawMT(MTA, mA, nA, maxNumA);
    
    int num;
    for (int col = 0; col < nA; ++col) {
        for (int row = 0; row < mA; ++row) {
            num = (int) MTA[row][col];
            if (MTA[row][col] >= 0) {
                if (MTA[row][col] - num >= 0.5)
                    MTA[row][col] = num + 1;
                else
                    MTA[row][col] = num;
            } else {
                if (MTA[row][col] - num <= -0.5)
                    MTA[row][col] = num - 1;
                else
                    MTA[row][col] = num;
            }
        }
    }
    
    cout << "Dua so thuc ve so nguyen gan nhat: " << endl;
    drawMT(MTA, mA, nA, maxNumA);
    
}

int main() {
	
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;

    float MTA[MAX][MAX];
    // int sum = 0;
    maxNumA = input(MTA, mA, nA);
    transform(MTA, mA, nA, maxNumA);
    
    return 0;
}