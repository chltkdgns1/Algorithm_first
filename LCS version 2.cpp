#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1000];
int dp[1000];
int main() {
	int n, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
		result = max(dp[i], result);
	}
	printf("%d", result);
	system("pause");
}
