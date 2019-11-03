#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

class Data {
public:
	int x, y, z;
	bool operator<(const Data &a) const {
		return z < a.z;
	}
};

class Data2 {
public:
	int size,node,idx;
	bool operator<(const Data2 &a) const {
		if (size == a.size) return idx < a.idx;
		return size > a.size;
	}
};


int d[100001];
int qurey[100001];

int find(int x) {
	if (d[x] < 0) return x;
	return d[x] = find(d[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (d[x] > d[y]) swap(x, y);
	d[x] += d[y];
	d[y] = x;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	int a, b, c;

	priority_queue <Data> pq;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}

	vector <Data2> v;
	for(int i=0;i<q;i++){
		cin >> a >> b;
		v.push_back({ a,b,i });
	}

	sort(v.begin(), v.end());

	memset(d, -1, sizeof(d));

	for (auto a : v) {
		while (!pq.empty()) {
			Data d = pq.top();
			int x = d.x, y = d.y, idx = d.z;

			if (d.z < a.size) break;
			pq.pop();

			merge(x, y);
		}
		qurey[a.idx] = -d[find(a.node)] - 1;
	}

	for (int i = 0; i < q; i++) {
		cout << qurey[i] << "\n";
	}
}