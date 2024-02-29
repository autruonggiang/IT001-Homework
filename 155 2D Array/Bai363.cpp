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

bool LK(int MT[][MAX], int a,int m, int n) {
    
    int temp;
    
    for (int j = 0; j < m; ++j) {
        if (j == 0) {
            temp = MT[j][a];
        } else {
            if (temp < MT[j][a]) {
                temp = MT[j][a];
            } else {
                return false;
            }
        }
    }
    
    return true;
}


int main() {
    
    int m, n;
    int maxNum;
    cout << "Ma tran m*n - hang*cot (VD: 5 3): ";
    cin >> m >> n;
    
    int MT[MAX][MAX];
    
    for (int i = 0; i < m; ++i) {
        cout << "Nhap so thuc cua hang " << setw(len(m)) << i+1 << " : ";
        for (int j = 0; j < n; ++j) {
            cin >> MT[i][j];
            //MT[i][j] = i+j;

            if (i == 0 && j == 0) {maxNum = MT[i][j];}
            else {
                if (MT[i][j] > maxNum) {maxNum = MT[i][j];}
            }
            
            //cout << MT[i][j] << " ";
        }
        //cout << endl;
    }
    
    int length = len(maxNum);
    
    draw(length, n);
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(length) << MT[i][j] << "|";
        }
        cout << endl;
    }
	
    draw(length, n);
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if(LK(MT, i, m, n)) {sum ++;}
    }
    
    cout << "Tong so cot tang dan la: " << sum << endl;
	
    return 0;
}