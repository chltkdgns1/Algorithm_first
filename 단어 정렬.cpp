#include <iostream>
#include <string>
#include <set>
using namespace std;
set <string> s[51];
int main() {
	int n;
	cin >> n;
	string word;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> word;
		s[word.length()].insert(word);
		if (max < word.length()) max = word.length();
	}
	for (int i = 1; i <= max; i++) {
		if (s[i].size() != 0) {
			for (set <string>::iterator iter = s[i].begin(); iter != s[i].end(); iter++) {
				cout << *iter << endl;
			}
		}
	}
}