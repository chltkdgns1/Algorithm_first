#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define max_int 21

using namespace std;

//�ð� ���⵵: O(n^4)
//���� ���⵵: O(n^2)
//����� �˰���: ����Ž�� by BFS, STL sorting
//����� �ڷᱸ��: �׷��� by 2���� �迭


int n, cur_x, cur_y, result, cur_size, cur_eat;
int d[max_int][max_int];
int check[max_int][max_int] = {0};
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };


struct info {
	int x;
	int y;
	int dist;
};

//���� �� �ִ� ����� ������ ���� ���� v
vector<info> v;

//���� �� �ִ� ����⸦ ���ǿ� ���� �����Ѵ�.
bool cmp(const info &a, const info &b) {

	if (a.dist == b.dist) {

		if (a.x == b.x) {
			return a.y < b.y;
		}
		else return a.x < b.x;
	}
	else return a.dist < b.dist;
}

//����� ���� ��ġ���� �̵��� �� �ִ� ��� ���������� �Ÿ��� ����Ѵ�.
void find_dist(int x, int y) {

	check[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (check[nx][ny] == 0 && d[nx][ny] <= cur_size) {
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {

	scanf_s("%d", &n);

	//1. ���� ���� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &d[i][j]);
			if (d[i][j] == 9) {

				//����� ���� ��ġ ������Ʈ
				cur_x = i;
				cur_y = j;

				//���� ������ �����Ѵ�
				d[i][j] = 0;
			}
		}
	}

	//ó�� ���������� ����� ���� �ʱ�ȭ
	//����� ũ��� 2, ���� ������ 0
	cur_size = 2;
	cur_eat = 0;

	while (true) {

		//2. ����� ���� ��ġ���� �̵��� �� �ִ� ��� ���������� �Ÿ��� ����Ѵ�.
		find_dist(cur_x, cur_y);

		//3. ���� �� �ִ� ����⸦ ã�´�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				//ĭ�� ������ �ְ�, ���� �� ������
				if (d[i][j] > 0 && d[i][j] < cur_size) {

					//���� �� �ִ� ���������� �Ÿ�
					int dist = check[i][j];

					//��, ���� �� �ִ� �����������, ū ����⿡�� �ѷ��׿� �� ��������� �� �� �� �ִ�.
					//�� �� ���� ��쿡�� ���� �ʴ´�.
					if (dist > 0) v.push_back({ i, j, dist });
				}
			}
		}


		//4. ��� �̵�
		int fish_cnt = (int)v.size();

		//1) ���� �� �ִ� ����Ⱑ ���ٸ� ����
		if (fish_cnt == 0) {
			break;
		}
		else {

			//2) ���� �� �ִ� ����Ⱑ 1�������� ������
			if (fish_cnt > 1) sort(v.begin(), v.end(), cmp);

			int nx = v[0].x;
			int ny = v[0].y;
			int move_time = v[0].dist;

			//��� ũ�� ������Ʈ
			cur_eat++;
			if (cur_eat == cur_size) {
				cur_eat = 0;
				cur_size++;
			}

			//����� ��ġ ������Ʈ
			cur_x = nx;
			cur_y = ny;

			//���� ����
			d[nx][ny] = 0;

			//������ ���� �ʱ�ȭ
			v.clear();

			//üũ �迭 �ʱ�ȭ
			memset(check, 0, sizeof(check));

			//�ð� ������Ʈ
			result += move_time;
		}
	}
	printf("%d\n", result);
	system("pause");
}
