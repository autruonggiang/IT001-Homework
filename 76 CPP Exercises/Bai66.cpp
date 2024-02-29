#include<iostream>
#include<math.h>

using namespace std;

int main() {

    float a, b, c;
    
    cout << "Nhap a, b, c (ax^4 + bx^2 + c): ";
    cin >> a >> b >> c;
    
    float delta = b * b - 4 * a * c;
    float x1, x2;
    
    if (a == 0 && b == 0) {
        if (c == 0)
            cout << "Phuong trinh co vo so nghiem";
            
        else
            cout << "Phuong trinh vo nghiem";
    } 
	
	else if (c == 0 && (a == 0 || b == 0)) {
        cout << "Phuong trinh co 1 nghiem" << endl;
        cout << "x: 0";
    } 
	
	else {
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem.";
        } 
		
		else if (delta == 0) {
            x1 = x2 = -b / (2 * a);
            
            if (x1 > 0) {
                cout << "Phuong trinh co 2 nghiem: " << endl;
                cout << "x1: " << sqrt(x1) << endl;
                cout << "x2: " << -sqrt(x1);
            } 
			
			else if (x1 == 0) {
                cout << "Phuong trinh co 1 nghiem: " << endl;
                cout << "x: " << x1;
            } 
			
			else {
                cout << "Phuong trinh vo nghiem";
            }
        } 
		
		else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            
            if (x1 < 0 && x2 < 0) {
                cout << "Phuong trinh vo nghiem";
            } 
			
			else if (x1 > 0 && x2 < 0) {
                cout << "Phuong trinh co 2 nghiem: " << endl;
                cout << "x1: " << sqrt(x1) << endl;
                cout << "x2: " << -sqrt(x1) << endl;
            } 
			
			else if (x1 < 0 && x2 > 0) {
                cout << "Phuong trinh co 2 nghiem: " << endl;
                cout << "x1: " << sqrt(x2) << endl;
                cout << "x2: " << -sqrt(x2) << endl;
            } 
			
			else if (x1 == 0 && x2 == 0) {
                cout << "Phuong trinh co 1 nghiem: " << endl;
                cout << "x: " << x1;
            } 
			
			else if (x1 == 0 || x2 == 0) {
                cout << "Phuong trinh co 3 nghiem: " << endl;
                
                if (x1 > 0) {
                    cout << "x1: " << sqrt(x1) << endl;
                    cout << "x2: " << -sqrt(x1) << endl;
                } 
				
				else {
                    cout << "x1: " << sqrt(x2) << endl;
                    cout << "x2: " << -sqrt(x2) << endl;
                }
                
                cout << "x3: 0";
            } 
			
			else {
                cout << "Phuong trinh co 4 nghiem: " << endl;
                cout << "x1: " << sqrt(x1) << endl;
                cout << "x2: " << -sqrt(x1) << endl;
                cout << "x3: " << sqrt(x2) << endl;
                cout << "x4: " << -sqrt(x2);
            }
        }
    }
    
    return 0;
}