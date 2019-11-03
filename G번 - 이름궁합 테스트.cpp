#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[26] = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	string a, b, t;
	cin >> a >> b;
	int len = 0, max_len;
	len = min(a.length(), b.length());
	max_len = max(a.length(), b.length());
	int x = 0, y = 0;
	for(int i=0;i<len*2;i++){
		if (!(i % 2)) t += a[x++];
		else t += b[y++];
	}
	if(a.length() > b.length()) for (int i = y; i < max_len; i++) t += a[i];
	else for (int i = y; i < max_len; i++) t += b[i];
	for (int i = 0; i < t.length(); i++) {
		t[i] = arr[t[i] - 'A'] + 48;
	}
	while (t.length() != 2) {
		string c;
		for (int i = 0; i < t.length() - 1; i++) {
			c += (t[i] - 48 + t[i + 1] - 48) % 10 + 48;
		}
		t = c;
	}
	if(t.length() == 2 && t[0] =='0') 	cout << t[1] << "%" << "\n";
	else cout << t << "%" << "\n";
}

