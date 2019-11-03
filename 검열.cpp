#include <iostream>
#include <queue>
#include <string>
using namespace std;

deque <char> q;
int pi[26];

void getpi(string a) {
	int b = 0;
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == a[b]) pi[i] = ++b;
		else if (b) {
			i--;
			b = pi[b - 1];
		}
	}
}

void find(string a, string b) {
	int c = 0;
	for (int i = 0; i < a.length(); i++) {
		if(a[i] == )
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b; cin >> a >> b;


}