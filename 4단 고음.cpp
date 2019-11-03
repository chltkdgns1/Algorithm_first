#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int a;
int answer;
void solve(int n,int cnt) { // ������ �� cnt �� ��� ��������
	if (n < 3 || n < pow(3, cnt / 2)) return;
	if (n == 3) {
		if (cnt == 2) answer++;
	}
	else if (n > 3) {
		if (n % 3 == 0 && cnt >= 2) {
			solve(n / 3, cnt - 2);
		}
		solve(n - 1, cnt + 1);
	}
}

int solution(int n) {
	a = n;

	answer = 0;
	solve(n, 0);
	cout << answer << "\n";
	return answer;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	solution(n);
	system("pause");
}