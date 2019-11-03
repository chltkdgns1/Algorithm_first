#include <iostream>
#include <string>
using namespace std;
void go(int a,int b,int c) {
	string d;
	bool e = 0;
	if (a + b == c) { 
		d += to_string(a); 
		d += "+";
		d += to_string(b);
		e = true;
	}
	else if (a - b == c) {
		d += to_string(a);
		d += "-";
		d += to_string(b);
		e = true;
	}
	else if (a / b == c) {
		d += to_string(a);
		d += "/";
		d += to_string(b);
		e = true;
	}
	else if (a * b == c) {
		d += to_string(a);
		d += "*";
		d += to_string(b);
		e = true;
	}
	if (e) {
		d += "=", d += to_string(c);
		cout << d << "\n";
		system("pause");
		exit(0);
	}
	if (a == b + c) {
		d += to_string(a), d += '=';
		d += to_string(b);
		d += "+";
		d += to_string(c);
		e = true;
	}
	else if (a == b - c) {
		d += to_string(a), d += '=';
		d += to_string(b);
		d += "-";
		d += to_string(c);
		e = true;
	}
	else if (a == b / c) {
		d += to_string(a), d += '=';
		d += to_string(b);
		d += "/";
		d += to_string(c);
		e = true;
	}
	else if (a == b * c) {
		d += to_string(a), d += '=';
		d += to_string(b);
		d += "*";
		d += to_string(c);
		e = true;
	}
	if (e) {
		cout << d << "\n";
		system("pause");
		exit(0);
	}
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	go(a, b, c);
}