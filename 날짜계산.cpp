#include <iostream>
using namespace std;

int main() {
	int e, s, m; // 지구 e 태양 s 달 m
	cin >> e >> s >> m;
	int e_ = 0, s_ = 0, m_ = 0;
	int i = 0;
	while (1) {
		if (e_ == e && s_ == s && m_ == m) {
			cout << i << endl;
			return 0;
		}
		e_++, s_++, m_++;
		if (e_ == 16)e_ = 1;
		if (s_ == 29)s_ = 1;
		if (m_ == 20)m_ = 1;
		i++;
	}
}