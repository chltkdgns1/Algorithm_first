#include <iostream>
#include <queue>
using namespace std; 
const int MAX = 1000000; 
int N; int idx = 9;
queue<long long> q; 
long long descending[MAX + 1];
void preCalculate(void) {
	while (idx <= N) { 
		if (q.empty())return;
		long long descendingNum = q.front(); 
		q.pop();	
		int lastNum = descendingNum % 10;
		for (int i = 0; i < lastNum; i++) { 
			q.push(descendingNum * 10 + i);
			descending[++idx] = descendingNum * 10 + i; 
		}
	} 
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		q.push(i);	descending[i] = i;
	}
	preCalculate(); 
	if (!descending[N] && N) 
		cout << -1 << endl;
	else		
		cout << descending[N] << endl;	
	return 0;
}