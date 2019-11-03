#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> diction;
map<string, int> diction2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int index = 0;
	string s;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		diction.insert(pair<string, int>(s, i));
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (diction[s] != 0) {
			diction2.insert(pair<string, int>(s, index));
			index++;
		}
	}
	map<string, int>::iterator iter;
	cout << index << endl;
	for (iter = diction2.begin(); iter != diction2.end(); iter++){
		cout << (*iter).first <<"\n";
	}
}
