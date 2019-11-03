#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, int> m;
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	string name;
	map <string, int>::iterator iter;
	for (int i = 0; i < n; i++) {
		cin >> name;
		iter = m.find(name);
		if (iter != m.end()) (*iter).second++;
		else m.insert({ name,1 });
	}
	int max = 0;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if ((*iter).second > max) max = (*iter).second;
 	}
	for (iter = m.begin(); iter != m.end(); iter++) {
		if ((*iter).second == max) {
			cout << (*iter).first << "\n";
			break;
		}
	}
}