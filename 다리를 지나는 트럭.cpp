#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;

	int sum, count; sum = count = 0;

	for (int i = 0; i < truck_weights.size(); i++) {
		int d = truck_weights[i];

		while (true) {

			if (q.empty()) {
				q.push(d);
				count++;
				sum += d;
				break;
			}
			else if (q.size() == bridge_length) {
				sum -= q.front(); q.pop();
			}
			else {

				if (sum + d > weight) {
					q.push(0);
					count++;
				}
				else {
					q.push(d);
					count++;
					sum += d;
					break;
				}
			}
		}
	}
	return count + bridge_length;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	int a, b, n; cin >> a >> b >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		v.push_back(c);
	}

	cout << solution(a, b, v) << "\n";
	system("pause");
}