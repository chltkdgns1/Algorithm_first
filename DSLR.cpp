#include <iostream>
#include <queue>
#include <string>
using namespace std;

int a, b;
bool check[10000];

void bfs(int n,string arr) {
	queue <pair<int, string>> q;
	q.push({ n,arr });
	check[n] = true;
	while (!q.empty()) {
		int number = q.front().first;
		string s = q.front().second;
		q.pop();
		if (number == b) {
			cout << s << endl;
			return;
		}

		int t_number = (number * 2) % 10000;
		if (check[t_number] == false) {
			q.push({t_number, s + "D"});
			check[t_number] = true;
		}

		if (number == 0) t_number = 9999;
		else t_number = number - 1;
		if (check[t_number] == false) {
			q.push({t_number, s + "S"});
			check[t_number] = true;
		}

		t_number = number / 1000;
		int tt_number = number % 1000 * 10 + t_number;
		if (check[tt_number] == false) {
			q.push({ tt_number,s + "L" });
			check[tt_number] = true;
		}

		t_number = number / 10;
		tt_number = number % 10 * 1000 + t_number;
		if (check[tt_number] == false) {
			q.push({ tt_number,s + "R" });
			check[tt_number] = true;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		bfs(a, "");
		for (int i = 0; i < 10000; i++) check[i] = 0;
	}
}