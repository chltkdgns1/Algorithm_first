#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	string name[120]; // 변수 명들
	string f_name[120]; // 각 변수의 자료형
	string f; // 자료형
	int index = 0;
	for (int i = 0; i < s.length(); i++) { //& [] *
		index = i;
		if (s[i] != ' ') f += s[i];
		else break;
	}
	int cnt = 0, cnt2 = 0;
	for (int i = index + 1; i < s.length(); i++) {
		if (s[i] != '*' && s[i] != '&' && s[i] != '[' && s[i] != ']'
			&& s[i] != ' ' && s[i] != ',' && s[i] != ';') {
			name[cnt] += s[i];
		}
		else if(s[i] != ',' && s[i] != ' ' && s[i] != ';'){
			f_name[cnt2] += s[i];
		}
		else if (s[i] == ' ') { cnt2++, cnt++; }
	}

	for (int i = 0; i <= cnt; i++) {
		reverse(f_name[i].begin(), f_name[i].end());
		for (int k = 0; k < f_name[i].length(); k++) {
			if (f_name[i][k] == ']') {
				swap(f_name[i][k], f_name[i][k + 1]);
				k++;
			}
		}
		cout << f + f_name[i] + " " + name[i] + ";" << "\n";
	}
}