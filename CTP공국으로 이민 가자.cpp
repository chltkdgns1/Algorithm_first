#include <iostream>
using namespace std;
char d[27] = { 0,'A','B','C' ,
'D' ,'E' ,'F' ,'G' ,'H' ,
'I' ,'J' ,'K' ,'L' ,'M' ,
'N' ,'O' ,'P' ,'Q' ,'R' ,
'S' ,'T' ,'U' ,'V' ,'W' ,
'X' ,'Y' ,'Z' };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a; char c;
		cin >> a >> c;
		if (c == 'C') {
			for (int i = 0; i < a; i++) {
				char b; cin >> b;
				cout << int(b - 64) << " ";
			}
		}
		else {
			for (int i = 0; i < a; i++) {
				int a; cin >> a;
				cout << d[a] << " ";
			}
		}
		cout << "\n";
	}
}