#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ofstream str;
	str.open("text.txt");
	for (int i = 0; i < 1000; i++) {
		str << i + 1 << " " << i + 2 << "\n";
	}
	system("pause");
}