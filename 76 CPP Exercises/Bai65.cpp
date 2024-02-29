#include<iostream>
#include<math.h>

using namespace std;

int main() {

    float a, b, c;
    
    cout << "Nhap a, b, c (ax^2 + bx + c): ";
    cin >> a >> b >> c;
    
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
        float delta = b * b - 4 * a * c;
        
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem.";
        } 
		
		else if (delta == 0) {
            cout << "Phuong trinh co 1 nghiem duy nhat:" << endl;
            cout << "x: "<< -b / (2 * a);
        } 
		
		else {
            cout    << "Phuong trinh co 2 nghiem: " << endl
                    << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\n"
                    << "x2 = " << (-b - sqrt(delta)) / (2 * a);
        }
    }
    
    return 0;
}