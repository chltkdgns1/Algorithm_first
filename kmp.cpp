#include <iostream>
#include <string>
#include <vector>
using namespace std;

void kmp(vector <int> &pi,string a,string b,vector <int> &res) { // kmp �˰���
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

	kmp(inclde, total_string, a, res1); // ��Ŭ��忡 ���� ���ڿ� ���� �ε���
	kmp(defi, total_string, b, res1); // ������
	kmp(var, total_string, c, res1); // ��


	pair<int, int> index[1001];
	for (int i = 0; i < total_string.length(); i++) {
		if (total_string[i] == '#') index[i] = { -1,0 };
	}
	for (int i = 0; i < res1.size(); i++) index[res1[i]] = { 1,res1[i]};
	for (int i = 0; i < res2.size(); i++) index[res1[i]] = { 2,res2[i]};


	//kmp(v, a, b, res);
	// #include #define
}

// �ε��� �迭�� ó������ �����鼭 -1 ������ 1 �Ǵ� 2�� ���ؼ� �ι�° �����忡
// ���ؼ� �ε����� ã�ƿͼ� �޺κп� ���� ���ڿ��� �����ִ��� üũ