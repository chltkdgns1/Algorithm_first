#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[8];
vector <int> arr[8];

void bfs(int start) {
	queue <int> q;
	q.push(start);
	c[start] = 1;
	cout << start << " ";
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (c[y] == 0) {
				c[y] = 1;
				q.push(y);
				cout << y << " ";
			}
		}
	}
}
int main() {
	arr[1].push_back(2);
	arr[2].push_back(1);

	arr[1].push_back(3);
	arr[3].push_back(1);

	arr[2].push_back(3);
	arr[3].push_back(2);

	arr[2].push_back(4);
	arr[4].push_back(2);

	arr[2].push_back(5);
	arr[5].push_back(2);

	arr[3].push_back(6);
	arr[6].push_back(3);

	arr[3].push_back(7);
	arr[7].push_back(3);

	arr[6].push_back(7);
	arr[7].push_back(6);
	bfs(1);
	cout << endl;
	system("pause");
}