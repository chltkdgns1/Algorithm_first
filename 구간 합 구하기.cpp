#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 0;
 	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) +
		sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector <long long> tree(tree_size), arr;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	init(arr, tree, 1, 0, n - 1);
	for (int i = 0; i < k + m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long dif = c - arr[b - 1];
			arr[b - 1] = c;
			update(tree, 1, 0, n - 1, b - 1, dif);
		}
		else if (a == 2) {
			cout << sum(tree, 1, 0, n - 1, b - 1, c - 1 ) << "\n";
		}
	}
}







/*
#include <iostream>
using namespace std;
long long arr[1000001], d[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 1) d[i] = arr[i];
		else d[i] = d[i - 1] + arr[i];
	}
	
	for (int i = 0; i < k + m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			for (int i = b; i <= n; i++) d[i] += c - arr[b];
		}
		else if (a == 2) {
			cout << d[c] - d[b - 1] << "\n";
		}
	}
}
*/
/*
Prefix Sum

견해 : 일단 하면서 느낀거는 일정한 값에서 하는 쿼리에 대한 응답으로는 실로 빠르다고
       생각이든다. 하지만 배열의 값이 바뀌게 되면 미리 계산해놓은 구간합들을 다시 한번
	   계산해줘야 하는 경우가 생긴다.
	   위의 코드 17 18 번째 줄이 그 경우인데 실제로 백준의 문제를 풀때 시간초과가 발생한다.
	   내 생각으로는 옛날에 풀이로 보았던 세그먼트 트리를 이용해서 간단하게 해결할 수 있을것 같다.
*/
