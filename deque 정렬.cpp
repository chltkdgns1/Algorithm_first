#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	deque <int> q;
	for (int i = 10; i > 0; i--) {
		q.push_back(i);
	}
	sort(q.begin(), q.end());
	while (!q.empty()) {
		cout << q.front() << "\n";
		q.pop_front();
	}
	system("pause"); 
	// deque 도 정렬 잘 된다.
}