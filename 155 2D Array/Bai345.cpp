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

bool SCT(int MT[][MAX], int num, int a, int b, int m, int n) {

    bool small;
    int a1, b1, a2, b2;
    a1 = (a-1 >= 0)? a-1: 0;
    b1 = (b-1 >= 0)? b-1: 0;
    a2 = (a+2 >= m)? m: a+2;
    b2 = (b+2 >= n)? n: b+2;
    
    for (int i = a1; i < a2; ++i) {
        for (int j = b1; j < b2; ++j) {
            if (i != a || j != b) {
                if (i ==  a1 && j == b1) {
                    if (MT[i][j] > num) {
                        small = false;
                    } else {
                        small = true;
                    }
                } else {
                    if (MT[i][j] > num) {
                        if (small) {return false;}
                    } else if (MT[i][j] < num) {
                        if (!small) {return false;}
                    } else {
                        return false;
                    }
                }
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
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(SCT(MT, MT[i][j], i, j, m, n)) {sum += MT[i][j];}
        }
    }
    
    cout << "Tong cac phan tu cuc tri: " << sum << endl;
	
    return 0;
}
