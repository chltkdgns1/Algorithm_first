#include <iostream>
#include <string>
#include <vector>
using namespace std;

void kmp(vector <int> &pi,string a,string b,vector <int> &res) { // kmp 알고리즘
	int j = 0;
	for (int i = 0; i < a.length(); i++) {
		while (j > 0 && a[i] != b[j])       
			j = pi[j - 1];     
		if (a[i] == b[j]) {           
			if (j == b.length() - 1) {   
				res.push_back(i - b.length() + 1);
				j = pi[j];   
			}
			else j++;   
		}
	}
}

void makePi(vector <int> &pi,string s) {
	int j = 0;
	for (int i = 1; i < s.length(); i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
	}
}

int main() {
	vector <int> inclde(30), defi(30), var(30);
	vector <int> res1, res2, res3;
	string a, b, c;
	string def[100];
	string total_string, s;
	a = "include", b = "define ", c = "var ";
	makePi(inclde, b);
	while (getline(cin, s)) {
		total_string += s + "\n";
	}

	kmp(inclde, total_string, a, res1); // 인클루드에 대한 문자열 시작 인덱스
	kmp(defi, total_string, b, res1); // 디파인
	kmp(var, total_string, c, res1); // 바


	pair<int, int> index[1001];
	for (int i = 0; i < total_string.length(); i++) {
		if (total_string[i] == '#') index[i] = { -1,0 };
	}
	for (int i = 0; i < res1.size(); i++) index[res1[i]] = { 1,res1[i]};
	for (int i = 0; i < res2.size(); i++) index[res1[i]] = { 2,res2[i]};


	//kmp(v, a, b, res);
	// #include #define
}

// 인덱스 배열을 처음부터 읽으면서 -1 다음에 1 또는 2에 대해서 두번째 세컨드에
// 대해서 인덱스를 찾아와서 뒷부분에 무슨 문자열이 적혀있는지 체크