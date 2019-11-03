#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> mp1;
int main() {
	string a = "a", b = "b";
	string c = "c";
	mp1.insert(pair<string, int>(a, 1));
	mp1.insert(pair<string, int>(b, 2));
	cout << mp1[c] << endl;
	system("pause");
}