#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Data {
public:
	int a, b, c;
};

bool cmp(const Data&a, const Data&b) {
	return a.b < b.b;
}

int dp[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, a, b, c;
		cin >> n >> m;
		memset(dp, 987654321, sizeof(dp));
		vector <Data> v;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c; // 갯수 가격 택배비
			v.push_back({ a,b,c });
		}

		sort(v.begin(), v.end(), cmp);
		
		for (int i = 0; i < m; i++) {

		}
	}
}