#include<iostream>
#include <map>
using namespace std; 
int n, l, b, c;
multiset<int>s{ 0 };
map<int, multiset<int>>p;
int main()
{
	for (cin >> n; n--; p[l].insert(b), p[c].insert(-b))cin >> l >> b >> c;
	for (auto&x : p)
	{
		for (int t : x.second) t < 0 ? s.erase(s.find(-t)) : s.insert(t);
		n - (l = *s.rbegin()) && printf("%d %d ", x.first, n = l);
	}
}