#include <iostream>
#include <map>
using namespace std;

map <int, pair<int, bool>> m; // ù��° ���� ���� ������ �״��� 0 1 
void makePlace(int a,int b) {

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	m.insert({ 1,{n,0} });
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (!i) m.insert({ a,{b,1} });
	}
}