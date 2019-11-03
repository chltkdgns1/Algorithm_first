#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	int t = s / n, q = s % n;
	// t 가 제일 작은 값
	vector<int> answer;
	if (t) {
		for (int i = 0; i < n - q; i++) answer.push_back(t);
		for (int i = 0; i < q; i++) answer.push_back(t + 1);
	}
	else answer.push_back(-1);
	return answer;
}

int main() {
	int a, b; cin >> a >> b;
	for (auto a : solution(a, b)) {
		cout << a << " ";
	}
	cout << "\n";
	system("pause");
}