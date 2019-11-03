#include <iostream>
#include <vector>
using namespace std;

vector <pair<int,char>> v[500001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; char c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}


}