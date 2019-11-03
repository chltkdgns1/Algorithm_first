#include <iostream>
using namespace std;
int arr[50][50];
int cipher(int number) {
	int cnt = 0;
	while (number) {
		number /= 10;
		cnt++;
	}
	return cnt;
}
int main() {
	int r1, c1, r2, c2, curve = 0, cnt = 1, br = 0, h_cip, s_n = 1,max = 0;
	cin >> r1 >> c1 >> r2 >> c2;
	int s_ypos = 25;
	int s_xpos = 25;
	r2 += 25; c2 += 25;
	r1 += 25, c1 += 25;
	arr[s_ypos][s_xpos] = 1;
	s_n++;
	while (1) {
		for (int i = 0; i < cnt; i++) { // 오른쪽
			s_xpos++;
			if (s_ypos > 49) { br = 1; break; }
			arr[s_ypos][s_xpos] = s_n;
			s_n++;
		}
		curve++;
		if (br == 1) break;
		if (curve == 2) { cnt++, curve = 0; }
		for (int i = 0; i < cnt; i++) { // 위
			s_ypos--;
			if (s_ypos < 0) { br = 1; break; }
			arr[s_ypos][s_xpos] = s_n;
			s_n++;
		}
		curve++;
		if (br == 1) break;
		if (curve == 2) { cnt++, curve = 0; }
		for (int i = 0; i < cnt; i++) { // 왼
			s_xpos--;
			if (s_xpos < 0) { br = 1; break; }
			arr[s_ypos][s_xpos] = s_n;
			s_n++;
		}
		curve++;
		if (br == 1) break;
		if (curve == 2) { cnt++, curve = 0; }
		for (int i = 0; i < cnt; i++) { // 아래
			s_ypos++;
			if (s_ypos > 49) { br = 1; break; }
			arr[s_ypos][s_xpos] = s_n;
			s_n++;
		}
		curve++;
		if (br == 1) break;
		if (curve == 2) { cnt++, curve = 0; }
	}
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	h_cip = cipher(max);
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			for (int k = 0; k < h_cip - cipher(arr[i][j]); k++) cout << " ";
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

#include<cstdio>
int a[50][50], r1, c1, r2, c2, m, s;
int main() {
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			int x = i - r1, y = j - c1;
			if (i - j < 0) {
				if (i + j < 0) a[x][y] = 4 * i*i + i + 1 - j;
				else a[x][y] = 4 * j*j - 3 * j + 1 - i;
			}
			else {
				if (i + j < 0) a[x][y] = 4 * j*j - j + 1 + i;
				else a[x][y] = 4 * i*i + 3 * i + 1 + j;
			}
			if (a[x][y] > m) m = a[x][y];
		}
	}
	for (; m; m /= 10) s++;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) printf("%*d ", s, a[i][j]);
		puts("");
	}
	return 0;
}