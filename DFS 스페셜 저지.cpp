#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector <int> v[100001];
bool check[100001];
vector <int> e,q;
int dfs(int s,int index){
	if (check[s]) return -1;
	check[s] = true;
	bool ck = false;
	e.push_back(s);
	for(int i=0;i<v[s].size();i++){
		int y = v[s][i];
		if(y == q[index] && !check[y]){
			int num = dfs(y, index + 1);
			if (num != -1) index = num;
			ck = true;
		}
	}
	cout << "\n";
	cout << index << "\n";
	return index;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		int r; cin >> r;
		q.push_back(r);
	}
	dfs(1,1);
	for (int i = 0; i < n; i++) {
		if (q[i] != e[i]) { cout << 0; return 0; }
	}
	cout << 1 << "\n";
	system("pause");
}