#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); 
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	while (n--) {
		int d; cin >> d;
		int sum = 0;
		double aver = 0;
		for (int i = 0; i < d; i++) {
			int ss; cin >> ss; sum += ss;
			double dd; cin >> dd; aver += (dd * ss);
		}
		double sol = floor(aver * 10 / sum + 0.5f) / 10;
		printf("%d %0.1f\n", sum, sol);
	}
	return 0;
}

