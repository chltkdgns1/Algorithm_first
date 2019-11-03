#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
int total = 0;
int d[15];
bool check(int a) {
	for (int i = 0; i < a ; i++) {
		if (d[i] == d[a] || abs(d[i] - d[a]) == abs(i - a)) return false;
	}
	return true;
}
void dfs(int a) {
	if (a == n) {
		total += 1;
	}
	else {
		for (int i = 0; i < n; i++) {
			d[a] = i;
			if (check(a) == true) {
				dfs(a + 1);
			}
		}
	}
}
int main() {
	cin >> n;
	dfs(0);
	cout << total << "\n";
}