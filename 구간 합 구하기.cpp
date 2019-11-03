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

���� : �ϴ� �ϸ鼭 �����Ŵ� ������ ������ �ϴ� ������ ���� �������δ� �Ƿ� �����ٰ�
       �����̵��. ������ �迭�� ���� �ٲ�� �Ǹ� �̸� ����س��� �����յ��� �ٽ� �ѹ�
	   �������� �ϴ� ��찡 �����.
	   ���� �ڵ� 17 18 ��° ���� �� ����ε� ������ ������ ������ Ǯ�� �ð��ʰ��� �߻��Ѵ�.
	   �� �������δ� ������ Ǯ�̷� ���Ҵ� ���׸�Ʈ Ʈ���� �̿��ؼ� �����ϰ� �ذ��� �� ������ ����.
*/
