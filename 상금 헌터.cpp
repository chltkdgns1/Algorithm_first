#include <iostream>
using namespace std;
int f1[6] = { 1,3,6,10,15,21 };
int cost1[6] = { 500,300,200,50,30,10 };
int f2[6] = { 1,3,7,15,31 };
int cost2[6] = { 512,256,128,64,32 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int t = 0;
		for (int i = 0; i < 6; i++) {
			if (!a) break;
			if (a <= f1[i]) {
				t += cost1[i];
				break;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (!b) break;
			if (b <= f2[i]) {
				t += cost2[i];
				break;
			}
		}
		cout << t * 10000 << "\n";
	}
	system("pause");
}