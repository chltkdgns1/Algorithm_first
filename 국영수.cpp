#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class st {
public:
	string name;
	int a, b, c;
};
st s[100000];
bool cmp(const st &a,const st &b) {
	if (a.a == b.a) {
		if (a.b == b.b) {
			if (a.c == b.c) {
				return a.name < b.name;
			}
			else return a.c > b.c;
		}
		else return a.b < b.b;
	}
	else return a.a > b.a;
}
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name;
		cin>> s[i].a >> s[i].b >> s[i].c;
	}
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i].name << "\n";
	}
}