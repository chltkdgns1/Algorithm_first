#include <iostream>
#include <string>
using namespace std;
string str;
int n;
bool check(string ar) {
	int num = stoi(ar);
	for (int i = 2; i * i <=num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}
void dfs(int index) {
	if (index == n) {
		cout << str << "\n";
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (!index && !i) continue;
		if (!index && i == 1) continue;
		str += i + 48;
		if (check(str)) {
			dfs(index + 1);
		}
		str.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(0);
}