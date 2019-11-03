#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Data {
public:
	int x, y, d,l,r;
};

bool cmp(Data &a, Data &b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y > b.y;
}

vector<vector<int>> answer;
vector <Data> v, e;

void pre(int index) {
	if (!index) return;
	answer[0].push_back(e[index].d);
	pre(e[index].l);
	pre(e[index].r);
}

void post(int index) {
	if (!index) return;
	post(e[index].l);
	post(e[index].r);
	answer[1].push_back(e[index].d);
}

void makeTree(Data d,int index) {
	if (e[index].x < d.x) {
		if (!e[index].r) {
			e[index].r = d.d;
			e[d.d] = d;
		}
		else makeTree(d, e[index].r);
 	}
	else if(e[index].x > d.x){
		if (!e[index].l) {
			e[index].l = d.d;
			e[d.d] = d;
		}
		else makeTree(d, e[index].l);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	int index = 1;
	for (auto a : nodeinfo) {
		v.push_back({ a[0],a[1],index++,0,0});
	}
	answer.resize(2);
	sort(v.begin(), v.end(), cmp);
	e.resize(v.size() + 1);
	e[v[0].d] = v[0];
	for (int i = 1; i < v.size(); i++) {
		makeTree(v[i], v[0].d);
	}
	pre(v[0].d),post(v[0].d);
	return answer;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector <vector<int>> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v[i].push_back(a);
		v[i].push_back(b);
	}
	solution(v);
	system("pause");
}