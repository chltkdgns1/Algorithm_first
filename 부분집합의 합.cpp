
#include <iostream>
#include <vector>

using namespace std;

int N, S, ans = 0;
vector<int> arr;

// cnt: �迭�� �ε���, sum: ��, length: �κ������� ����
int dfs(int cnt, int sum, int length) {
	// �Էµ� ������ ��� Ȱ��
	if (cnt == N) {
		// �κ������� ���� �Է°� ���� �������� �ƴ� ���
		if (sum == S && length != 0) {
			ans++;
		}
		return 0;
	}

	// ������ �κ��������� ����
	dfs(cnt + 1, sum + arr[cnt], length + 1);
	// ������ �κ��������� �������� ����
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