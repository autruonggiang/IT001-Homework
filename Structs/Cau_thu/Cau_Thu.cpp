#include<iostream>
#include<string.h>

using namespace std;

struct Ngay {
	int day, month, year;
};

void oDate(Ngay date) {
		
	if (date.day > 9)
		cout << date.day << "/";
	else
		cout << "0" << date.day << "/";
	
	if (date.month > 9)
		cout << date.month << "/" << date.year << endl;
	else
		cout << "0" << date.month << "/" << date.year << endl;
}

void iDate(Ngay &date) {
	cout << "Nhap ngay (VD: 15/03/2023): ";
	string temp;
	getline(cin, temp);
	
	temp += "/";
	string num = "";
	int state = 0;
	for (int i = 0; i < temp.length(); ++i) {
		if (temp[i] != '/') {
			num += temp[i];
		} else {
			if (state == 0)
				date.day = stoi(num);
			else if (state == 1)
				date.month = stoi(num);
			else
				date.year = stoi(num);
			
			num = "";
			state++;
		}
	}
}

struct CauThu {
	string code;
	string name;
	Ngay date;
};

typedef CauThu CT;

void oCT(CT human) {
	
	cout << endl;
	cout << "Ma cau thu la : " << human.code << endl;
	cout << "Ten cau thu la: " << human.name << endl;
	cout << "Ngay sinh cau thu la: ";
	oDate(human.date);
	
}

void iCT(CT &human) {
	cout << "Nhap ma cau thu: ";
	getline(cin, human.code);
	
	while (0 < human.code.length() && human.code.length() > 10) {
		cout << "Ma cau thu it hon 10 ky tu.\n";
		cout << "Nhap ma cau thu: ";
		getline(cin, human.code);
	}
	
	cout << "Nhap ten cau thu la: ";
	getline(cin, human.name);
	
	while (0 < human.name.length() && human.name.length() > 30) {
		cout << "Ten cau thu it hon 30 ky tu.\n";
		cout << "Nhap ten cau thu: ";
		getline(cin, human.name);
	}
	
	iDate(human.date);
}

int main() {
	
	CT human;
	iCT(human);
	oCT(human);
	
	return 0;
}