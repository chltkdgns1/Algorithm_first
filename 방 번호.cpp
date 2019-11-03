#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int temp[10];
int main() {
		int n, money, min = 50, index = 0, key;
		int count = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cin >> money;
		for (int i = 0; i < n; i++) {
			if (min > arr[i]) {
				min = arr[i];
				index = i;
			}
		}
		key = (money / min);//  이게 최상의 자릿수 
		if (index == 0) { // 하지만 0으로만으로는 수를 만들 수없음
			temp[index] = key;
			for (int i = 1; i <= key; i++) {
				if (count == 0) {
					for (int j = n - 1; j > index; j--) {
						if (arr[j] <= money - (key - i)*min) {
							count++;
							temp[j]++;
							money = money - arr[j];
							temp[index] -= i;
							break;
						}
					}
				}
				else {
					for (int j = n - 1; j >= index; j--) {
						if (arr[j] <= money - (key - i)*min) {
							if (j != index) {
								temp[j]++;
								temp[index]--;
							}
							money = money - arr[j];
							break;
						}
					}
				}
			}
		}
		else {
			for (int i = 1; i <= key; i++) {
				for (int j = n - 1; j >= index; j--) {
					if (arr[j] <= money - (key - i)*min) {
						temp[j]++;
						money = money - arr[j];
						break;
					}
				}
			}
		}
		if (count == 0) temp[index] = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] > 0) {
				for (int j = 0; j < temp[i]; j++)	cout << i;
			}
		}
		cout << endl;
		system("pause");
}

/*
#include<stdio.h>
int n, c[10], p;
char r[51];
int main() {
	while (scanf("%d", &n) != -1) {
		int m = 50, idx, s = 0, rcnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", c + i);
			if (m >= c[i]) m = c[i], idx = i;
		}
		scanf("%d", &p);
		for (; p >= m;) r[rcnt++] = idx + '0', p -= m;
		for (int i = 0; i < rcnt; i++) {
			for (int j = n - 1; j >= 0; j--)
				if (c[j] <= p + m) { r[i] = j + '0'; p += m - c[j]; break; }
			if (r[s] == '0') s++, p += m;
		}
		puts(s == rcnt ? "0" : r + s);
	}
	return 0;
}

*/