#include<iostream>

using namespace std;

int SolveA (int n) {
    if (n == 0) {
        return 0;
    } 
	
	else {
        return n + SolveA(n - 1);
    }
}

int SolveB (int n) {
    if (n == 0) {
        return 0;
    } 
	
	else {
        return n * n + SolveB(n - 1);
    }
}

float SolveC (float n) {
    if (n == 1) {
        return 1;
    } 
	
	else {
        return 1 / n + SolveC(n - 1);
    }
}

int SolveD (int n) {
    if (n == 1) {
        return 1;
    } 
	
	else {
        return n * SolveD(n - 1);
    }
}

int SolveE (int n) {
    int gt = 1, sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        gt *= i;
        sum += gt;
    }
    
    return sum;
}

float solve(int n, char select) {
    switch(select) {
        case 'a': return SolveA(n); break;
        case 'b': return SolveB(n); break;
        case 'c': return SolveC(n); break;
        case 'd': return SolveD(n); break;
        case 'e': return SolveE(n); break;
    }
}

int main() {
    
    int n;
    
    cout << "Nhap n: ";
    cin >> n;
    
    cout << "Cau a: " << "S = " << solve(n, 'a') << "\n";
    cout << "Cau b: " << "S = " << solve(n, 'b') << "\n";
    cout << "Cau c: " << "S = " << solve(n, 'c') << "\n";
    cout << "Cau d: " << "S = " << solve(n, 'd') << "\n";
    cout << "Cau e: " << "S = " << solve(n, 'e') << "\n";

    return 0;
}