#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

unordered_set <string> s;
int n, k;

bool same(vector <int> &v) {
	int c;
	for (int i = 0; i < v.size(); i++) {
		if (!i) c = v[i];
		else {
			if (c != v[i]) return false;
		}
	}
	return true;
}

void bfs(vector <int> &v) {
	queue <vector<int>> q;
	q.push(v);
	int cnt = 0;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			vector <int> st = q.front();
			for (int i = 0; i < st.size(); i++) {
				cout << st[i] << " ";
			}
			cout << "\n";
			int check;
			int start = -1, end = -1;
			if (same(st)) {
				cout << cnt << "\n";
				return;
			}
			q.pop();
			for (int z = 0; z < st.size(); z++) {
				if (!z) check = st[z], start = 0 , end = 0;
				else {
					if (st[z] == check) end = z;
					else {
						vector <int> e = st;
						for (int i = start; i <= end; i++) {
							e[i]++;
							if (e[i] == k) e[i] = 0;
						}
						sort(e.begin(), e.end());
						string str;
						for (int i = 0; i < e.size(); i++) {
							str += to_string(e[i]);
						}
						if (s.find(str) == s.end()) {
							q.push(e);
							s.insert(str);
						}

						start = end = z;
						check = st[z];
					}
					
				}
			}
		}
		cout << "\n";
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	string st; 
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		st += a + 48;
	}
	sort(st.begin(), st.end());
	s.insert(st);
	sort(v.begin(), v.end());
	bfs(v);
	system("pause");
}