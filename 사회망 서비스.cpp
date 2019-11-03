#include<cstdio>
#include<vector>
using namespace std;
const int MXN = 1e6;
int n, ck[MXN + 1], res;
vector<int> adj[MXN + 1];
void f(int h, int p) {
	int flag = 0;
	for (auto it : adj[h]) if (it^p) {
		f(it, h);
		flag |= !ck[it];
	}
	if (flag) ck[h] = 1, res++;
}
int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	f(1, 0);
	printf("%d", res);
	return 0;
}