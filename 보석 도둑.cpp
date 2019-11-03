#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define n_ 300000 + 5
using namespace std;
int n, k;
vector<pair<int, int>> jam;
priority_queue<int> sol;
int bag[n_];
bool chk[n_];
int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		jam.push_back({ a,b });
	}
	for (int i = 0; i < k; i++) cin >> bag[i];
	sort(jam.begin(), jam.end());
	sort(bag, bag + k);
	long long ans = 0;
	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n&&jam[j].first <= bag[i]) {
			sol.push(jam[j].second);
			j++;
		}
		if (!sol.empty()) {
			ans += sol.top();
			sol.pop();
		}
	}
	cout << ans << endl;
}


/*
int main() {
	int n, k;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> je[i].m >> je[i].v;
	sort(je, je + n, cmp);
	for (int i = 0; i < k; i++) cin >> beg[i];
	sort(beg, beg + k);
	int max = 0 , index = 0 ,total=0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (beg[i] >= je[j].m ) {
				if (check_je[j] == false) {
					if (max < je[j].v) {
						max = je[j].v;
						index = j;
					}
				}
			}
			else break;
		}
		if (max != 0) {
			total += je[index].v;
			check_je[index] = true;
		}
		index = 0, max = 0;
	}
	cout << total << endl;
}
*/