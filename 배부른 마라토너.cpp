#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	map <string,int> s;
	int n;
	cin >> n;
	string a;
	map <string, int>::iterator iter;
	for (int i = 0; i < n; i++) {
		cin >> a;
		 iter = s.find(a);
		 if (iter != s.end()) (*iter).second++;
		 else s.insert({ a,1 });
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		iter = s.find(a);
		if (iter != s.end()) (*iter).second--;
	}
	for (iter = s.begin(); iter != s.end(); iter++) {
		if ((*iter).second == 1) {
			cout << (*iter).first << "\n"; break;
		}
	}
}