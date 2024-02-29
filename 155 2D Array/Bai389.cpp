#include<iostream>
#include<iomanip>
#define MAX 100


using namespace std;

bool SHT(int num) {
    
    int sum = 0;
    if (num > 1) {
        for (int i = 1; i < num; ++i) {
            if (num%i == 0) {
                sum += i;
            }
        }
        if (num == sum) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    

}

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
    
    int MT[MAX][MAX];
    
    for (int i = 0; i < m; ++i) {
        cout << "Nhap so thuc cua hang " << setw(len(m)) << i+1 << " : ";
        for (int j = 0; j < n; ++j) {
            cin >> MT[i][j];
            // MT[i][j] = i+j;

            if (i == 0 && j == 0) {maxNum = MT[i][j];}
            else {
                if (MT[i][j] > maxNum) {maxNum = MT[i][j];}
            }
            
            // cout << MT[i][j] << " ";
        }
        // cout << endl;
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
    
    
    int maxCount[m];
    for (int i = 0; i < m; ++i) {
        maxCount[i] = -1;
    }
    
    int count = 0;
    int max = 0;
    int dem = 0;
    for (int row = 0; row < m; row++) {
        count = 0;
        for (int col = 0; col < n; col++) {
            if (SHT(MT[row][col])) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            for (int i = 0; i < m; ++i) {
                maxCount[i] = -1;
            }
            dem = 0;
            maxCount[dem] = row;
            dem++;
        } else if (count == max) {
            maxCount[dem] = row;
            dem++;
        }
    }
    
    cout << "So hang co nhieu so hoan thien nhat la: ";
    for (int i = 0; i < dem; ++i) {
        if (maxCount[i] != -1)
            cout << maxCount[i] << ", ";
    }
	
    return 0;
}