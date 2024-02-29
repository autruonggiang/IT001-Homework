#include<iostream>
#include<string>
#include<math.h>

using namespace std;

struct DONTHUC {
    float heso;
    string bien; // *x^15*y^16;
};

void nhap(DONTHUC &);
void xuat(DONTHUC);
DONTHUC tich(DONTHUC, DONTHUC);
DONTHUC thuong(DONTHUC, DONTHUC);
DONTHUC daoham(DONTHUC);
DONTHUC daoham(DONTHUC, int);
float tinhf(DONTHUC, float);
DONTHUC operator* (DONTHUC, DONTHUC);
DONTHUC operator/ (DONTHUC, DONTHUC);
string from(string, long long unsigned int, long long unsigned int);
void cleanS(string &);

int main() {
    
    DONTHUC a;
    DONTHUC b;
    
    nhap(a);
    nhap(b);
    
    cout << "a = ";
    xuat(a);
    cout << "b = ";
    xuat(b);
    
    DONTHUC c = a*b;
    cout << "a*b = " << c.heso << "*" << c.bien << endl;
    c = a/b;
    cout << "c = a/b = " << c.heso << "*" << c.bien << endl;
    cout << "c(5) = " << tinhf(c, 5) << endl;
    cout << "Dao ham bac 1 cua a theo x la: ";
    xuat(daoham(a));
    int k;
    cout << "So bac k muon dao ham a: ";
    cin >> k;
    cout << "Dao ham bac " << k << " cua a theo x la: ";
    xuat(daoham(a, k));
    
    
    return 0;
}

void cleanS(string &S) {
    
    int dem = 0;
    for (long long unsigned int i = S.length()-1; i >= 0; --i) {
        if (S[i] == '*')
            dem++;
        else
            break;
    }
    S.erase(S.length()-dem, dem);
    
    dem = 0;
    for (long long unsigned int i = 0; i < S.length(); ++i) {
        if (S[i] == '*')
            dem++;
        else
            break;
    }
    S.erase(0, dem);
}

void nhap(DONTHUC &a) {
    cout << "He so la:  ";
    cin >> a.heso;
    cout << "Bien so la (VD: x^5*y^16): ";
    cin >> a.bien;
}

void xuat(DONTHUC c) {
    cleanS(c.bien);
    if (c.bien != "")
        cout << c.heso << "*" << c.bien << endl;
    else
        cout << c.heso << endl;
}

string from(string S, long long unsigned int a, long long unsigned int b) {
    
    string out = "";
    for (long long unsigned int i = a; i < b; ++i) {
        out += S[i];
    }
    return out;
}

DONTHUC tich(DONTHUC a, DONTHUC b) {
    
    DONTHUC c;
    c.heso = b.heso * a.heso;
    
    string muS = "";
    float mu;
    string bien = "";
    
    string  bien1 = "*" + a.bien + "*",
            bien2 = "*" + b.bien + "*";
    
    long long unsigned int  temp = 0;
    int status = 0; // 0: mu, 1: bien;
    int check = 0;
    
    for (long long unsigned int i = 0; i < bien1.length(); ++i) {
        if (bien1[i] == '*') {
            status = 1;
            if (muS != "") {
                mu += stof(muS);
                bien += to_string((int)mu) + "*";
                muS = "";
                mu = 0;
            }
        } else if (bien1[i] == '^') {
            status = 0;
        } else if (status == 1) {
            bien += bien1[i];
            bien += "^";
        } else if (status == 0) {
            muS += bien1[i];
        }
        
        if (status == 1 && bien1[i] != '*') {
            check = 0;
            for (long long unsigned int j = 0; j < bien2.length(); ++j) {
                if (check == 2) {
                    muS += bien2[j];
                }
                if (bien2[j] == bien1[i]) {
                    temp = j;
                    check = 1;
                }
                if (check == 1 && bien2[j] == '^') {
                    check = 2;
                }
                if (bien2[j] == '*' && check == 2) {
                    bien2.erase(temp, j-temp+1);
                    temp = 0;
                    check = 0;
                    break;
                }
            }
            if (muS != "") {
                mu = stof(muS);
                muS = "";                
            }
        }
    }
    
    cleanS(bien);
    cleanS(bien2);
    
    c.bien = bien + "*" + bien2;
    cleanS(c.bien);
    
    return c;
}

