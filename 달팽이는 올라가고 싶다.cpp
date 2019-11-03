#include <iostream>

int main() {
	int A, B, V, d;
	scanf("%d %d %d", &A, &B, &V);
	d = (V - A - 1) / (A - B) + 2;
	printf("%d\n", d);

	return 0;
}