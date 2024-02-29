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
	cout << "	Nhap ngay (VD: 15/03/2023): ";
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
	cout << "	Ma cau thu la : " << human.code << endl;
	cout << "	Ten cau thu la: " << human.name << endl;
	cout << "	Ngay sinh cau thu la: ";
	oDate(human.date);
	
}

void iCT(CT &human) {
	cout << "	Nhap ma cau thu: ";
	getline(cin, human.code);
	
	while (0 < human.code.length() && human.code.length() > 10) {
		cout << "	Ma cau thu it hon 10 ky tu.\n";
		cout << "	Nhap ma cau thu: ";
		getline(cin, human.code);
	}
	
	cout << "	Nhap ten cau thu la: ";
	getline(cin, human.name);
	
	while (0 < human.name.length() && human.name.length() > 30) {
		cout << "	Ten cau thu it hon 30 ky tu.\n";
		cout << "	Nhap ten cau thu: ";
		getline(cin, human.name);
	}
	
	iDate(human.date);
}

struct Team {
	string code;
	string name;
	CT human[30];
	int num = 0;
};

void oTeam(Team doi) {
	cout << "\n***********************************" << endl;
	cout << "Ma doi bong la: " << doi.code << endl;
	cout << "Ten doi bong la: " << doi.name << endl;
	
	for (int i = 0; i < doi.num; ++i) {
		cout << "\nThanh vien so "  << i+1;
		oCT(doi.human[i]);
	}
}

void iTeam(Team &doi) {
	cout << "Nhap ma doi bong: ";
	getline(cin, doi.code);
	
	while (0 < doi.code.length() && doi.code.length() > 5) {
		cout << "Ma cau thu it hon 5 ky tu.\n";
		cout << "Nhap ma cau thu: ";
		getline(cin, doi.code);
	}
	
	cout << "Nhap ten doi bong: ";
	getline(cin, doi.name);
	
	while (0 < doi.name.length() && doi.name.length() > 30) {
		cout << "Ten cau thu it hon 30 ky tu.\n";
		cout << "Nhap ten cau thu: ";
		getline(cin, doi.name);
	}
	
	cout << "So thanh vien doi bong: ";
	cin >> doi.num;
	cin.ignore(1, '\n');
	for (int i = 0; i < doi.num; ++i) {
		cout << "\n";
		cout << "Thanh vien so "  << i+1 << endl;
		iCT(doi.human[i]);
	}
}

int main() {
	
	Team doi;
	iTeam(doi);
	oTeam(doi);
	
	return 0;
}