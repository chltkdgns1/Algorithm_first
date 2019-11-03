#include <iostream>
typedef long long ll;
using namespace std;

int arr[3] = { 1,2,3 };
ll dp[1000001];

ll Solve(int n, int index) {
	if (dp[n]) return dp[n];
	if (n - arr[index] > 0) {
		for (int i = 0; i < 3; i++)
			dp[n - arr[index]] += Solve(n - arr[index], i);
	}
	else if (n - arr[index] == 0) {
		return 1;
	}
	return 0;
}

int main() {
	int t, n;
	cin >> t;
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for(int i=0;i<3;i++) dp[1000000] += Solve(1000000,i);
	while(t--){
		cin >> n;
		cout << dp[n] << "\n";
	}
	system("pause");
}

