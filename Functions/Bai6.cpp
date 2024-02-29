#include<iostream>
#include<math.h>

using namespace std;

unsigned long long int SolveA (unsigned long long int n) {
    
    int len = 0, temp = n;
    
    while(temp != 0) {
        temp /= 10;
        len++;
    }
    
    unsigned long long int newN = 0;
    
    while(n != 0) {
        newN += n%10*pow(10, len - 1);
        n /= 10;
        len--;
    }
    
    return newN;
}

bool SolveB (unsigned long long int n) {
    if (n == SolveA(n)) {
        return true;
    } 
	
	else {
        return false;
    }
}

bool SolveC (unsigned long long int n) {
    if (((int) sqrt(n)) == sqrt(n)) {
        return true;
    } 
	
	else {
        return false;
    }
    
    return 0;
}

bool SolveD (unsigned long long int n) {
    if (n <= 3) {
        return true;
    }
    
    for (unsigned long long int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int SolveE (unsigned long long int n) {
    int sum = 0;
    
    while (n != 0) {
        if((n % 10) % 2 == 1) {
            sum += n % 10;
        }
        
        n /= 10;
    }
    
    return sum;
}

int SolveF (unsigned long long int n) {
    int sum = 0;
    
    while (n != 0) {
        if (SolveD(n % 10)) {
            sum += n % 10;
        }
        
        n /= 10;
    }
    
    return sum;
}

int SolveG (unsigned long long int n) {
    int sum = 0;
    
    while (n != 0) {
        if (SolveC(n % 10)) {
            sum += n % 10;
        }
        n /= 10;
    }
    
    return sum;
}

unsigned long long int solve(unsigned long long int n, char select) {
    switch(select) {
        case 'a': return SolveA(n); break;
        case 'b': return SolveB(n); break;
        case 'c': return SolveC(n); break;
        case 'd': return SolveD(n); break;
        case 'e': return SolveE(n); break;
        case 'f': return SolveF(n); break;
        case 'g': return SolveG(n); break;
    }
}

int main() {
    unsigned long long int n;
    
    cout << "Nhap n: ";
    cin >> n;
    
    cout << "Cau a: " << "Reverse " << n << ": " << solve(n, 'a') << "\n";
    if (solve(n, 'b')) {
        cout << "Cau b: " << "True" << "\n";
    } 
	
	else {
        cout << "Cau b: " << "False" << "\n";
    }
    
    if (solve(n, 'c')) {
        cout << "Cau c: " << n << " la so chinh phuong" << "\n";
    } 
	
	else {
        cout << "Cau c: " << n << " khong la so chinh phuong" << "\n";
    }
    
    if (solve(n, 'd')) {
        cout << "Cau d: " << n << " la so nguyen to" << "\n";
    } 
	
	else {
        cout << "Cau d: " << n << " khong la so nguyen to" << "\n";
    }
    
    cout << "Cau e: " << "S = " << solve(n, 'e') << "\n";
    cout << "Cau f: " << "S = " << solve(n, 'f') << "\n";
    cout << "Cau g: " << "S = " << solve(n, 'g') << "\n";

    return 0;
}