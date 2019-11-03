#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector <int> v;
	for (int i = 0; i < 10; i++) v.push_back(i);
	cout<<lower_bound(v.begin(), v.end(), 3) - v.begin()<<"\n";
	system("pause");
}