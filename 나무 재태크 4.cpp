#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maps[10][10];
int n, m, k;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
class tree {
public:
	vector <int> v;
	int g;
};

tree map[10][10];

bool check(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}

void sortingTree() { // ���� ������ ������ ���̼� ����
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			sort(map[i][k].v.begin(), map[i][k].v.end());
		}
	}
}

void springSummer() { // �� ����
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (map[i][k].v.size()) {
				int t = map[i][k].g, store_g = 0;
				vector <int> ::iterator it = map[i][k].v.begin();
				for (int z = 0; z < map[i][k].v.size(); z++, it++) {
					int y = map[i][k].v[z];
					if (t - y >= 0) {
						t -= y;
						map[i][k].v[z] += y;
					}
					else {
						store_g += (*it) / 2;
						map[i][k].v.erase(it);
						z--;
						it--;
					}
				}
				map[i][k].g = t + store_g;
			}
		}
	}
}

void fall() { // ����
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			int len = map[i][k].v.size();
			if (len) {
				for (int z = 0; z < len; z++) {
					if (map[i][k].v[z] >= 5) {
						for (int q = 0; q < 8; q++) {
							int nx = k + dx[q];
							int ny = i + dy[q];
							if (check(nx, ny)) {
								map[ny][nx].v.push_back(1);
							}
						}
					}
				}
			}
		}
	}
	sortingTree(); // ������ �߰��Ǿ����� ����
}

void winter() { // �ܿ�
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			map[i][k].g += maps[i][k]; // ��� �߰�
		}
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> maps[i][k]; // �ų� �ܿ￡ �߰��� ����� ��
			map[i][k].g = 5; // �� �� ��� 5�� ����
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		map[y - 1][x - 1].v.push_back(age);
	}

	sortingTree();
	for (int i = 0; i < k; i++) {
		//��//����
		springSummer();
		//����
		fall();
		//�ܿ�
		winter();
	}
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			t += map[i][k].v.size();
		}
	}
	cout << t << "\n";
	system("pause");
}