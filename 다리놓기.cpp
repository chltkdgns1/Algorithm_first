#include <iostream>
using namespace std;

int d[100][100] = { 0 };
int Union(int n, int m);


int main() {
	int test_case;
	int n, m;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> n >> m;
	cout<<	Union(n, m)<<endl;
	}
	system("pause");
}

int Union(int n,int m) { // m == n , n == r
	// 알고리즘 nCr 을 분해하여 각각을 더하는 재귀함 수를 만든다.
	if (n == m ||  n==0) {
		return 1;
	}
	else if (n == 1) {
		return m;
	}
	if (d[m][n]) {
		return d[m][n];
	}
	return d[m][n] = Union(n, m - 1) + Union(n - 1, m - 1);
    // mCn 의 값은 d[m] 에 대입
}


// nCr = n-1Cr + n-1Cr-1;
// n-1Cr = n-2Cr + n-2Cr-1;


/*

#include <iostream>
using namespace std;

int Factorial(int number) {
	int cnt = 1;
	for (int i = number; i >= 1; i--) {
		cnt *= i;
		cout << "cnt : " << cnt<<endl;
	}
	return cnt;
}

// m 개의 포인트 중애 n 개의 다리 연결
int Union(int n, int m) {
	return Factorial(m) /(Factorial(n) * Factorial(m - n));
}

int main() {
	int test_case;
	int n, m;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> n >> m;
		cout<<Union(n, m)<<endl;
	}
	system("pause");
}


*/