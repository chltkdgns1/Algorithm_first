#include <iostream>
#include <stack>
#include <string>
using namespace std;int main() {ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);int n,a;stack <int> s;cin >> n;for(int i=0;i<n;i++){string t;cin >> t;if (t == "push") {	cin >> a;	s.push(a);}if (t == "top") {	if (s.empty()) cout << -1 << "\n";	else cout << s.top() << "\n";}if (t == "size") cout << s.size() << "\n";if (t == "pop") {	if (s.empty()) cout << -1 << "\n";	else {	cout << s.top() << "\n";	s.pop();	}}if (t == "empty") {	if (s.empty()) cout << 1 << "\n";	else cout << 0 << "\n";	}}}