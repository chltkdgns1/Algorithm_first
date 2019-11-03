#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

unordered_set <string> s;
string res = "ABCDEFGHIJKLMNOP";

char map[5][5];
class path {
public:
	int a, b, c; // 행인지 렬인지 몇번째 행렬인지 몇 칸인지
};

string converter(string s,int mod_a,int mod_b) {
	// mod_a 는 행과 렬인지 mod_b 는 얼마만큼 이동할지
	string t = s;
	if (mod_a < 4) {
		int index = mod_a * 4;
		for (int k = index; k < 4; k++) {
			t[(index + mod_b) % 4] = s[index];
		}
	}
	else {
		int index = mod_a - 4;
		int cnt = 4;
		for (int i = 0; i < 16; i += 4) {
			t[((index + i) + (cnt * mod_b)) % 16] = s[index + i];
	     // 이게 원래 인덱스들 // 이게 바뀔 인덱스
		}
	}
	return t;
}




void bfs(string e) {
	s.insert(e);
	queue < pair<string, vector<path>>> q;
	vector <path> v;
	q.push({ e,v });
	while (!q.empty()) {
		string e = q.front().first;
		vector <path> w = q.front().second;
		q.pop();

		if (w.size() == 7) continue;

		for (int i = 0; i < 4;i++) { // 행
			for (int z = 1; z < 4; z++) {
				string r = converter(e, i, z);
				if (s.find(r) == s.end()) {
					path t; t.a = 1, t.b = i + 1, t.c = z;
					w.push_back(t);
					q.push({ r,w });
					w.pop_back();
				}
			}
		}
		for (int i = 0; i < 4; i++) { // 렬
			for (int z = 1; z < 4; z++) {
				string r = converter(e, i + 4, z);
				if (s.find(r) == s.end()) {
					path t; t.a = 2, t.b = i + 1, t.c = z;
					w.push_back(t);
					q.push({ r,w });
					w.pop_back();
				}
			}
		}
	}
}



int main() {
	string s;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			int a; cin >> a;
			map[i][k] = a + 64;
			s += a + 64;
		}
	}
	cout << s << "\n";
	cout << converter(s, 4, 3) << "\n";

	//bfs(s);


	system("pause");
}