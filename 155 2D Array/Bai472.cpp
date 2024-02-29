#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 100

using namespace std;

long long int UCLN(long long int m, long long int n) {

    long long int num;
    m = (m < 0)? -m: m;
    n = (n < 0)? -n: n;

    if (m < n) {
        num = n;
        n = m;
        m = num;
    }

    if (n == 0 || m == n)
        return m;
    return UCLN(n, m%n);
}

struct PS {
    long long int tu;
    long long int mau;

    PS operator + (PS PS2) {

        PS new_PS;
        new_PS.mau = mau * PS2.mau;
        new_PS.tu = tu*PS2.mau + PS2.tu*mau;

        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    PS operator - (PS PS2) {

        PS new_PS;
        new_PS.mau = mau * PS2.mau;
        new_PS.tu = tu*PS2.mau - PS2.tu*mau;

        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    PS operator * (PS PS2) {

        PS new_PS;
        long long int numTu = UCLN(tu, PS2.mau);
        long long int numMau = UCLN(mau, PS2.tu);
        
        new_PS.mau = mau/numMau * PS2.mau/numTu;
        new_PS.tu = tu/numTu * PS2.tu/numMau;        
        
        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    PS operator / (PS PS2) {

        PS new_PS;
        new_PS.mau = mau * PS2.tu;
        new_PS.tu = tu * PS2.mau;

        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    PS operator * (long long int a) {
        PS new_PS;
        
        long long int numMau = UCLN(a, mau);
        
        new_PS.tu = tu * a/numMau;
        new_PS.mau = mau/numMau;

        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    PS operator / (long long int a) {
        PS new_PS;

        new_PS.tu = tu;
        new_PS.mau = mau * a;

        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    PS operator + (long long int a) {
        PS new_PS;

        new_PS.tu = tu + a;
        new_PS.mau = mau * a;

        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    PS operator - (long long int a) {
        PS new_PS;

        new_PS.tu = tu - a;
        new_PS.mau = mau * a;

        long long int num = UCLN(new_PS.tu, new_PS.mau);
        new_PS.tu = new_PS.tu/num;
        new_PS.mau = new_PS.mau/num;

        return new_PS;
    }

    bool operator == (PS a) {
        if (tu == a.tu && mau == a.mau)
            return true;
        else
            return false;
    }

    bool operator == (long long int a) {
        if (tu/mau  == a)
            return true;
        else
            return false;
    }

    bool operator != (PS a) {
        if (tu != a.tu || mau != a.mau)
            return true;
        else
            return false;
    }

    bool operator != (long long int a) {
        if (tu/mau  != a)
            return true;
        else
            return false;
    }
};

PS turnPS (double n) {

    PS a;

    long long int num, i = 1;
    do {
        num = n*i;
        i++;
    } while (num != n*(i-1));

    a.tu = num;
    a.mau = i-1;

    return a;
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
    if (num < 0)
        a++;

    while(num /= 10) {
        a++;
    }
    
    return a;
}

void drawMT(double MTA[][MAX], int mA, int nA, int maxNumA) {

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

int input(double MTA[][MAX], int mA, int nA, bool bug = false) {

    srand(time(NULL));

    int maxNumA, temp;
    for (int i = 0; i < mA; ++i) { // row
        cout << "Nhap so thuc cua hang " << setw(len(mA)) << i+1 << " : ";
        for (int j = 0; j < nA; ++j) { // col
            if (bug)
                MTA[i][j] = rand()%200-99;
            else
                cin >> MTA[i][j];

            if (i == 0 && j == 0) {maxNumA = MTA[i][j];}
            else {
                if (MTA[i][j] > maxNumA) {
                    maxNumA = MTA[i][j];
                } else if (MTA[i][j] < 0) {
                    temp = MTA[i][j];
                    temp *= -1;
                    if (len(temp) >= len(maxNumA)) {
                        maxNumA = temp * 10;
                    }
                }
            }

            if (bug)
                cout << MTA[i][j] << " ";
        }
        if (bug)
            cout << endl;
    }

    return maxNumA;
}

void swapRow(PS MTA[][MAX], int mA ,int row1, int row2) {

    PS temp;
    for (int i = 0; i < mA; ++i) {
        temp = MTA[row1][i];
        MTA[row1][i] = MTA[row2][i];
        MTA[row2][i] = temp;
    }
}

void swapRow(double MTA[][MAX], int mA ,int row1, int row2) {

    double temp;
    for (int i = 0; i < mA; ++i) {
        temp = MTA[row1][i];
        MTA[row1][i] = MTA[row2][i];
        MTA[row2][i] = temp;
    }
}

double det(double MTA[][MAX], int mA) {

    double dt = 1;
    double num;

    double MTB[MAX][MAX];
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < mA; ++j) {
            MTB[i][j] = MTA[i][j];
        }
    }

    for (int i = 0; i < mA; ++i) {
        if (MTB[i][i] == 0) {
            for (int j = i+1; j < mA; ++j) {
                if (MTB[j][i] != 0) {
                    swapRow(MTB, mA, i, j);
                    break;
                } else if (MTB[j][i] == 0 && j == mA - 1) {
                    dt = 0;
                    goto end;
                }
            }
        }

        for (int j = i+1; j < mA; ++j) {
            num = (-1*MTB[j][i])/MTB[i][i];
            for (int k = i; k < mA; ++k ) {
                MTB[j][k] += MTB[i][k] * num;
            }
        }
    }

    for (int i = 0; i < mA; ++i) {
        dt *= MTB[i][i];
    }

    end:
        return dt;
}

void revMT(double MTA[][MAX], int mA, int nA, int maxNumA) {

    drawMT(MTA, mA, nA, maxNumA);


    PS MTB[MAX][MAX];
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < mA; ++j) {
            MTB[i][j] = turnPS(MTA[i][j]);
        }
    }

    for (int i = 0; i < mA; ++i) {
        for (int j = mA; j < 2*mA; ++j) {
            if (i + mA == j)
                MTB[i][j] = {1, 1};
            else
                MTB[i][j] = {0, 1};
        }
    }

    PS dv = {1, 1};

    PS num;
    bool stop = false;
    if (mA != nA) {
        stop = true;
        goto end;
    } else {
        if (det(MTA, mA) == 0) {
            stop = true;
            goto end;
        } else {
            for (int i = 0; i < mA; ++i) {

                // Check xem phan tu dau co = 0 ko
                if (MTB[i][i] == 0) {

                    // check co row 0 khong
                    for (int j = 0; j < mA; ++j) {
                        if (MTB[i][j] != 0)
                            break;
                        else if (MTB[i][j] == 0 && j == nA - 1) {
                            stop = true;
                            goto end;
                        }
                    }

                    for (int j = 0; j < mA; ++j) {
                        if (MTB[j][i] != 0) {
                            swapRow(MTB, mA*2, i, j);
                            break;
                        } else if (MTB[j][i] == 0 && j == mA - 1) {
                            stop = true;
                            goto end;
                        }
                    }
                } else {
                    num = dv/MTB[i][i];
                    for (int j = i; j < mA*2; ++j) {
                        MTB[i][j] = MTB[i][j] * num;
                    }

                    for (int j = 0; j < mA; ++j) {
                        if (j != i) {
                            num = MTB[j][i] * -1;
                            for (int k = 0; k < mA*2; ++k) {
                                MTB[j][k] = MTB[j][k] + MTB[i][k]*num;
                            }
                        }
                    }
                }
            }
        }
    }

    end:
        if (stop) {
            cout << "Ma tran khong kha nghich.";
        } else {
            cout << "Ma tran kha nghich la: " << endl;
            
            int maxTu = 0, maxMau = 0, length;
            for (int i = 0; i < mA; ++i) {
                for (int j = mA; j < mA*2; ++j) {
                    if (len(MTB[i][j].tu) > maxTu)
                        maxTu = len(MTB[i][j].tu);
                    if (len(MTB[i][j].mau) > maxMau)
                        maxMau = len(MTB[i][j].mau);
                }
            }            
            length = maxTu+3+maxMau;
            draw(length, nA);
            for (int i = 0; i < mA; ++i) {
                for (int j = mA; j < mA*2; ++j) {
                    if (MTB[i][j].mau != 1)
                        cout << setw(maxTu+1) << MTB[i][j].tu << "/" << MTB[i][j].mau << setw(maxMau-len(MTB[i][j].mau)+2) << "|";
                    else
                        cout << setw(maxTu+1) << MTB[i][j].tu / MTB[i][j].mau << setw(maxMau-len(MTB[i][j].mau)+2) << "|";
                    
                }
                cout << endl;
            }

            draw(length, nA);
        }
}



int main() {

    int mA, nA;
    int maxNumA;
    cout << "Ma tran A m*n - hang*cot (VD: 5 3): ";
    cin >> mA >> nA;

    double MTA[MAX][MAX];
    // int sum = 0;
    maxNumA = input(MTA, mA, nA);
    revMT(MTA, mA, nA, maxNumA);
    
    // PS a = {17, -1866};
    // PS b = {79, -933};
    // PS c = {-1613, -173638};
    
    // PS d = a * c;
    // cout << d << endl;
    
    // cout << 1866*173638;

    return 0;
}
