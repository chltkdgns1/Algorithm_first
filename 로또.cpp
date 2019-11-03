#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[13];
vector <int> key[924];
int vec_index;
int storage[6];
int n;
void dfs(int number,int index) {
	if (index == 6) {
		for (int i = 0; i < index; i++) {
			key[vec_index].push_back(storage[i]);
		}
		vec_index++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if ( number < arr[i] ) {
			storage[index] = arr[i];
			dfs(arr[i], index + 1);
			storage[index] = 0;
		}
	}
}

int main() {
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		int i = 0;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n; i++) {
			storage[0] = arr[i];
			dfs(arr[i], 1);
		}
		for (int i = 0; i < vec_index; i++) {
			for (int j = 0; j < key[i].size(); j++) {
				cout << key[i][j] << " ";
			}
			key[i].clear();
			cout << endl;
		}
		cout << endl;
		vec_index = 0;
		for (int i = 0; i < 6; i++) storage[i] = 0;
	}
}