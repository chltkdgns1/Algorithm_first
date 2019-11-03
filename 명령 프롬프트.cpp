#include <iostream>
#include <string.h>
using namespace std;
char name[50];
char collect[50];
int main() {
	int n;
	cin >> n;
	cin >> collect;
	for (int i = 0; i < n - 1; i++) {
		cin >> name;
		for (int j = 0; j < strlen(collect); j++) {
			if (collect[j] != name[j]) collect[j] = '?';
		}
	}
	cout << collect << endl;
}