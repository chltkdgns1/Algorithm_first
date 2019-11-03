#include <iostream>
#include <string>
using namespace std;

string solution(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (!i) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] -= 32;
			}
		}
		else {
			if (s[i - 1] == ' ') {
				if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
		}
	}
	string answer = s;
	return answer;
}

int main() {
	string s; getline(cin,s);
	cout << solution(s) << "\n";
	system("pause");
}