#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp[3001];
string a[3001];
class Node {
public:
	int cnt;
	Node *next[27];
	Node() {
		cnt = 0;
		memset(next,0,sizeof(next));
	}
};

class Tree {
public:
	ll t;
	Node *head;
	Tree() { head = new Node(); t = 1; }
	void insert(Node *cur,const char* key,int s,int e) {
		if (s > e) return;
		if (*key == '\0') {
			if (cur->next[26] == NULL)
				cur->cnt++;
		}
		else {
			int curr = *key - 'A';
			if (cur->next[curr] == NULL) {
				cur->next[curr] = new Node();
				cur->cnt++;
			}
			insert(cur->next[curr], key + 1,s + 1,e);
		}
	}
	void find(Node *cur) {
		if (cur->cnt) {
			t = (t*dp[cur->cnt]) % MOD;
			for (int i = 0; i < 27; i++) {
				if (cur->next[i])
					find(cur->next[i]);
			}
		}
	}
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	Tree tree;

	dp[1] = 1;
	for (int i = 2; i <= 3000; i++) dp[i] = (dp[i - 1] * i) % MOD;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int index, ago = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k < a[i].length(); k++) {
			index = k;
			if (a[i][k] != a[i + 1][k]) break;
		}
		index = max(ago, index + 1);
		tree.insert(tree.head,a[i].c_str(), 0, index);
		ago = index;
	}
	tree.insert(tree.head, a[n - 1].c_str(), 0, index);
	tree.find(tree.head);
	cout << tree.t << "\n";
}



