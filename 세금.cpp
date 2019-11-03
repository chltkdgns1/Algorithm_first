#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
typedef long long ll;
using namespace std;
class Data {
public:
	int from, to, cost;
};
vector <Data> v;
int dis[1001][1001];
int cnt, s, d, n, m, a;
void dinamic(int s) {

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < n; k++) dis[i][k] = INF;
	}
	dis[s][0] = 0;

	for (int i = 1; i < n; i++) {
		for (auto a : v) {
			int from = a.from, to = a.to, cost = a.cost;
			dis[to][i] = min(dis[to][i], dis[from][i - 1] + cost);
			dis[from][i] = min(dis[from][i], dis[to][i - 1] + cost);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> a;
	cin >> s >> d;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	dinamic(s);
	int min = INF;
	int num = -1;
	for (int i = 0; i < n; i++) {
		if (min > dis[d][i]) {
			min = dis[d][i];
			num = i;
		}
	}
	cout << min << "\n";
	int t = 0;
	for (int k = 0; k < a; k++) {
		int c; cin >> c;
		int min = INF; t += c;
		for (int i = num; i >= 0; i--) {
			if (min > dis[d][i] + i * t) {
				min = dis[d][i] + i * t;
				num = i;
			}
		}
		cout << min << "\n";
	}
}