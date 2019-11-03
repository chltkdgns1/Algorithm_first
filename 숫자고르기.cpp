#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v[101];
bool visit[101];
int ar[101];
vector <int> e;
int check[101];
void dfs(int number,int ar[],int index) {
	if (visit[number]) {
		int idx = 0;
		bool bre = 0;
		for (int i = 0; i < index; i++) {
			if (ar[i] == number) {
				idx = i;
				bre = 1;
			}
		}
		if (bre) {
			for (int i = idx; i < index; i++) {
				e.push_back(ar[i]);
			}
		}
		return;
	}
	visit[number] = true;
	ar[index] = number;
	dfs(v[number][0], ar,  index + 1);
	ar[index]  = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, number;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> number;
		v[i].push_back(number);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ar[0] = i;
			dfs(v[i][0], ar, 1);
			ar[0] = 0;
		}
	}
	cout << e.size() << "\n";
	sort(e.begin(), e.end());
	for (int i = 0; i < e.size(); i++)cout << e[i] << "\n";
}