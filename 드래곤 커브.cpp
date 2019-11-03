#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void Go(int cur, string key) {
	string master;
	for (int i = 0; i < key.length(); i++) {
		if (key[i] == '<') {
			if(cur !=0) cur--;
		}
		else if (key[i] == '>') {
			if (key.length() - 1 != cur) cur++;
		}
		else if (key[i] == '-') {
			if (cur != 0) {
				master.erase(cur - 1, 1);
				cur--;
			}
		}
		else {
			if (master[cur] == 0) {
				master += key[i];
				cur++;
			}
			else {
				master.insert(cur, key[i] +"0");
				master.erase(cur + 1, 1);
			}
		}
	}
	cout << master << endl;
}
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		string key;
		cin >> key;
		Go(0, key);
	}
	system("pause");
}