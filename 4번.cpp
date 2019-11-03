#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map <string, int> m;

bool cmp(string &a, string &b) {
	return a.length() < b.length();
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	sort(words.begin(), words.end(), cmp);
	for (auto a : queries) {
		if (m[a]) {
			answer.push_back(m[a]);
			continue;
		}
		int res = 0, alen = a.length();

		if (a[0] == '?' && a[alen - 1] == '?') {
			for (auto b : words) {
				if (alen == b.length()) res++;
				else if (alen < b.length()) break;
			}
			m[a] = res;
			answer.push_back(res);
			continue;
		}
		if (a[0] == '?') {

			for (auto b : words) {
				int cnt = 1, len = b.length();
				bool ch = 0;

				if (alen != len) continue;
				if (alen < len) break;
				while (alen - cnt >= 0) {
					if (a[alen - cnt] == '?') break;
					if (len - cnt < 0) {
						ch = 1;
						break;
					}
					if (b[len - cnt] != a[len - cnt]) {
						ch = 1;
						break;
					}
					cnt++;
				}
				if (!ch) res++;
			}
		}
		else {

			for (auto b : words) {
				int cnt = 0, len = b.length();
				bool ch = 0;

				if (alen != len) continue;
				if (alen < len) break;
				while (cnt < alen) {
					if (a[cnt] == '?') break;
					if (cnt == len) {
						ch = 1;
						break;
					}
					if (b[cnt] != a[cnt]) {
						ch = 1;
						break;
					}
					cnt++;
				}
				if (!ch) res++;	
			}
		}
		m[a] = res;
		answer.push_back(res);
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector <string> a, b;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		a.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		b.push_back(s);
	}
	for (auto a : solution(a, b)) {
		cout << a << " ";
	}
	cout<<"\n";
	system("pause");
}