#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
bool check[MAX + 1];
int n, m;
void bfs(int s) {
	check[s] = 1;
	priority_queue <pair<int,int>> q;
	q.push({ 0,s });
	while (!q.empty()) {
		int cnt = -q.top().first;
		int p = q.top().second;
		check[p] = 1;
		if (p == m) {
			cout<<cnt<<"\n";
			return;
		}
		q.pop();
		if (p * 2 <= MAX && !check[p * 2]) q.push({ -cnt,p * 2 });
		if (p + 1 <= MAX && !check[p + 1]) q.push({ -(cnt + 1),p + 1 });
		if (p - 1 >= 0 && !check[p - 1]) q.push({ -(cnt + 1),p - 1 });
	}
}

int main() {
	cin >> n >> m;
	int x = n;
	bfs(n);
}