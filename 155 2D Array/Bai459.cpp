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

bool maphuong(int MTA[][MAX], int mA, int nA, int maxNumA) {
        
    int M = (nA*(nA*nA+1))/2;
    int sum;
    
    // Hang
    for (int i = 0; i < mA; ++i) {
        sum = 0;
        for (int j = 0; j < nA; ++j) {
            sum += MTA[i][j];
        }
        if (sum != M)
            return false;
    }
    
    // Cot
    for (int j = 0; j < nA; ++j) {
        sum = 0;
        for (int i = 0; i < mA; ++i) {
            sum += MTA[i][j];
        }
        if (sum != M)
            return false;
    }
    
    // Cheo
    sum = 0;
    for (int j = 0; j < nA; ++j) {
        sum += MTA[j][j];
    }
    if (sum != M)
        return false;
    
    sum = 0;
    for (int j = nA-1; j >= 0; --j) {
        sum += MTA[j][j];
    }
    if (sum != M)
        return false;
    
    
    return true;
}

int main() {
    
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A vuong m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;
    
    // Tao ma tran A
    int MTA[MAX][MAX];
    
    for (int i = 0; i < mA; ++i) {
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) {
            cin >> MTA[i][j];
            // MTA[i][j] = i+j;

            if (i == 0 && j == 0) {
                maxNumA = MTA[i][j];
            }
            else {
                if (MTA[i][j] > maxNumA) {maxNumA = MTA[i][j];}
            }
        }
    }

    drawMT(MTA, mA, nA, maxNumA);
 
    if (maphuong(MTA, mA, nA, maxNumA))
        cout << "Ma tran tren la ma phuong";
    else
        cout << "Ma tran tren khong la ma phuong";
    
    
    return 0;
}