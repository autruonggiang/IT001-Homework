#include<iostream>
#include<iomanip>

using namespace std;

int** createMT(int N, int n);
int** createMT(int n);
int** createMPLe(int N, int n);
int** createMP4n(int n);
int** createMP4n_2(int n);
void swap(int **MT, int N, int n);
void drawMP(int **MT, int n, int maxNum);

int main() {
    int n;
    cout << "Ma phuong bac (n*n): ";
    cin >> n;
    
    int N = (n-1) + n;
    int maxNum = n*n;
    
    
    int **MP;
    if (n%2 == 1) {
        MP = createMPLe(N, n);
    } else if (n%4 == 0) {
        MP = createMP4n(n);
    } else {
        MP = createMP4n_2(n);
    }
    
    drawMP(MP, n, maxNum);
    
    return 0;
}

int** createMT(int N, int n) {
    int **MT;
    MT = new int *[N];
    for (int i = 0; i < N; ++i) {
        MT[i] = new int[N];
    }
    
    int root = (N - 1)/2;
    int num = 0;
    int col, row;
    for(int i = 0; i < n; ++i) {
        col = root;
        row = i;
        while(true) {
            num++;
            MT[row][col] = num;
            col--;
            row++;
            if(num % n == 0) {break;}
        }
        root++;
    }
    
    return MT;
}

int** createMT(int n) {
    int **MT;
    MT = new int *[n];
    for (int i = 0; i < n; ++i) {
        MT[i] = new int[n];
    }
    
    return MT;
}

void swap(int **MT, int N, int n) {
    
    int length = (N - n)/2;
    int mid = (N - 1)/2;
    N--;
    
    // Swap up -> down
    for (int i = 0; i < length; ++i) {
        for(int j = mid - i; j <= mid + i; j = j + 2) {
            MT[i+n][j] = MT[i][j];
        }
    }
    
    // Swap down -> up
    for (int i = 0; i < length; ++i) {
        for(int j = mid - i; j <= mid + i; j = j + 2) {
            MT[N-i-n][j] = MT[N-i][j];
        }
    }
    
    // Swap left -> right
    for (int i = 0; i < length; ++i) {
        for(int j = mid - i; j <= mid + i; j = j + 2) {
            MT[j][i+n] = MT[j][i];
        }
    }
    
    // Swap right -> left
    for (int i = 0; i < length; ++i) {
        for(int j = mid - i; j <= mid + i; j = j + 2) {
            MT[j][N-i-n] = MT[j][N-i];
        }
    }
}

int** createMPLe(int N, int n) {
    
    int **MT, **MP;
    
    MT = createMT(N, n);
    swap(MT, N, n);
    
    MP = createMT(n);
    
    int plus = (N-n)/2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            MP[i][j] = MT[i+plus][j+plus];
        }
    }
    
    return MP;
}

int** createMP4n(int n) {
    int **MP;
    MP = createMT(n);
    
    int num = 1;
    int check = -1;
    int checkRow = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (checkRow == -1 || i == n-1 || checkRow >= 2) {
                if (check == -1 || j == n-1) {
                    MP[i][j] = num;
                } else {
                    if (check >= 2) {
                        MP[i][j] = num;
                    } else {
                        MP[n-i-1][n-j-1] = num;
                    }
                }
            } else {
                if (check < 2 && check >= 0) {
                    MP[i][j] = num;
                } else {
                    MP[n-i-1][n-j-1] = num;
                }
            }
                
            if (check == 3) {
                check = -1;
            }
            check++;
            num++;
        }
        
        if (checkRow == 3) {
            checkRow = -1;
        }
        check = -1;
        checkRow++;
    }
    
    return MP;
}

int** createMP4n_2(int n) {
    
    int n1 = n/2;
    int N = (n1-1) + n1;
    int a = (n/2 - 1)/2;
    
    int **MT;
    MT = createMPLe(N, n1);
    
    int **MP;
    MP = createMT(n);
    
    int select;
    
    // Dang L
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j < n1; ++j) {
            select = MT[i][j];
            
            if (i != a && j != (n1-1)/2) {
                MP[i*2][j*2] = select*4;
                MP[i*2][j*2 + 1] = (select-1)*4 + 1;
                MP[i*2 + 1][j*2] = (select-1)*4 + 2;
                MP[i*2 + 1][j*2 + 1] = (select-1)*4 + 3;
            } else {
                MP[i*2][j*2] = (select-1)*4 + 1;
                MP[i*2][j*2 + 1] = select*4;
                MP[i*2 + 1][j*2] = (select-1)*4 + 2;
                MP[i*2 + 1][j*2 + 1] = (select-1)*4 + 3;
            }
        }
    }
    
    // Dang U
    for (int i = a+1; i <= a+1; ++i) {
        for (int j = 0; j < n1; ++j) {
            select = MT[i][j];
            
            if (j != (n1-1)/2) {
                MP[i*2][j*2] = (select-1)*4 + 1;
                MP[i*2][j*2 + 1] = select*4;
                MP[i*2 + 1][j*2] = (select-1)*4 + 2;
                MP[i*2 + 1][j*2 + 1] = (select-1)*4 + 3;
            } else {
                MP[i*2][j*2] = select*4;
                MP[i*2][j*2 + 1] = (select-1)*4 + 1;
                MP[i*2 + 1][j*2] = (select-1)*4 + 2;
                MP[i*2 + 1][j*2 + 1] = (select-1)*4 + 3;
            }
        }
    }
    
    // Dang X
    for (int i = a+2; i < n1; ++i) {
        for (int j = 0; j < n1; ++j) {
            select = MT[i][j];
            
            MP[i*2][j*2] = (select-1)*4 + 1;
            MP[i*2][j*2 + 1] = select*4;
            MP[i*2 + 1][j*2] = (select-1)*4 + 3;
            MP[i*2 + 1][j*2 + 1] = (select-1)*4 + 2;
        }
    }
    
    return MP;
}

void drawMP(int **MT, int n, int maxNum) {
    
    int length = 1;
    while(maxNum /= 10) {
        length++;
    }
    
    for(int i = 0; i < n; ++i) {
        cout << "|";
        for(int j = 0; j < n; ++j) {
            cout << setw(length) << MT[i][j] << "|";
        }
        cout << endl;
    }
}
