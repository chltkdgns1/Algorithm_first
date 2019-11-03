#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int d[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
	int year = 2014, month = 0;
	int t = 1;
	for (int i = 0; i < 3; i++) t += d[i];
	t += n;
	bool check = 0;
	while (1) {
		if (!(year % 4) && (year % 100 || !(year % 400))) {
			if (t <= 366) {check = 1; break;}
			t -= 366;
		}
		else {
			if (t <= 365) {check = 0; break;}
			t -= 365;
		}
		year++;
	}
	if (check) d[1]++;
	for (int i = 0; i < 12; i++) {
		if (t <= d[i]) { month = i + 1; break; }
		t -= d[i];
	}
	string s,e;
	s = to_string(month), e = to_string(t);
	if (s.length() == 1) s.insert(0,"0");
	if (e.length() == 1) e.insert(0, "0");
	cout << year << "-" << s << "-" << e << "\n";
}