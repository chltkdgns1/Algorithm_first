#include <iostream>
#include <string>
#include <set>
using namespace std;

set <int> s;
int map[50][26];
int wd[26];
int bin[26];
int n1, k;
int Go(int bin[],int n) { // n Àº ÀÍÈù °¹¼ö bin Àº ÀÍÈù ¹®ÀÚ¿­
	if (n > k) return -1;
	if (n == k) { 
		int cnt = 0;
		for (int i = 0; i < n1; i++) {
			int br = 0;
			for (set <int>::iterator iter = s.begin(); iter != s.end(); iter++) {
				if (map[i][*iter] != bin[*iter] && map[i][*iter] != 0) {
					br = 1;
					break;
				}
			}
			if (br) continue;
			cnt++;
		}
		return cnt;
	}
	int max = 0;
	for (set <int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		if (wd[*iter] != 0 && bin[*iter] == 0) {
			bin[*iter] = 1;
			int data = Go(bin, n + 1);
			if (max < data) max = data;
			bin[*iter] = 0;
		}
	}
	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n1 >> k;
	string word;
	if (k < 5) {
		cout << 0; return 0;
	}
	for (int i = 0; i < n1; i++) {
		cin >> word;
		for (int j = 4; j < word.length() - 4; j++) {
			map[i][word[j] - 97] = 1;
			wd[word[j] - 97] = 1;
			s.insert(word[j] - 97);
		}
	}
	bin[0] = bin[2] = bin[8] = bin[13] = bin[19] = 1;
	wd[0] = wd[2] = wd[8] = wd[13] = wd[19] = 1;	
	int max = 0;
	for(set <int>::iterator iter = s.begin();iter != s.end();iter++){
		if (wd[*iter] != 0 && bin[*iter] == 0) {
			bin[*iter] = 1;
			int data = Go(bin,6);
			if (max < data) max = data;
			bin[*iter] = 0;
		}
	}
	cout << max << endl;
}