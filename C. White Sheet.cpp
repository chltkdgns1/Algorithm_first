#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> v[3];

int arr[4][2] = {{0,2},{0,3},{1,3},{2,1}};

bool check(int a, int x,int y) { // 한 사각형 내부에 있을 경우
	if (v[a][0].first <= x && x <= v[a][1].first &&
		v[a][0].second <= y && y <= v[a][1].second) {
		return 1;
	}
	return 0;
}

bool check2(int a, int c) {
	int x = arr[c][0], y = arr[c][1];
	if (check(a, v[0][x].first, v[0][x].second) && check(a, v[0][y].first, v[0][y].second)) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			int a, b; cin >> a >> b;
			v[i].push_back({ a,b });
		}
	}

	if ((check(1, v[0][0].first,v[0][0].second) && check(1,v[0][1].first,v[0][1].second))) {
		cout << "NO" << "\n";
		return 0;
	}
	if ((check(2, v[0][0].first,v[0][0].second) && check(2,v[0][1].first,v[0][1].second))){ 
		cout << "NO" << "\n";
		return 0;
	}

	v[0].push_back({ v[0][0].first,v[0][1].second });//왼쪽 상단점
	v[0].push_back({ v[0][1].first,v[0][0].second }); //오른쪽 하단점

	for (int i = 0; i < 2; i++) {
		if (check2(1,i) && check2(2,i + 2)) {
			if (!i && v[1][1].first >= v[2][0].first) {
				cout << "NO" << "\n";	
				return 0;
			}
			if (i && v[1][1].second >= v[2][0].second) {
				cout << "NO" << "\n"; 
				return 0;
			}
		}
		if (check2(1,i + 2) && check2(2,i)) {
			if (!i && v[1][0].first <= v[2][1].first) {
				cout << "NO" << "\n";
				return 0;
			}
			if (i && v[1][0].second <= v[2][1].second) {
				cout << "NO" << "\n"; 
				return 0;
			}
		}
	}
	cout << "YES" << "\n";
}