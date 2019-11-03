#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int d[10];

int solution(vector<int> priorities, int location) {

	vector <int> v = priorities;
	int cnt = 0;
	for (auto a : priorities) {
		d[a]++;
	}

	int answer = 1;
	int lc = 0;
	for (int i = 9; i >= 1; i--) {
		while (d[i]) {
			for (int k = lc; k < v.size(); k++) {
				lc = k;
				if (k == v.size() - 1) lc = 0;
				if (i == v[k]) {
					d[i]--;
					if (k == location) {
						return answer;
					}
					v[k] = -1;
					answer++;
					if (!d[i]) break;
				}
			}
		}
	}
}

int main() {
	vector <int> v;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	cout << solution(v, m) << "\n";
	system("pause");
}