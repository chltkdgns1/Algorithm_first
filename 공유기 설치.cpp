#include <stdio.h>
#include <algorithm>
using namespace std;

int n, c;
int home[200000];

bool chk(int mid) {
	int cnt = 1;
	int cur = 0;
	int next = 1;

	while (next <= n - 1) {
		if (home[next] - home[cur] < mid)
			next++;
		else {
			cnt++;

			if (cnt == c)
				return true;

			cur = next;
			next = cur + 1;
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; ++i)
		scanf("%d", &home[i]);

	sort(home, home + n);

	int left = 1, right = home[n - 1] - home[0];
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (chk(mid)) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	printf("%d", ans);

	return 0;
}
