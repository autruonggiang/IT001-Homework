#include<iostream>
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
	
	void rutgon(PS &a) {
		long long int num = UCLN(a.tu, a.mau);
		a.tu = a.tu/num;
		a.mau = a.mau/num;
        
        if (a.mau < 0) {
            a.tu *= -1;
            a.mau *= -1;
        }
	}
	
    PS operator + (PS PS2) {

        PS new_PS;
        new_PS.mau = mau * PS2.mau;
        new_PS.tu = tu*PS2.mau + PS2.tu*mau;

        rutgon(new_PS);

        return new_PS;
    }

    PS operator - (PS PS2) {

        PS new_PS;
        new_PS.mau = mau * PS2.mau;
        new_PS.tu = tu*PS2.mau - PS2.tu*mau;

        rutgon(new_PS);

        return new_PS;
    }

    PS operator * (PS PS2) {

        PS new_PS;
        long long int numTu = UCLN(tu, PS2.mau);
        long long int numMau = UCLN(mau, PS2.tu);
        
        new_PS.mau = mau/numMau * PS2.mau/numTu;
        new_PS.tu = tu/numTu * PS2.tu/numMau;        
        
        rutgon(new_PS);

        return new_PS;
    }

    PS operator / (PS PS2) {

        PS new_PS;
        new_PS.mau = mau * PS2.tu;
        new_PS.tu = tu * PS2.mau;

        rutgon(new_PS);

        return new_PS;
    }

    PS operator * (long long int a) {
        PS new_PS;
        
        long long int numMau = UCLN(a, mau);
        
        new_PS.tu = tu * a/numMau;
        new_PS.mau = mau/numMau;

        rutgon(new_PS);

        return new_PS;
    }

    PS operator / (long long int a) {
        PS new_PS;

        new_PS.tu = tu;
        new_PS.mau = mau * a;

        rutgon(new_PS);

        return new_PS;
    }

    PS operator + (long long int a) {
        PS new_PS;

        new_PS.tu = tu + a;
        new_PS.mau = mau * a;

        rutgon(new_PS);

        return new_PS;
    }

    PS operator - (long long int a) {
        PS new_PS;

        new_PS.tu = tu - a;
        new_PS.mau = mau * a;

        rutgon(new_PS);

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
	
    bool operator < (PS a) {
        PS c;
		
		c = a - *this;
				
		if (c.tu*1.0/c.mau > 0)
			return true;
		else
			return false;
    }
	
    bool operator > (PS a) {
        PS c;
		
		c = a - *this;
				
		if (c.tu*1.0/c.mau < 0)
			return true;
		else
			return false;
    }
	
    bool operator <= (PS a) {
        PS c;
		
		c = a - *this;
				
		if (c.tu*1.0/c.mau <= 0)
			return true;
		else
			return false;
    }
	
    bool operator >= (PS a) {
        PS c;
		
		c = a - *this;
				
		if (c.tu*1.0/c.mau >= 0)
			return true;
		else
			return false;
    }
    
    PS operator ++ () {
        PS c;
        
        c = *this + 1;
        
        return c;
    }
    
    PS operator -- () {
        PS c;
        
        c = *this - 1;
        
        return c;
    }
	
};

void rutgon(PS &a) {
	long long int num = UCLN(a.tu, a.mau);
	a.tu = a.tu/num;
	a.mau = a.mau/num;
}

PS tong(PS a, PS b) {
    PS c = a + b;
    return c;
}

PS hieu(PS a, PS b) {
    PS c = a - b;
    return c;
}

PS tich(PS a, PS b) {
    PS c = a * b;
    return c;
}

PS thuong(PS a, PS b) {
    PS c = a / b;
    return c;
}

bool kttoigian(PS a) {
    if (UCLN(a.tu, a.mau) == 1)
        return true;
    
    return false;
}

void quydong (PS &a, PS &b) {
    
    long long int temp = a.mau;
    
    a.mau *= b.mau;
    a.tu *= b.mau;
    
    if (kttoigian(a))
        rutgon(a);
    
    b.mau *= temp;
    b.tu *= temp;
    
    if (kttoigian(b))
        rutgon(b);
    
}

bool ktduong(PS a) {
    if (a.tu*a.mau > 0)
        return true;
    return false;
}

bool ktam (PS a) {
    if (a.tu*a.mau < 0)
        return true;
    return false;
}

int sosanh(PS a, PS b) {
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}

void xuat(PS a) {
	
    if ((ktduong(a) && a.tu < 0) || (ktam(a) && a.mau < 0))
        cout << a.tu*-1 << "/" << a.mau*-1 << endl;
    else
        cout << a.tu << "/" << a.mau << endl;
}

void nhap(PS &a) {
	cout << "   Tu so : ";
	cin >> a.tu;
	cout << "   Mau so: ";
	cin >> a.mau;
    rutgon(a);
}

void output(PS list[], int num) {
    
    cout << "\n";
    for (int i = 0; i < num; ++i) {
        cout << "Phan so thu " << i+1 << " : ";
        xuat(list[i]);
    }
}

