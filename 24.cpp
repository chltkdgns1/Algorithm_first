#include <iostream>
#include <string>
using namespace std;
int e,s;
int main() {
	string a, b, t1, t2,res;
	cin >> a >> b;
	int cnt = 0, t = 3600, twf = 24 * 3600;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != ':') {
			t1 += a[i];
			t2 += b[i];
			if (i == a.length() - 1) {
				e += stoi(t1);
				s += stoi(t2);
			}
		}
		else {
			e += stoi(t1) * t;
			s += stoi(t2) * t;
			t1.clear(), t2.clear();
			cnt++;
			t /= 60;
		}
	}
	t = 3600;
	if (e < s) {
		s = (s - e) ;
		for (int i = 0; i < 3; i++) {
			string r = to_string(s / t);
			if (r.length() == 1) r.insert(0, "0");
			res += r + ":";
			if (i != 2) s = s % t;	
			t /= 60;
		}
	}
	else {
		s = (s - e) + twf;
		for (int i = 0; i < 3; i++) {
			string r = to_string(s / t);
			if (r.length() == 1) r.insert(0, "0");
			res += r + ":";
			if (i != 2) s = s % t;
			t /= 60;
		}
	}
	res.pop_back();
	cout << res << "\n";
}