#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

vector<int> tree;
int n;
pii a[500000];

int query(int node, int value, int s, int e)
{
	if (value < s) return tree[node];
	if (value > e || s == e) return 0;
	return query(node * 2, value, s, (s + e) / 2) + query(node * 2 + 1, value, (s + e) / 2 + 1, e);
}


int update(int node, int s, int e, int value)
{
	if (s > value || e < value) return tree[node];
	if (s == e) return tree[node] = 1;
	return tree[node] = update(node * 2, s, (s + e) / 2, value) + update(node * 2 + 1, (s + e) / 2 + 1, e, value);
}

bool cmp(pii a1, pii a2) {
	return a1.second < a2.second;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	sort(a, a + n);
	for (int i = 0; i < n; i++) a[i].first = i;
	sort(a, a + n, cmp);

	tree.resize(4 * n);

	for (int i = 0; i < n; i++) {
		int ans = query(1, a[i].first, 0, n - 1);
		printf("%d\n", ans + 1);
		update(1, 0, n - 1, a[i].first);
	}

	return 0;
}