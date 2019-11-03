#include <iostream>
#include <vector>
#include <memory.h>
#define SIZE 3001

using namespace std;

typedef struct _tagPoint
{
	int x, y;
}POINT;

// ¾à 25mb
int parent[SIZE];
int num[SIZE] = { 0 };
int n;
vector < pair<pair<int, int>, pair<int, int>> > v;
void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		v.push_back({ {x1, y1}, {x2, y2} });

		parent[i] = i;
		num[i] = 0;
	}
}
int CCW(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3)
{
	int op = p1.first * p2.second + p2.first*p3.second + p3.first*p1.second;
	op -= (p1.first*p3.second + p2.first*p1.second + p3.first*p2.second);

	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}
bool CheckIntersect(int line1, int line2)
{
	pair<int, int> p1 = v[line1].first;
	pair<int, int> p2 = v[line1].second;
	pair<int, int> p3 = v[line2].first;
	pair<int, int> p4 = v[line2].second;

	int line1_2 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int line2_1 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if (line1_2 == 0 && line2_1 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		return p1 <= p4 && p3 <= p2;
	}
	return line1_2 <= 0 && line2_1 <= 0;
}
bool visit[SIZE];

int getParent(int p)
{
	if (parent[p] == p) return p;
	getParent(parent[p]);
}

void unoin_find(int a, int b)
{
	int p_a = getParent(a);
	int p_b = getParent(b);

	if (p_a < p_b) parent[p_b] = p_a;
	else if (p_a > p_b) parent[p_a] = p_b;
}
void solution()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (CheckIntersect(i, j))
			{
				unoin_find(i, j);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	solution();
	int iMax = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (parent[i] == i) ++cnt;
		num[getParent(i)]++;
		if (num[getParent(i)] > iMax) iMax = num[getParent(i)];
	}
	cout << cnt << '\n';
	cout << iMax << '\n';
	return 0;
}