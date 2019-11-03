#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int map[1001];
class Data {
public:
	string ar;
	int s, b;
};
Data d[100];

void Go(string ar, int s, int b) {
	char arr[4];
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (i == j) continue;
			for (int k = 1; k < 10; k++) {
				int s_n = 0, b_n = 0;
				if (j == k || i == k) continue;
				arr[0] = i + '0';
				arr[1] = j + '0';
				arr[2] = k + '0';
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (i == j && arr[i] == ar[i]) s_n++;
						else if (arr[i] == ar[j]) b_n++;
					}
				}
				if (s == s_n && b == b_n) {
					map[atoi(arr)]++;
				}
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) cin >> d[i].ar >> d[i].s >> d[i].b;
	for (int i = 0; i < t; i++) {
		Go(d[i].ar, d[i].s, d[i].b);
	}
	int cnt = 0;
	for (int i = 100; i <= 999; i++) {
		if (map[i] == t) cnt++;
	}
	cout << cnt << endl;
}