void input(PS list[], int &num) {
	
    cout << "Chieu dai mang: ";
	cin >> num;
	
	while (num <= 0 || num > 100) {
		cout << "Mang khong hop le." << endl;
		cout << "Chieu dai mang: ";
		cin >> num;
	}
    
    for (int i = 0; i < num; ++i) {
        cout << "\nPhan so thu " << i+1 << ":" << endl;
        nhap(list[i]);
    }
    
}

int count (PS list[], int num, int state) {
    
    int dem = 0;
    for (int i = 0; i < num; ++i) {
        if (state == 1) {
            if (ktduong(list[i]))
                dem++;
        } else if (state == -1) {
            if (ktam(list[i]))
                dem++;
        }
    }
    
    return dem;
}

void copy(PS &a, PS b) {
    a.tu = b.tu;
    a.mau = b.mau;
}

PS max(PS list[], int num) {
    
    PS temp;
    copy(temp, list[0]);
    for (int i = 1; i < num; ++i) {
        if (sosanh(temp, list[i]) == -1) {
            copy(temp, list[i]);
        }
    }
    
    return temp;
}

PS min(PS list[], int num) {
    
    PS temp;
    copy(temp, list[0]);
    for (int i = 1; i < num; ++i) {
        if (sosanh(temp, list[i]) == 1) {
            copy(temp, list[i]);
        }
    }
    
    return temp;
}

PS duongdau(PS list[], int num) {
    
    PS temp = {0, 1};
    
    for (int i = 0; i < num; ++i) {
        if (ktduong(list[i])) {
            copy(temp, list[i]);
            break;
        }
    }
    
    return temp;
}

float lonnhat(PS list[], int num) {
    
    PS temp = max(list, num);
    
    return temp.tu*1.0/temp.mau;
}

int indexMin(PS list[], int num) {
    
    PS temp;
    copy(temp, min(list, num));
    
    int index;
    for (int i = 0; i < num; ++i) {
        if (temp == list[i]) {
            index = i;
            break;
        }
    }
    
    return index;
}

PS minDuong(PS list[], int num) {
    
    PS temp = {-1, 1};
    
    for (int i = 0; i < num; ++i) {
        if (ktduong(list[i])) {
            if (temp.tu == -1 && temp.mau == 1)
                copy(temp, list[i]);
            else {
                if (list[i] < temp) {
                    copy(temp, list[i]);
                }
            }
        }
    }
    
    return temp;
}

int indexMinPo(PS list[], int num) {
    
    PS temp;
    copy(temp, minDuong(list, num));
    
    int index = -1;
    for (int i = 0; i < num; ++i) {
        if (temp == list[i])
            index = i;
    }
    
    return index;
}

void swap(PS &a, PS &b) {
    
    PS temp;
    copy(temp, a);
    
    copy(a, b);
    copy(b, temp);
}


void sort(PS list[], int num, int state) {
    
    
    bool stop = true;
    for (int i = 0; i < num-1; ++i) {
        if (state == 1) {
            if (list[i] > list[i+1]) {
                swap(list[i], list[i+1]);
                stop = false;
            }
        } else if (state == -1) {
            if (list[i] < list[i+1]) {
                swap(list[i], list[i+1]);
                stop = false;
            }
        }
    }
    
    if (!stop) {
        sort(list, num, state);
    }
    
}

void solve(PS list[], int num) {
    
    cout << "\nSo luong phan so duong trong mang la: " << count(list, num, 1) << endl;
    cout << "So luong phan so am trong mang la: " << count(list, num, -1) << endl;
	cout << "Phan so lon nhat trong mang la: ";
    xuat(max(list, num));
	cout << "Phan so nho nhat trong mang la: ";
    xuat(min(list, num));
    cout << "Gia tri lon nhat trong mang la: " << lonnhat(list, num) << endl;
    
    PS temp;
    
    copy(temp, duongdau(list, num));
    cout << "Gia tri duong dau tien cua mang la: ";
    if (temp.tu == 0 && temp.mau == 1) {
        xuat(temp);
    } else {
        cout << temp.tu*1.0/temp.mau << endl;
    }
    
    cout << "Vi tri co gia tri nho nhat la: " << indexMin(list, num) << endl;
    
    copy(temp, minDuong(list, num));
    cout << "Gia tri duong nho nhat cua mang la: ";
    if (temp.tu == -1 && temp.mau == 1) {
        xuat(temp);
    } else {
        cout << temp.tu*1.0/temp.mau << endl;
    }
    
    cout << "Vi tri gia tri duong nho nhat la: " << indexMinPo(list, num) << endl;
    
    cout << "\nMang tang dan:";
    sort(list, num, 1);
    output(list, num);
    
    cout << "\nMang giam dan:";
    sort(list, num, -1);
    output(list, num);
    
}


int main() {
	
    int num;
	PS list[MAX];
    input(list, num);
	output(list, num);
	solve(list, num);
	
	return 0;
}