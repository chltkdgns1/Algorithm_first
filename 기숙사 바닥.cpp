#include <iostream>
using namespace std;int arr[2500000];int main() {int r, b, index = 1;int first_index = 1;cin >> r >> b;for (int i = 1; i <= b; i++) {if (b % i == 0) {	arr[index] = i;	index++;	}}index--;while (1) {if (first_index > index) break;if (r == (arr[first_index] * 2) + (arr[index] + 2) * 2) {cout << arr[index] + 2 << " " << arr[first_index] + 2 << endl;break;}index--;	first_index++;}}

/*
�˰���

�ϴ� ������ Ÿ���� ������� ��� ���ؼ� ������ Ÿ���� ������ ȯ���Ѵ�.
�׸��� �� ������ ������ �װ� �츮�� ���ϴ� Ÿ���� ũ���̴�.

	for (int i = 1; i <= r + b; i++) {
		if ((r + b) % i == 0) {
			arr[index] = i;
			index++;
		}
	}
	index--;
	if (index % 2 == 0) cout << arr[index / 2 + 1] << " " << arr[index / 2 ] << endl;
	else cout << arr[index / 2 + 1 ] << " " << arr[index / 2 + 1] << endl;
*/