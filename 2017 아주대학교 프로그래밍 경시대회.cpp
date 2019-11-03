#include <iostream>
#include <algorithm>
using namespace std;
int s[10001], c[10001], l[10001];
int s_index[10001], c_index[10001];
int s_max = 0, c_max = 51, l_max = 180, s_data = 1, c_data = 1;
int main() {
	int n, s1, c1, l1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> c1 >> l1;
		s[i] = s1; c[i] = c1; l[i] = l1;
		if (s_max < s1) s_max = s1;
	}
	for (int i = 1; i <= n; i++) {
		if (s_max == s[i]) { // s 배열의 값들중 가장 큰 값들 모음.
			s_index[s_data] = i; // s 배열의 가장 큰 값들의 index 들
			s_data++;
		}
	}
	for (int i = 1; i < s_data; i++) {
		if (c_max > c[s_index[i]]) c_max = c[s_index[i]];
	}
	for (int i = 1; i < s_data; i++) {
		if (c[s_index[i]] == c_max) {
			c_index[c_data] = s_index[i];
			c_data++;
		}
	}
	for (int i = 1; i < c_data; i++) {
		if (l_max > l[c_index[i]]) l_max = l[c_index[i]];
	}
	for (int i = 1; i < c_data; i++) {
		if (l[c_index[i]] == l_max) {
			cout << c_index[i] << endl;
			break;
		}
	}
}