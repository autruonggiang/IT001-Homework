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

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
 
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while(true) {
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void up(int MTA[][MAX], int mA, int nA) {
    
    int list[mA*nA];
    
    int row = 0, col = 0;
    for (int i = 0; i < mA*nA; ++i) {
        list[i] = MTA[row][col];
        col++;
        if (col == nA) {
            row++;
            col = 0;
        }
    }
    
    quickSort(list, 0, mA*nA-1);
    
    row = 0;
    col = 0;
    for (int i = 0; i < mA*nA; ++i) {
        MTA[row][col] = list[i];
        col++;
        if (col == nA) {
            row++;
            col = 0;
        }
    }
}

void transform(int MTA[][MAX], int mA, int nA, int maxNumA) {
    
    int PATH[mA][nA];
    
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            PATH[i][j] = 0;
        }
    }
    
    int MTB[mA][nA];
    
    int row = 0, col = 0;
    bool stop = false;
    bool end = true;
    while (true) {
        
        stop = false;    
        for (int i = 0; i < mA; ++i) {
            for (int j = 0; j < nA; ++j) {
                if (PATH[i][j] != 1) {
                    stop = true;
                    PATH[i][j] = 1;
                    MTB[i][j] = MTA[row][col];
                    col++;
                    if (col == nA) {
                        row++;
                        col = 0;
                    }
                }
            }
            if (stop) {
                break;
            }
        }
        
        stop = false;
        for (int j = nA - 1; j >= 0; --j) {
            for (int i = 0; i < mA; ++i) {
                if (PATH[i][j] != 1) {
                    stop = true;
                    PATH[i][j] = 1;
                    MTB[i][j] = MTA[row][col];
                    col++;
                    if (col == nA) {
                        row++;
                        col = 0;
                    }
                }
            }
            if (stop) {
                break;
            }
        }
        
        stop = false;
        for (int i = mA - 1; i >= 0; --i) {
            for (int j = nA - 1; j >= 0; --j) {
                if (PATH[i][j] != 1) {
                    stop = true;
                    PATH[i][j] = 1;
                    MTB[i][j] = MTA[row][col];
                    col++;
                    if (col == nA) {
                        row++;
                        col = 0;
                    }
                }
            }
            if (stop) {
                break;
            }
        }
        
        stop = false;
        for (int j = 0; j < nA; ++j) {
            for (int i = mA - 1; i >= 0; --i) {
                if (PATH[i][j] != 1) {
                    stop = true;
                    PATH[i][j] = 1;
                    MTB[i][j] = MTA[row][col];
                    col++;
                    if (col == nA) {
                        row++;
                        col = 0;
                    }
                }
            }
            if (stop) {
                break;
            }
        }
        
        end = true;
        for (int i = 0; i < mA; ++i) {
            for (int j = 0; j < nA; ++j) {
                if (PATH[i][j] != 1) {
                    end = false;
                    break;
                }   
            }
            if (!end) {
                break;
            }
        }
        
        if (end) {
            break;
        }        
        
    }
    
    int length = len(maxNumA);
    
    draw(length, nA);
    
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            cout << setw(length) << MTB[i][j] << "|";
        }
        cout << endl;
    }
    
    draw(length, nA);
    
    
}

int main() {
    
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;
    
    int MTA[MAX][MAX];
    // int sum = 0;
    for (int i = 0; i < mA; ++i) { // row
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) { // col
            cin >> MTA[i][j];
            // MTA[i][j] = i+j;
            // sum++;

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

    cout << "Ma tran hinh xoan oc tang dan" << endl;
    
    up(MTA, mA, nA);
    transform(MTA, mA, nA, maxNumA);
    

    return 0;
}