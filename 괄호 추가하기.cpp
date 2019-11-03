#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int d[24];
long long max1 = (1 << 31);
string s;
long long calCulate(string s) {
	stack <char> st; // 문자를 담을 공간.
	queue <char> q; // 숫자와 문자를 담을 공간
	for (int i = 0; i < s.length(); i++) { // 문자를 한개씩 읽어옴
		if (s[i] >= 48 && s[i] <= 57)  q.push(s[i]);// 숫자이면
		else { // 문자일 경우에
			if (st.empty()) {
				st.push(s[i]);
			}
			else if (s[i] == '(') st.push(s[i]); // 괄호 열기일 경우 무조건 넣어주고
			else if (s[i] == ')') { // 괄호 닫기일 경우에는
				while (st.top() != '(') {
					q.push(st.top()); // 큐에다가 모두 넣어주고 
					st.pop(); // 스택에 있는것은 하나씩 빼준다.
				}
				//마지막으로 괄호 열기를 빼준다.
				st.pop();
			}
			else { // 우선순위가 같기 때문에 한개를 뽑아서 큐에 넣고 새로운 것은 스택에 넣는다
				if (st.top() == '(') st.push(s[i]);
				else {
					q.push(st.top());
					st.pop();
					st.push(s[i]);
				}
			}
		}
	}
	while (!st.empty()) {
		q.push(st.top());
		st.pop();
	}
	stack <long long> ist;
	while (!q.empty()) {
		if (q.front() >= 48 && q.front() <= 57) ist.push(q.front() - 48);
		else {
			long long a = ist.top();
			ist.pop();
			long long b = ist.top();
			ist.pop();
			if (q.front() == '+') ist.push(a + b);
			else if (q.front() == '-') ist.push(b - a);
			else ist.push(b*a);
		}
		q.pop();
	}
	return ist.top();
}
void dfs(int index) {
	if (index >= s.length()) {
		string t;
		for (int i = 0; i < s.length(); i++) {
			if (d[i] == 1) {
				t += '('; t += s[i];
			}
			else if (d[i] == 2) {
				t += s[i]; t += ')';
			}
			else t += s[i];
		}
		long long x = calCulate(t);
		if (max1 < x) max1 = x;
		return;
	}
	if (index + 2 >= s.length()) {
		d[index] = 0;
		dfs(index + 2);
		return;
	}
	d[index] = 1;
	d[index + 2] = 2;
	dfs(index + 4);
	d[index] = 0;
	d[index + 2] = 0;
	dfs(index + 2);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;  cin >> n;
	cin >> s;
	dfs(0);
	cout << max1 << "\n";
}