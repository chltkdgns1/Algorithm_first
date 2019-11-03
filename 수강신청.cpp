#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map <string,int> m;
vector <string> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	queue <string> q;
	for (int i = 0; i < k; i++) {
		string a;
		cin >> a;
		q.push(a);
		if (m.find(a) == m.end()) m[a] = 1;
		else m[a]++;
	}
	int cnt = 0;
	while (!q.empty()) {
		string e = q.front();
		if (m[e] >= 2) m[e]--;
		else if (m[e] == 1) {
			v.push_back(e);
			m[e]--;
			cnt++;
			if (cnt == n) break;
		}
		q.pop();
	}
	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}