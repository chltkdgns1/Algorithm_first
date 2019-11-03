#include <iostream>
#include <assert.h>
#define oo 1000000000

using namespace std;
int n, best;
int a[100];   /* current addition chain */
int b[100];   /* best addition chain so far */
int d[1000];
void visit(int k)
{
	int i, j;
	if (k + d[a[k]] >= best) return;
	if (a[k] == n)
	{
		best = k;
		for (i = 0; i <= k; i++) b[i] = a[i];
		return;
	}
	for (i = k; i >= 0; i--)
		for (j = k; j >= i; j--)
		{
			a[k + 1] = a[i] + a[j];
			if (a[k + 1] > a[k] && a[k + 1] <= n) visit(k + 1);
		}
}

void solve_case()
{
	int i;
	for (i = n + n; i >= n; i--) d[i] = 0;
	for (i = n - 1; i >= 1; i--) d[i] = 1 + d[i + i];
	best = oo;
	a[0] = 1;
	visit(0);
	for (i = 0; i < best; i++)
		printf("%d ", b[i]);
	printf("%d\n", b[best]);
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		cin >> n;
		if (!n) break;
		solve_case();
	}
	system("pause");
}