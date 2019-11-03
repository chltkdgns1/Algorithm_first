#include <iostream>
#include <vector>
using namespace std;

char map[51][51];
pair<int, int> door[2];
vector <pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, c = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
			if (map[i][k] == '#') {
				door[c].first = k; door[c].second = i;
				c++;
			}
			else if (map[i][k] == '!') {
				map[i][k] = '0';
				v.push_back({ k,i });
			}
		}
	}
}