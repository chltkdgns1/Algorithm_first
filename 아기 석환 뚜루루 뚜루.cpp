#include <iostream>
#include <string>
using namespace std;

string st[14] = { "baby","sukhwan","tururu","turu",
"very","cute","tururu","turu","in","bed","tururu","turu","baby","sukhwan"};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	n--;
	int index = n % 14 ;
	if (st[index] == "tururu" || st[index] == "turu") {
		if (st[index] == "tururu") {
			if(n/14 + 2 >= 5) cout << "tu+ru*" << n / 14 + 2<< "\n";
			else {
				string s;
				for (int i = 0; i < n / 14; i++) s += "ru";
				cout << st[index] + s << "\n";
			}
		}
		else {
			if (n / 14 + 1 >= 5) cout << "tu+ru*" << n / 14 + 1 << "\n";
			else {
				string s;
				for (int i = 0; i < n / 14; i++) s += "ru";
				cout << st[index] + s << "\n";
			}
		}
	}
	else cout << st[index] << "\n";
}