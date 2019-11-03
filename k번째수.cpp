#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	int size = commands.size();

	vector <int> answer, v = array;
	for (int i = 0; i < size; i++) {
		int arr[3];
		for (int k = 0; k < 3; k++) {
			arr[k] = commands[i][k] - 1;
		}

		sort(v.begin() + arr[0], v.begin() + arr[1] + 1);
		answer.push_back(v[arr[0] + arr[2]]);

		for (int i = arr[0]; i <= arr[1]; i++) v[i] = array[i];
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;

	vector <int> v;
	vector <vector<int>> e(m);

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < m; i++) {
		for (int k = 0; k < 3; k++) {
			int a; cin >> a;
			e[i].push_back(a);
		}
	}

	for (auto a : solution(v, e)) {
		cout << a << " ";
	}
	system("pause");
}
