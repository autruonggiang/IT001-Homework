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

void maxSumSubnet(int MTA[][MAX], int mA, int nA, int maxNumA) {
    
    int MTB[mA][nA];
    int maxMT[mA][nA];
    
    int sum;
    int max = 0;
    int delCol = -1, delRow = -1;
    
    int row = mA;
    // Xoa hang
    while (row--) {
        sum = 0;
        
        for (int i = 0; i < mA; ++i) {
            for (int j = 0; j < nA; ++j) {
                MTB[i][j] = MTA[i][j];
            }
        }
        
        for (int i = 0; i < nA; ++i) {
            MTB[row][i] = 0;
        }
        
        for (int i = 0; i < mA; ++i) {
            for (int j = 0; j < nA; ++j) {
                sum += MTB[i][j];
            }
        }
        
        if (sum > max) {
            delRow = row;
            max = sum;
            for (int i = 0; i < mA; ++i) {
                for (int j = 0; j < nA; ++j) {
                    maxMT[i][j] = MTB[i][j];
                }
            }
        }
    }
    
    int col = nA;
    // Xoa cot
    while (col--) {
        sum = 0;
        
        for (int i = 0; i < mA; ++i) {
            for (int j = 0; j < nA; ++j) {
                MTB[i][j] = MTA[i][j];
            }
        }
        
        for (int i = 0; i < mA; ++i) {
            MTB[i][col] = 0;
        }
        
        for (int i = 0; i < mA; ++i) {
            for (int j = 0; j < nA; ++j) {
                sum += MTB[i][j];
            }
        }
        
        if (sum > max) {
            delCol = col;
            delRow = -1;
            max = sum;
            for (int i = 0; i < mA; ++i) {
                for (int j = 0; j < nA; ++j) {
                    maxMT[i][j] = MTB[i][j];
                }
            }
        }
    }
    
    int length = len(maxNumA);
    
    if (delCol == -1)
        draw(length, nA);
    else
        draw(length, nA-1);
    
    
    for (int i = 0; i < mA; ++i) {
        if (delRow == -1) {
            for (int j = 0; j < nA; ++j) {
                if (delCol == -1) {
                    cout << setw(length) << maxMT[i][j] << "|";
                } else {
                    if (j != delCol) {
                        cout << setw(length) << maxMT[i][j] << "|";
                    }
                }
            }
            cout << endl;       
        } else {
            if (i != delRow) {
                for (int j = 0; j < nA; ++j) {
                    if (delCol == -1) {
                        cout << setw(length) << maxMT[i][j] << "|";
                    } else {
                        if (j != delCol) {
                            cout << setw(length) << maxMT[i][j] << "|";
                        }
                    }
                }
                cout << endl;   
            }
        }
    }
	
    if (delCol == -1)
        draw(length, nA);
    else
        draw(length, nA-1);
    
    
}

int main() {
    
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;
    
    // Tao ma tran A
    int MTA[MAX][MAX];
    
    for (int i = 0; i < mA; ++i) {
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) {
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
    
    cout << "Ma tran con co tong lon nhat la: " << endl;
    
	maxSumSubnet(MTA, mA, nA, maxNumA);
    
    return 0;
}