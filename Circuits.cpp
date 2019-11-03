#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int>> v;
vector <int> tree(400000);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		v.push_back({ d,b });
	}
}