DONTHUC thuong(DONTHUC a, DONTHUC b) {
    DONTHUC c;
    c.heso = a.heso / b.heso;
    
    string muS = "";
    float mu;
    string bien = "";
    
    string  bien1 = "*" + a.bien + "*",
            bien2 = "*" + b.bien + "*";
    
    long long unsigned int  temp = 0;
    int status = 0; // 0: mu, 1: bien;
    int check = 0;
    
    for (long long unsigned int i = 0; i < bien1.length(); ++i) {
        if (bien1[i] == '*') {
            status = 1;
            if (muS != "") {
                mu = stof(muS) - mu;
                bien += to_string((int)mu) + "*";
                muS = "";
                mu = 0;
            }
        } else if (bien1[i] == '^') {
            status = 0;
        } else if (status == 1) {
            bien += bien1[i];
            bien += "^";
        } else if (status == 0) {
            muS += bien1[i];
        }
        
        if (status == 1 && bien1[i] != '*') {
            check = 0;
            for (long long unsigned int j = 0; j < bien2.length(); ++j) {
                if (check == 2) {
                    muS += bien2[j];
                }
                if (bien2[j] == bien1[i]) {
                    temp = j;
                    check = 1;
                }
                if (check == 1 && bien2[j] == '^') {
                    check = 2;
                }
                if (bien2[j] == '*' && check == 2) {
                    bien2.erase(temp, j-temp+1);
                    temp = 0;
                    check = 0;
                    break;
                }
            }
            if (muS != "") {
                mu = stof(muS);
                muS = "";                
            }
        }
    }
    
    cleanS(bien);
    cleanS(bien2);
    
    for(long long unsigned int i = 0; i < bien2.length(); ++i) {
        if (bien2[i] == '*')
            bien2[i] = '/';
    }
    
    c.bien = bien + "/" + bien2;    
    cleanS(c.bien);
    return c;
}

DONTHUC operator* (DONTHUC a, DONTHUC b) {
    return tich(a, b);
}

DONTHUC operator/ (DONTHUC a, DONTHUC b) {
    return thuong(a, b);
}

float tinhf(DONTHUC a, float b) {
    
    float s = 1;
    
    DONTHUC c;
    
    float heso = a.heso;
    
    string muS = "";
    float mu;
    string bien = "";
    
    string  bien1 = "*" + a.bien + "*";
    
    int status = 0; // 0: mu, 1: bien;
    int exist = 0;
    
    for (long long unsigned int i = 0; i < bien1.length(); ++i) {
        if (bien1[i] == '*' || bien1[i] == '/') {
            status = 1;
            if (muS != "") {
                if (exist == 1) {
                    s *= heso*pow(b, stof(muS));
                    exist = 0;
                    muS = "";
                } else {                    
                    mu += stof(muS);
                    bien += muS + "*";
                    muS = "";
                    mu = 0;
                }
            }
        } else if (bien1[i] == '^') {
            status = 0;
        } else if (status == 1) {
            if (bien1[i] == 'x') {
                exist = 1;
            } else {
                bien += bien1[i];
                bien += "^";
            }
        } else if (status == 0) {
            muS += bien1[i];
        }
    } 
    cleanS(bien);
    
    c.bien = bien;
    c.heso = s;
    xuat(c);
    cout << "xc(5) = ";
    
    return s;
}

float findRootX(DONTHUC a) {
    
    string muS = "";
    string  bien1 = "*" + a.bien + "*";
    
    int status = 0; // 0: mu, 1: bien;
    
    for (long long unsigned int i = 0; i < bien1.length(); ++i) {
        if (bien1[i] == '*') {
            status = 1;
            if (muS != "" && bien1[i - muS.length() - 2] == 'x') {
                return stof(muS);
            }
            muS = "";
        } else if (bien1[i] == '^') {
            status = 0;
        } else if (status == 0) {
            muS += bien1[i];
        }
    }
}

DONTHUC daoham(DONTHUC a) {
    if (a.bien != "") {
        
        string muS = "";
        float mu;
        string bien = "";
        
        string  bien1 = "*" + a.bien + "*";
        
        int status = 0; // 0: mu, 1: bien;
        
        for (long long unsigned int i = 0; i < bien1.length(); ++i) {
            if (bien1[i] == '*') {
                status = 1;
                if (muS != "" && bien1[i - muS.length() - 2] == 'x') {
                    if (stof(muS) != 0) {
                        a.heso *= stof(muS);
                        mu = stof(muS) - 1;
                        if (mu != 0)
                            bien += "x^" + to_string((int) mu) + "*";
                        muS = "";
                    } else {
                        muS = "";
                    }
                } else {
                    if (muS != "") {
                        mu = stof(muS);
                        bien += to_string((int) mu) + "*";
                        muS = "";
                    }
                }
            } else if (bien1[i] == '^') {
                status = 0;
            } else if (status == 1) {
                if (bien1[i] != 'x') {
                    bien += bien1[i];
                    bien += "^";
                }
            } else if (status == 0) {
                muS += bien1[i];
            }            
        }
        
        cleanS(bien);
        
        a.bien = bien;
        cleanS(a.bien);
        
        return a;
        
    } else {
        a.heso = 0;
        a.bien = "";
        return a;
    }
}

DONTHUC daoham(DONTHUC a, int k) {
    
    if (findRootX(a) >= k || findRootX(a) < 0) {
        for (int i = 0; i < k; ++i) {
            a = daoham(a);
        }
    } else {
        a.heso = 0;
        a.bien = "";
    }
    
    return a;
}
