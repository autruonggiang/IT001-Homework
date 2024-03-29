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

int Subnet(int MTA[][MAX], int MTB[][MAX], int mA, int nA, int mB, int nB) {
    
    // Create rootList
    int rootList[mB][nB];
    for (int i = 0; i < mB; ++i) {
        for (int j = 0; j < nB; j++) {
            rootList[i][j] = 0;
        }
    }
    
    for (int i = 0; i < mB; ++i) {
        for (int j = 0; j < nB; j++) {
            if (MTA[0][0] == MTB[i][j]) {
                rootList[i][j] = 1;
            }
        }
    }
    
    int blackList[mB][nB];
    int whiteList[mB][nB];
    int count = 0;
    int countMT = 0;
    int startFlag[2] = {mA, nA};
    int tempCol, tempRow;
    
    bool next = false;
    bool stop = false;
    bool exist = false;
    bool dup = true;
    
    int countA = 0;
    // Loop rootList
    for (int rowRoot = 0; rowRoot < mB; ++rowRoot) {
        for (int colRoot = 0; colRoot < nB; ++colRoot) {
            if (rootList[rowRoot][colRoot] == 1) {
                startFlag[1] = nA;
                startFlag[1] = mA;
                
                
                // Reset blackList
                for (int i = 0; i < mB; ++i) {
                    for (int j = 0; j < nB; ++j) {
                        blackList[i][j] = 0;
                    }
                }    

                // Reset whiteList
                for (int i = 0; i < mB; ++i) {
                    for (int j = 0; j < nB; ++j) {
                        whiteList[i][j] = 0;
                    }
                } 
                
                
                stop = false;
                while (true) {
                    
                    // Reset whiteList
                    for (int i = 0; i < mB; ++i) {
                        for (int j = 0; j < nB; ++j) {
                            whiteList[i][j] = 0;
                        }
                    }   
                    
                    // Init whiteList
                    countA = 0;
                    tempCol = colRoot;
                    for (int colA = 0; colA < nA; ++colA) {
                        for (int colB = tempCol; colB < nB; ++colB) {
                            if (MTB[rowRoot][colB] == MTA[0][colA]) {
                                if (blackList[rowRoot][colB] == 0 && whiteList[rowRoot][colB] == 0) {
                                    tempCol = colB + 1;
                                    countA++;
                                    whiteList[rowRoot][colB] = 1;
                                    break;
                                } else {
                                    blackList[rowRoot][colB] = 1;
                                }
                            }
                        }
                    }
                    
                    // Next root if not exist row A[0] in B
                    if (countA != nA && startFlag[1] == 1) {
                        stop = true;
                        break;
                    }
                    
                    countA = 0;
                    tempRow = rowRoot + 1;
                    for (int rowA = 0; rowA < mA; ++rowA) {
                        for (int rowB = tempRow; rowB < mB; ++rowB) {
                            if (MTB[rowB][colRoot] == MTA[rowA][0]) {
                                if (blackList[rowB][colRoot] == 0 && whiteList[rowB][colRoot] == 0) {
                                    tempRow = rowB + 1;
                                    countA++;
                                    whiteList[rowB][colRoot] = 1;
                                    break;
                                } else {
                                    blackList[rowB][colRoot] = 1;
                                }
                            }
                        }
                    }
                    
                    // Next root if not exist col A[0] in B
                    if (countA != mA && startFlag[0] == 1) {
                        stop = true;
                        break;
                    }

                    if (stop) {
                        break;
                    }
                    
                    // Check A in B
                    count = 0;
                    for (int rowA = 0; rowA < mA; ++rowA) {
                        for (int colA = 0; colA < nA; ++colA) {
                            next = false;
                            for (int rowB = rowRoot; rowB < mB; ++rowB) {
                                if (whiteList[rowB][colRoot] == 1) {
                                    for (int colB = colRoot; colB < nB; ++colB) {
                                        if (whiteList[rowRoot][colB] == 1) {
                                            if (MTA[rowA][colA] == MTB[rowB][colB]) {
                                                count++;
                                                next = true;
                                                break;
                                            }
                                        }
                                    }
                                    if (next) {
                                        break;
                                    }
                                }
                            }
                        }
                    // End check
                    }
                    
                    if (count == mA*nA) {
                        countMT++;
                    }
                    
                    // Init blackList
                    dup = true;
                    while (dup && startFlag[1] != 1) {
                        exist = false;
                        for (int colA = nA-1; colA > 0; --colA) {
                            for (int colB = colRoot; colB < nB; ++colB) {
                                if (MTA[0][colA] == MTB[rowRoot][colB] && blackList[rowRoot][colB] == 0) {
                                    blackList[rowRoot][colB] = 1;
                                    if (blackList[rowRoot][colB] == whiteList[rowRoot][colB]) {
                                        dup = false;
                                    }
                                    exist = true;
                                    break;
                                }
                            }
                            if (!exist) {
                                // Reset blackList
                                for (int i = 0; i < nB; ++i) {
                                    blackList[rowRoot][i] = 0;
                                }
                                
                                startFlag[1]--;                                
                            } else {
                                break;
                            }
                        }
                        
                        if (dup) {
                            for (int i = 0; i < nB; ++i) {
                                if (whiteList[rowRoot][i] == 0) {
                                    blackList[rowRoot][i] = 1;
                                }
                            }
                        }
                    }

                    dup = true;
                    while(dup && startFlag[1] == 1) {
                        // Reset blackList
                        for (int i = 0; i < nB; ++i) {
                            blackList[rowRoot][i] = 0;
                        }
                        
                        startFlag[1] = nA;
                        exist = false;
                        for (int rowA = mA-1; rowA > 0; --rowA) {
                            for (int rowB = rowRoot; rowB < mB; ++rowB) {
                                if (MTA[rowA][0] == MTB[rowB][colRoot] && blackList[rowB][colRoot] == 0) {
                                    blackList[rowB][colRoot] = 1;
                                    if (blackList[rowB][colRoot] == whiteList[rowB][colRoot]) {
                                        dup = false;
                                    }
                                    exist = true;
                                    break;
                                }
                            }
                            if (!exist) {
                                // Reset blackList
                                for (int i = 0; i < mB; ++i) {
                                    blackList[i][colRoot] = 0;
                                }
                                
                                startFlag[0]--;                                
                            } else {
                                break;
                            }
                        }
                        
                        if (dup) {
                            for (int i = 0; i < mB; ++i) {
                                if (whiteList[i][colRoot] == 0) {
                                    blackList[i][colRoot] = 1;
                                }
                            }
                        }
                    }
                // End while
                }
            }
        }
    // End loop rootList
    }
    
    return countMT;
}

