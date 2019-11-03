#include <iostream>
#include <map>
using namespace std;

map <int, pair<int, bool>> m; // 첫번째 왼족 범위 오른쪽 그다음 0 1 
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