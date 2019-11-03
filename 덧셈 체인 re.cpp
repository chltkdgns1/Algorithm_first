#include <iostream>
#include <vector>
using namespace std;

vector <int> res;
void dfs(vector <int> &v,int n) {
	if (v.back() == n) {
		res = v;
		return;
	}
	if (!res.empty() && res.size() <= v.size() + 1) return;
	bool visit[101] = { 0 };
	for (int i = 0; i < v.size(); i++) visit[v[i]] = 1;
	for (int i = n; i > v.back(); i--) {
		bool flag = 0;
		for (int k = 0; k < v.size(); k++) {
			if (visit[i - v[k]] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			v.push_back(i);
			dfs(v, n);
			v.pop_back();
		}
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		vector <int> v;
		int n; cin >> n;
		if (!n) break;
		v.push_back(1);
		dfs(v, n);
		for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
		cout << "\n";
		res.clear();
	}
}