#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
	int N; cin >> N;
	while (N--) {
		string str; cin >> str;
		cout << (regex_match(str, regex("(100+1+|01)+")) ? "YES\n" : "NO\n");
	}
}
