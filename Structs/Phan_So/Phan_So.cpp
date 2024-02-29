#include<iostream>

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
	if (a.mau == 1) {
		cout << a.tu << endl;
	} else if (a.tu == 0) {
		cout << "0" << endl;
	} else {
        if ((ktduong(a) && a.tu < 0) || (ktam(a) && a.mau < 0))
            cout << a.tu*-1 << "/" << a.mau*-1 << endl;
        else
            cout << a.tu << "/" << a.mau << endl;
	}
}

void nhap(PS &a) {
	cout << "Tu so: ";
	cin >> a.tu;
	cout << "Mau so: ";
	cin >> a.mau;
	
	xuat(a);
}

void check(bool a) {
    if (a)
        cout << "Khong" << endl;
    else
        cout << "Co" << endl;
}

void solve(PS &a, PS &b) {
    cout << "-------------------------------------" << endl;
    
	cout << "a = ";
	xuat(a);
    cout << "b = ";
	xuat(b);
    
    
    cout << "Phan so a toi gian chua: "; check(kttoigian(a));
    cout << "Phan so b toi gian chua: "; check(kttoigian(b));
	cout << "Phan so sau khi rut gon: " << endl;
	rutgon(a);
	rutgon(b);
    cout << "a = ";
	xuat(a);
    cout << "b = ";
	xuat(b);

	PS c = a + b;
	cout << "a + b = ";
	xuat(c);
	c = a - b;
	cout << "a - b = ";
	xuat(c);
	c = a * b;
	cout << "a * b = ";
	xuat(c);
	c = a / b;
	cout << "a / b = ";
	xuat(c);
    
    cout << "Quy dong phan so a va b:" << endl;
    quydong(a, b);
    cout << "a =  ";
    xuat(a);
    cout << "b =  ";
    xuat(b);
    
    
    cout << "Phan so a co duong khong: "; check(ktduong(a));
    cout << "Phan so b co duong khong: "; check(ktduong(b));
    cout << "Phan so a co am khong: "; check(ktam(a));
    cout << "Phan so b co am khong: "; check(ktam(b));
    
    cout << "So sanh phan so a voi b: " << sosanh(a, b) << endl;
    
	
}


int main() {
	
	PS a, b;
	nhap(a);
    nhap(b);
	solve(a, b);
	
	return 0;
}