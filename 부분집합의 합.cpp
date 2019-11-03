
#include <iostream>
#include <vector>

using namespace std;

int N, S, ans = 0;
vector<int> arr;

// cnt: 배열의 인덱스, sum: 합, length: 부분집합의 길이
int dfs(int cnt, int sum, int length) {
	// 입력된 정수를 모두 활용
	if (cnt == N) {
		// 부분집합의 합이 입력과 같고 공집합이 아닐 경우
		if (sum == S && length != 0) {
			ans++;
		}
		return 0;
	}

	// 정수를 부분집합으로 선택
	dfs(cnt + 1, sum + arr[cnt], length + 1);
	// 정수를 부분집합으로 선택하지 않음
	dfs(cnt + 1, sum, length);
	return 0;
}

int main() {

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}