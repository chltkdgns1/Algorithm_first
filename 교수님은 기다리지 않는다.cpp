#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int n, m;
char type;
int a, b, c,par[MAXN], sze[MAXN];
ll dist[MAXN];
pair<int, ll> find(int x, ll ret) {
	if (x == par[x]) return { x, ret };
	return find(par[x], ret + dist[x]);
}
void merge(int a, int b, int t) {
	auto x = find(a, 0), y = find(b, 0);
	if (x.first == y.first) return;
	if (sze[x.first] > sze[y.first]) {
		dist[y.first] -= (y.second - x.second - t);
		par[y.first] = x.first;
		sze[x.first] += sze[y.first];
		sze[y.first] = 1;
	}
	else {
		dist[x.first] += (y.second - x.second - t);
		par[x.first] = y.first;
		sze[y.first] += sze[x.first];
		sze[x.first] = 1;
	}
}
int main() {
	while (scanf("%d%d", &n, &m), !(n == 0 && m == 0)) {
		memset(dist, 0, sizeof dist);
		for (int i = 1; i <= n; i++) par[i] = i, sze[i] = 1;
		for (int i = 0; i < m; i++) {
			scanf(" %c", &type);
			if (type == '!') {
				scanf("%d%d%d", &a, &b, &c);
				merge(a, b, c);
			}
			else {
				scanf("%d%d", &a, &b);
				auto aa = find(a, 0);
				auto bb = find(b, 0);
				if (aa.first != bb.first) {
					printf("UNKNOWN\n");
				}
				else {
					printf("%lld\n", -aa.second + bb.second);
				}
			}
		}
	}
	return 0;
}