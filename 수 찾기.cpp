#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set <int> s;
	int n, m, input_number;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> input_number;
		s.insert(input_number);
	}
	cin >> m;
	pair<set<int>::iterator, bool > result;
	for (int i = 0; i < m; i++) {
		cin >> input_number;
		result = s.insert(input_number);
		if(result.second == 0) cout << "1" << "\n";
		else cout << "0" << "\n";
	}
}