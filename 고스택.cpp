#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <math.h>
#define MAX 1000000000
using namespace std;
vector <int> q; // Äõ¸®
class Stack {
private:
	int arr[1001];
	int len;
public:
	Stack() {
		len = 0;
	}
	bool empty() {
		return len == 0 ? true : false;
	}
	int size() {
		return len;
	}
	void push(int data) {
		arr[len] = data;
		len++;
	}
	void pop() {
		arr[len - 1] = 0;
		len--;
	}
	int top() {
		return arr[len - 1];
	}
};
void inputQurrey(string s) {
	if (s == "POP") q.push_back(1);
	else if (s == "INV") q.push_back(2);
	else if (s == "DUP") q.push_back(3);
	else if (s == "SWP") q.push_back(4);
	else if (s == "ADD") q.push_back(5);
	else if (s == "SUB") q.push_back(6);
	else if (s == "MUL") q.push_back(7);
	else if (s == "DIV") q.push_back(8);
	else if (s == "MOD") q.push_back(9);
	else {int a; cin >> a; q.push_back(-a);}
}
void executionQurrey(int r) {
	long long e, a, b, t, c, w;
	Stack st;
	st.push(r);
	for (int i = 0; i < q.size(); i++) {
		switch (q[i]) {
		case 1:
			if (st.empty()) {
				cout << "ERROR" << "\n";
				return;
			}
			st.pop();
			break;
		case 2:
			if (st.empty()) {
				cout << "ERROR" << "\n";
				return;
			}
			e = st.top();
			st.pop();
			st.push(-e);
			break;
		case 3:
			if (st.empty()) {
				cout << "ERROR" << "\n";
				return;
			}
			st.push(st.top());
			break;
		case 4:
			if (st.size() < 2) {
				cout << "ERROR" << "\n";
				return;
			}
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(a), st.push(b);
			break;
		case 5:
			if (st.size() < 2) {
				cout << "ERROR" << "\n";
				return;
			}
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			if (abs(a + b) > MAX) {
				cout << "ERROR" << "\n";
				return;
			}
			st.push(a + b);
			break;
		case 6:
			if (st.size() < 2) {
				cout << "ERROR" << "\n";
				return;
			}
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			if (abs(b - a) > MAX) {
				cout << "ERROR" << "\n";
				return;
			}
			st.push(b - a);
			break;
		case 7:
			if (st.size() < 2) {
				cout << "ERROR" << "\n";
				return;
			}
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			if (abs(a*b) > MAX) {
				cout << "ERROR" << "\n";
				return;
			}
			st.push(a*b);
			break;
		case 8:
			if (st.size() < 2) {
				cout << "ERROR" << "\n";
				return;
			}
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			if (a == 0) {
				cout << "ERROR" << "\n";
				return;
			}
			c = 0;
			if (b < 0)c++;
			if (a < 0)c++;
			if(c == 1) st.push(-(abs(b) / abs(a)));
			else st.push(abs(b) / abs(a));
			break;
		case 9:
			if (st.size() < 2) {
				cout << "ERROR" << "\n";
				return;
			}
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			if (a == 0) {
				cout << "ERROR" << "\n";
				return;
			}
			w= abs(b) % abs(a);
			if (b < 0) w = -w;
			st.push(w);
			break;
		default:
			st.push(-q[i]);
			break;
		}
	}
	if (st.size() != 1) cout << "ERROR" << "\n";
	else cout << st.top() << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		while (1) {
			string s;
			cin >> s;
			if (s == "QUIT") return 0;
			else if (s == "END") break;
			inputQurrey(s);
		}
		int n, a;
		cin >> n;
		while (n--) {
			cin >> a;
			executionQurrey(a);
		}
		cout << "\n";
		q.clear();
	}
}