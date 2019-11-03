#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector <pair<int, int>> v;
vector <pair<int, int>> sh;
int main() {
	string s;
	stack <pair<int,char>> st;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if(s[i] == '(') st.push({ i,s[i] });
		else {
			int a = st.top().first;
			if (i - a == 1) sh.push_back({ a , i }); // 레이저의 갯수
			else v.push_back({ a , i }); // 막대기의 갯수
			st.pop();
		}
	}
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		for (int k = 0; k < sh.size(); k++) {
			if (v[i].first < sh[k].first && sh[k].second < v[i].second) {
				cnt++;
			}
		}
		total += (cnt + 1);
	}
	cout << total << "\n";
}