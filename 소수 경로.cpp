#include <iostream>
#include <queue>
#include <string.h>
#include <stdlib.h>
using namespace std;

int arr[10001];
char a[5], b[5];
bool check[10001];
int key;
class arrData {
public :
	char arr[5];
	arrData() { for (int i = 0; i < 5; i++) arr[i] = 0; }
};
arrData d;
arrData temp, temp2;
void bfs() {
	queue <arrData> q;
	q.push(d);
	check[atoi(d.arr)] = true;
	int cnt = 0;
	while (1) {
		int len = q.size();
		if (len == 0) {
			key = -1;
			return;
		}
		for (int i = 0; i < len; i++) {
			for (int i = 0; i < 4; i++) {
				temp.arr[i] = temp2.arr[i] = q.front().arr[i];
			}
			q.pop();
			if (strcmp(temp.arr, b) == 0) {
				key = cnt;
				return;
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) continue;
					if (temp.arr[i] != j + 48) {
						temp2.arr[i] = j + 48;
						int number = atoi(temp2.arr);
						if (arr[number] == 0 && check[number] == false) {
							q.push(temp2);
							check[number] = true;
						}
						temp2.arr[i] = temp.arr[i];
					}
				}
			}
		}
		cnt++;
	}
}
int main() {
	for (int i = 2; i <= 5000; i++) {
		int j = 2;
		if (arr[i] == 0) {
			while (1) {
				if (i*j > 10000) break;
				arr[i*j] = 1;
				j++;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cin >> a >> b;
		for (int i = 0; i < 4; i++) {
			d.arr[i] = a[i];
		}
		bfs();
		if (key == -1) cout << "Impossible" << endl;
		else cout << key << endl;
		key = 0;
		for (int i = 0; i < 4; i++) temp.arr[i] = temp2.arr[i] = 0;
		for (int i = 1000; i <= 9999; i++) check[i] = 0;
	}
}

