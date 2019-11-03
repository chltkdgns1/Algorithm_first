#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ifstream in;
	ofstream out;
	in.open("text.txt");
	out.open("sibar.cpp");

	system("pause");
	if (in.is_open()) {
		cout << "succes" << "\n";
		char c;
		string s;
		while ((c = in.get()) != EOF) s += c;

		cout << s << "\n";
		out << s;

	}
	system("pause");
}