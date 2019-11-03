#include<stdio.h>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
bool arr[10];
int isOK(int n) {
	if (n == 0)
		return arr[n] == true ? -1 : 1;
	int i;
	for (i = 0; n; i++) {
		if (!arr[n % 10])n /= 10;
		else return -1;
	}
	return i;
}

int main()
{
	int n, m, input, a, cnt;
	scanf("%d\n%d", &n, &m);
	input = n;

	while (m--) {
		scanf("%d", &a);
		arr[a] = true;
	}
	int min = abs(input - 100);
	for (int i = input; i <= 999999; i++) {
		cnt = isOK(i);
		if (cnt != -1) {
			min = MIN(min, (cnt + abs(input - i)));
			break;
		}
	}
	for (int i = input; i >= 0; i--) {
		cnt = isOK(i);
		if (cnt != -1) {
			min = MIN(min, (cnt + abs(input - i)));
			break;
		}
	}
	printf("%d", min);
}