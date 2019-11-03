#include <iostream>
#include <string>
using namespace std;

char arr[26] = { 'y','h' ,'e' ,'s' ,'o' ,'c' ,'v' ,'x' ,'d' ,'u' ,'i' ,'g' ,'l' ,'b',
'k' ,'r' ,'z' ,'t' ,'n' ,'w' ,'j' ,'p' ,'f' ,'m' ,'a','q'};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int cnt = 1;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		cout << "Case #" << cnt << ": ";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') cout << s[i];
			else cout << arr[s[i] - 97];
		}
		cnt++;
		cout << "\n";
	}
}