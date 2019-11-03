#include <iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
vector <pair<int, int>> v;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cnt = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(),v.end());
	priority_queue<int, vector<int>, greater<int>>pq;
	pq.push(v[0].second);
	int start, end;
	for (int i = 1; i < n; i++){
		start = v[i].first;
		end = v[i].second;
		if (pq.top() > start) pq.push(end);
		else{
			pq.pop();
			pq.push(end);
		}
	}
	printf("%d\n", pq.size());
}