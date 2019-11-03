#include <iostream>
#include <math.h>
using namespace std;

int n, k;
int map[100][100];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int key_cnt = 0;
	for (int i = 0; i < n; i++) {
		int hight = map[i][0];
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (map[i][j] == hight && j == n - 1) key_cnt++;
			if (map[i][j] == hight) cnt++;
			else if (abs(map[i][j] - hight) == 1) {
				if (map[i][j] > hight) { // ���̰� ���� ���
					if (k > cnt) break;
					else {
						cnt = 1;
						hight = map[i][j];
						if (j == n - 1) key_cnt++;
						continue;
					}
				}
				else { // ���� ������ ������ ���
					cnt = 1;
					hight = map[i][j];
					int c;
					for (c = j + 1; c < n; c++) {
						if (hight == map[i][c]) cnt++;
						else if (hight != map[i][c]) break;
					}
					if (k > cnt) break;
					if (c == n ) {
						key_cnt++;
						break;
					}
					cnt -= k; // �ٸ� ��ġ ���
					j = (c - 1); // 1�ܰ� �������� �̵�
				}
			}
			else break;
		}
	}
	for (int i = 0; i < n; i++) {
		int hight = map[0][i];
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (map[j][i] == hight && j == n - 1) key_cnt++;
			if (map[j][i] == hight) cnt++;
			else if (abs(map[j][i] - hight) == 1) {		
				if (map[j][i] > hight) { // ���̰� ���� ���
					if (k > cnt) break;	
					else {
						cnt = 1;
						hight = map[j][i];
						if (j == n - 1) key_cnt++;
						continue;
					}
				}
				else { // ���� ������ ������ ���
					//if (i == 0) cout << "B" << endl;
					cnt = 1;
					hight = map[j][i];
					int c;
					for (c = j + 1; c < n; c++) {
						if (hight == map[c][i]) cnt++;
						else if (hight != map[c][i]) break;
					}
					if (k > cnt)break;
					if (c == n ) {
						key_cnt++;
						break;
					}
					cnt -= k; // �ٸ� ��ġ ���
					j = (c - 1); // 1�ܰ� �������� �̵�

				}
			}
			else break;	
		}
	}
	cout << key_cnt << endl;
}