int main() {
    
    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;
    
    // Tao ma tran B
    int MTA[MAX][MAX];
    
    for (int i = 0; i < mA; ++i) {
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) {
            cin >> MTA[i][j];
            //MTA[i][j] = i+j;

            if (i == 0 && j == 0) {maxNumA = MTA[i][j];}
            else {
                if (MTA[i][j] > maxNumA) {maxNumA = MTA[i][j];}
            }
            
            //cout << MTA[i][j] << " ";
        }
        //cout << endl;
    }
    
    // Tao ma tran B
    int mB, nB;
    int maxNumB;
    cout << "Ma tran B m*n - hang*cot (VD: 5 3): ";
    cin >> mB >> nB;
    
    int MTB[MAX][MAX];
    
    for (int i = 0; i < mB; ++i) {
        cout << "Nhap so thuc cua hang " << setw(len(mB)) << i+1 << " : ";
        for (int j = 0; j < nB; ++j) {
            cin >> MTB[i][j];
            //MTB[i][j] = i+j;

            if (i == 0 && j == 0) {maxNumB = MTB[i][j];}
            else {
                if (MTB[i][j] > maxNumB) {maxNumB = MTB[i][j];}
            }
            
            //cout << MTB[i][j] << " ";
        }
        //cout << endl;
    }
    
    cout << "--------------------------------------------" << endl;
    cout << "So lan xuat hien ma tran A trong B la : ";
    cout << Subnet(MTA, MTB, mA, nA, mB, nB);
    return 0;
}