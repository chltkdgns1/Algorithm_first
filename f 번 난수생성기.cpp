#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(0));
	
	ofstream fileprint("input.txt");

	if (fileprint.is_open()) {
		for (int i = 0; i < 100; i++) {
			int n = rand() % 100 + 3;
			int m = rand() % 100 + 1;
			fileprint << n << "\n";
			fileprint << m << "\n";

			string s;
			for (int i = 0; i < n; i++) {
				int t = rand() % 2;
				if (!t) s += 'W';
				else s += 'B';
			}

			fileprint << s << "\n";
		}
	}
}