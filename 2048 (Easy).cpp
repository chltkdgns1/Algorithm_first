#include <iostream>
#include <string.h>
using namespace std;

int map[20][20];
int visit[5];
int n;
int max1;
bool check[20];
void dfs(int time,int visit[]) {
	if (time == 5) {
		int temp_map[20][20];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) temp_map[i][j] = map[i][j];
		}
		for (int i = 0; i < time; i++) {
			switch (visit[i]) {
			case 1: // 왼쪽에서 오른쪽으로.
				for (int i = 0; i < n; i++) {
					int cnt = 0;
					for (int j = n - 1; j >= 0; j--) {
						if (temp_map[i][j] != 0) {
							//temp_map[i][n - 1 - cnt] = temp_map[i][j];
							if (cnt != 0) {
								if (temp_map[i][n - 1 - cnt + 1] == temp_map[i][j]) {
									temp_map[i][n - 1 - cnt + 1] += temp_map[i][j] + 1;
									check[n - 1 - cnt + 1] = true;
									temp_map[i][j] = 0;
									continue;
								}
							}
							if (n - 1 - cnt != j) {
								temp_map[i][n - 1 - cnt] = temp_map[i][j];
								temp_map[i][j] = 0;
							}
							cnt++;
						}
					}
					for (int k = 0; k < n; k++) {
						if (check[k] == true) {
							temp_map[i][k]--;
							check[k] = false;
						}
					}
				}
				break;
			case 2: // 오른쪽에서 왼쪽으로.
				for (int i = 0; i < n; i++) {
					int cnt = 0;
					for (int j = 0; j < n; j++) {
						if (temp_map[i][j] != 0) {
							if (cnt != 0) {
								if (temp_map[i][cnt - 1] == temp_map[i][j]) {
									temp_map[i][cnt - 1] += temp_map[i][j] + 1;
									check[cnt - 1] = true;
									temp_map[i][j] = 0;
									continue;
								}
							}
							if (cnt != j) {
								temp_map[i][cnt] = temp_map[i][j];
								temp_map[i][j] = 0;
							}
							cnt++;
						}
					}
					for (int k = 0; k < n; k++) {
						if (check[k] == true) {
							temp_map[i][k]--;
							check[k] = false;
						}
					}
				}
				break;
			case 3:// 위에서 아래
				for (int j = 0; j < n; j++) {
					int cnt = 0;
					for (int i = n - 1; i >= 0; i--) {
						if (temp_map[i][j] != 0) {
							if (cnt != 0) {
								if (temp_map[n - 1 - cnt + 1][j] == temp_map[i][j]) {
									temp_map[n - 1 - cnt + 1][j] += temp_map[i][j] + 1;
									check[n - 1 - cnt + 1] = true;
									temp_map[i][j] = 0;
									continue;
								}
							}
							if (n - 1 - cnt != i) {
								temp_map[n - 1 - cnt][j] = temp_map[i][j];
								temp_map[i][j] = 0;
							}
							cnt++;
						}
					}
					for (int k = 0; k < n; k++) {
						if (check[k] == true) {
							temp_map[k][j]--;
							check[k] = false;
						}
					}
				}
				break;
			case 4:// 아래에서 위
				for (int j = 0; j < n; j++) {
					int cnt = 0;
					for (int i = 0; i < n; i++) {
						if (temp_map[i][j] != 0) {
							if (cnt != 0) {
								if (temp_map[cnt - 1][j] == temp_map[i][j]) {
									temp_map[cnt - 1][j] += temp_map[i][j] + 1;
									check[cnt - 1] = true;
									temp_map[i][j] = 0;
									continue;
								}
							}
							if (cnt != i) {
								temp_map[cnt][j] = temp_map[i][j];
								temp_map[i][j] = 0;
							}
							cnt++;
						}
					}
					for (int k = 0; k < n; k++) {
						if (check[k] == true) {
							temp_map[k][j]--;
							check[k] = false;
						}
					}
				}
				break;
			}
		}
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (max < temp_map[i][j]) max = temp_map[i][j];
			}
		}
		if (max1 < max) max1 = max;
		return;
	}
	for (int i = 1; i < 5; i++) {
		if (visit[time - 1] != i) {
			visit[time] = i;
			dfs(time + 1, visit);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i < 5; i++) {
		visit[0] = i;
		dfs(1, visit);
	}
	cout << max1 << endl;
}

/*
for (int i = 0; i < n1; i++) {
		int cnt = 0;
		for (int j = n1 - 1; j >= 0; j--) {
			if (map[i][j] != 0) {
				//temp_map[i][n - 1 - cnt] = temp_map[i][j];
				if (cnt != 0) {
					if (map[i][n1 - 1 - cnt + 1] == map[i][j]) {
						map[i][n1 - 1 - cnt + 1] += map[i][j];
						map[i][j] = 0;
						continue;
					}
				}
				if (n1 - 1 - cnt != j) {
					map[i][n1 - 1 - cnt] = map[i][j];
					map[i][j] = 0;
				}
				cnt++;
			}
		}
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");

*/