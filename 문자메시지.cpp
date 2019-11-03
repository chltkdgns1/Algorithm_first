#include <iostream>
#include <string>
using namespace std;
int main() {
	int p, w, len, prev = -1, sum = 0;
	string message;
	cin >> p >> w;
	cin.ignore();
	getline(cin, message);
	len = message.length();
	for (int i = 0; i < len; i++) {
		if (message[i] == ' ') {
			sum += p;
			prev = 1;
		}
		else if (message[i] >= 'A' && message[i] <= 'C') {
			sum += (prev == 2) ? w + (message[i] - 'A' + 1)*p :( message[i] - 'A' + 1)*p;
			prev = 2;
		}
		else if (message[i] >= 'D' && message[i] <= 'F') {
			sum += (prev == 3) ? w + (message[i] - 'D' + 1)*p : (message[i] - 'D' + 1)*p;
			prev = 3;
		}
		else if (message[i] >= 'G' && message[i] <= 'I') {
			sum += (prev == 4) ? w + (message[i] - 'G' + 1)*p : (message[i] - 'G' + 1)*p;
			prev = 4;
		}
		else if (message[i] >= 'J' && message[i] <= 'L') {
			sum += (prev == 5) ? w + (message[i] - 'J' + 1)*p : (message[i] - 'J' + 1)*p;
			prev = 5;
		}
		else if (message[i] >= 'M' && message[i] <= 'O') {
			sum += (prev == 6) ? w + (message[i] - 'M' + 1)*p : (message[i] - 'M' + 1)*p;
			prev = 6;
		}
		else if (message[i] >= 'P' && message[i] <= 'S') {
			sum += (prev == 7) ? w + (message[i] - 'P' + 1)*p : (message[i] - 'P' + 1)*p;
			prev = 7;
		}
		else if (message[i] >= 'T' && message[i] <= 'V') {
			sum += (prev == 8) ? w + (message[i] - 'T' + 1)*p : (message[i] - 'T' + 1)*p;
			prev = 8;
		}
		else{
			sum += (prev == 9) ? w + (message[i] - 'W' + 1)*p : (message[i] - 'W' + 1)*p;
			prev = 9;
		}
	}
	cout << sum << endl;
}