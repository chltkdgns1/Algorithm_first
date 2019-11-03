#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set <string> s;
string res = "ABCDEFGHIJKLMNOP";
//            abcdefghijklmnop
char map[5][5];

class path {
public:
	int a, b, c; // 행인지 렬인지 몇번째 행렬인지 몇 칸인지
};

path p[8]; // 최대 7번이기 때문에
path r[8];
int min1 = 987654321;
void init(char m[5][5],char d[5][5]) {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) m[i][k] = d[i][k];
	}
}


void print() {
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		cout << map[i] << "\n";
	}
	cout << "\n";
}

string change() {
	string s;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			s += map[i][k];
		}
	}
	return s;
}

void dfs(int index) {
	char temp_map[5][5];
	string e = change();
	s.insert(e);

	if (e == res) {
		if (min1 > index) {
			min1 = index;
			for (int i = 0; i < index; i++) r[i] = p[i];
		}
		return;
	}
	if (index == 10) return;
	
	init(temp_map,map);

	for (int i = 0; i < 4; i++) { // 행 
		for (int z = 1; z < 4; z++) {
			for (int e = 0; e < 4; e++) {
				map[i][((e + z) % 4)] = temp_map[i][e];
			}
			string e = change();
			if (s.find(e) == s.end()) {
				p[index].a = 1, p[index].b = i + 1, p[index].c = z;
				dfs(index + 1);
			}
		}
		init(map, temp_map);
	}

	for (int k = 0; k < 4; k++) { // 렬
		for (int z = 1; z < 4; z++) {
			for (int e = 0; e < 4; e++) {
				map[((e + z) % 4)][k] = temp_map[e][k];
			}
			string e = change();
			if (s.find(e) == s.end()) {
				p[index].a = 2, p[index].b = k + 1, p[index].c = z;
				dfs(index + 1);
			}
		}
		init(map, temp_map);
	}

}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			int a; cin >> a;
			map[i][k] = a + 64;
		}
	}
	dfs(0);
	if (min1 != 987654321) {
		cout << min1 << "\n";
		for (int i = 0; i < min1; i++) {
			cout << r[i].a << " " << r[i].b << " " << r[i].c << "\n";
		}
	}
	system("pause");
}