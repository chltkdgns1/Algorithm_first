#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> p[500000];
int n, r;
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) scanf_s("%d", &p[i].first), p[i].second = i;
	sort(p, p + n);
	for (int i = 0; i < n; i++) r = max(r, p[i].second - i);
	printf("%d", r);
	system("pause");
	return 0;
}