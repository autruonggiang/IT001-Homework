#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

// Function declarations
char Change(char x);
int GiaiPT(float a, float b, float &x);
int GiaiPT2(float a, float b, float c, float &x1, float &x2);
float min(float x, float y);
void sapxep(int &a, int &b);

int main() {
    char x;

    cout << "Nhap ky tu: ";
    cin >> x;

    char KyTuChuyen = Change(x);
    
    cout << "Ky tu da duoc chuyen la: " << KyTuChuyen << endl;

    float a, b, xGiaiPT;
    
    cout << "\nNhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    
    int resultGiaiPT = GiaiPT(a, b, xGiaiPT);
    
    if (resultGiaiPT == 0)
        cout << "Phuong trinh vo nghiem" << endl;
        
    else if (resultGiaiPT == 1)
        cout << "Phuong trinh co mot nghiem: " << xGiaiPT << endl;
        
    else
        cout << "Phuong trinh co vo so nghiem" << endl;

    float a2, b2, c2, x1, x2;
    
    cout << "\nNhap a (a != 0): ";
    cin >> a2;
    
    cout << "Nhap b: ";
    cin >> b2;
    
    cout << "Nhap c: ";
    cin >> c2;
    
    int resultGiaiPT2 = GiaiPT2(a2, b2, c2, x1, x2);
    
    if (resultGiaiPT2 == 0)
        cout << "Phuong trinh vo nghiem" << endl;
        
    else if (resultGiaiPT2 == 1)
        cout << "Phuong trinh co nghiem kep x=" << x1 << endl;
        
    else {
        cout << "Phuong trinh da cho co hai nghiem phan biet" << endl;
        cout << "x1 =" << x1 << endl;
        cout << "x2 =" << x2 << endl;
    }

    float minResult = min(3.14, 2.71);
    
    cout << "So nho nhat la: " << minResult << endl;

    int num1, num2;
    
    cout << "\nNhap so thu nhat: ";
    cin >> num1;
    
    cout << "Nhap so thu hai: ";
    cin >> num2;
    
    cout << "\nTruoc khi doi: \n" << "So thu nhat = " << num1 << "\nSo thu hai = " << num2;
    
    sapxep(num1, num2);
    cout << "\nSau khi doi: \n" << "So thu nhat = " << num1 << "\nSo thu hai = " << num2;

    return 0;
}

char Change(char x) {
    char n;
    
    if ('a' <= x && x <= 'z')
        n = x - ('a' - 'A');
        
    else if ('A' <= x && x <= 'Z')
        n = x + ('a' - 'A');
        
    return n;
}

int GiaiPT(float a, float b, float &x) {
    if (a == 0) {
        if (b == 0)
            return 2;
            
        return 0;
    }

    x = -b / a;

    return 1;
}

int GiaiPT2(float a, float b, float c, float &x1, float &x2) {
    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        x1 = x2 = 0.0;
        
        return 0;
    } 
	
	else if (delta == 0) {
        x1 = x2 = -b / (2 * a);
        
        return 1;
    } 
	
	else {
        delta = sqrt(delta);
        
        x1 = (-b + delta) / (2 * a);
        x2 = (-b - delta) / (2 * a);
        
        return 2;
    }
}

float min(float x, float y) {
    return (x < y) ? x : y;
}

void sapxep(int &a, int &b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}