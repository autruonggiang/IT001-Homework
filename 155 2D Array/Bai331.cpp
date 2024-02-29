#include<iostream>
#include<iomanip>

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

int main() {
    
    int m, n;
    int maxNum;
    cout << "Ma tran m*n - hang*cot (VD: 5 3): ";
    cin >> m >> n;
    float MT[m][n];
    
    for (int i = 0; i < m; ++i) {
        cout << "Nhap so thuc cua hang " << setw(len(m)) << i+1 << " : ";
        for (int j = 0; j < n; ++j) {
            cin >> MT[i][j];

            if (i == 0 && j == 0) {maxNum = MT[i][j];}
            else {
                if (MT[i][j] > maxNum) {maxNum = MT[i][j];}
            }
            
            //cout << MT[i][j] << " " << endl;
        }
    }
    
    int length = len(maxNum);
    
    draw(length, n);
    
    float sum = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(length) << MT[i][j] << "|";
            sum += MT[i][j];
        }
        cout << " = " << sum << endl;
        sum = 0;
    }
	
    draw(length, n);
	
    return 0;
}