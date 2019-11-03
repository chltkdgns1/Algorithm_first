#include <iostream>
#include <string>
using namespace std;
bool check[25000];
int main() {
	string word,search;
	int key_cnt = 0;
	getline(cin,word);
	getline(cin, search);
	for (int i = 0; i < word.length(); i++) {
		if (i <= word.length() - search.length() ) {
			int cnt = 0 ,index = i;
			for (int j = 0; j < search.length(); j++) {
				if (word[index] == search[j] && check[index] == false) cnt++;
				else break;
				index++;
			}
			if (cnt == search.length()) {
				for (int j = i; j < i + search.length(); j++) {
					check[j] = true;
				}
				key_cnt++;
			}
		}
		else break;
	}
	cout << key_cnt << endl;
}