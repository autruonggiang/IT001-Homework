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

void down(int MTA[][MAX], int mA, int nA) {

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
    for (int i = mA*nA - 1; i >= 0; --i) {
        MTA[row][col] = list[i];
        col++;
        if (col == nA) {
            row++;
            col = 0;
        }
    }
}


void xuat(int MTA[][MAX], int mA, int nA, int maxNumA) {

    int MTB[MAX][MAX];
    
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            MTB[i][j] = MTA[i][j];
        }
    }
    
    down(MTB, mA, nA);
    
    bool exist = false;
    cout << "Cac gia tri am trong ma tran giam dan la: " << endl;
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nA; ++j) {
            if (MTB[i][j] < 0) {
                exist = true;
                cout << MTB[i][j] << ", ";
            }
        }
    }
    
    
    if (!exist) {
        cout << "Khong co so thuc am trong ma tran.";
    }
}

int main() {

    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;

    int MTA[MAX][MAX];
    for (int i = 0; i < mA; ++i) { // row
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) { // col
            cin >> MTA[i][j];
            // MTA[i][j] = i-j;

            if (i == 0 && j == 0) {maxNumA = MTA[i][j];}
            else {
                if (MTA[i][j] > maxNumA) {maxNumA = MTA[i][j];}
            }
        }
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

    xuat(MTA, mA, nA, maxNumA);


    return 0;
}
