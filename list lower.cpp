#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main() {
	list <int> st;
	vector <int> v;
	for (int i = 0; i < 100000; i++) {
		st.push_back(i);
	}

	//for (int i = 0; i < 100000; i++) {
	//	v.push_back(i);
	//}

	int q; cin >> q;
	while (q--) {
		int a; cin >> a;
		cout << (*lower_bound(st.begin(), st.end(), a))<< "\n";
		//cout << lower_bound(v.begin(), v.end(), a) - v.begin() << "\n";
	}
}