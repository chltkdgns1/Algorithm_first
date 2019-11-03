#include <iostream>
#include <queue>
using namespace std;
int a, b, c;
int brr[3], water_arr[201];
bool check[201][201][201];
class boul {
public:
	int bo[3];
};
void bfs(){
	boul e;
	for (int i = 0; i < 3; i++) e.bo[i] = brr[i];
	queue <boul> q;
	q.push(e);
	check[0][0][c] = true;
	water_arr[c] = 1;
	while (!q.empty()) {
		int temp_boul[3];
		for (int i = 0; i < 3; i++) {
			temp_boul[i] = q.front().bo[i];
			cout << temp_boul[i] << " ";
		}
		cout << endl;
		if (temp_boul[0] == 0) water_arr[temp_boul[2]] = 1;
		q.pop();
		int b1[3];

		for (int i = 0; i < 3; i++) b1[i] = temp_boul[i];
		if ((b1[1] + b1[0]) <= b) {
			b1[1] += b1[0];
			b1[0] = 0; 
		}
		else {
			b1[0] -= (b - b1[1]);
			b1[1] = b;
		}
		if (check[b1[0]][b1[1]][b1[2]] == false) {
			for (int i = 0; i < 3; i++) {
				e.bo[i] = b1[i];
			}
			q.push(e);
			check[b1[0]][b1[1]][b1[2]] = true;
		}
		for (int i = 0; i < 3; i++) b1[i] = temp_boul[i];
		if ((b1[2] + b1[0]) <= c) {
			b1[2] += b1[0];
			b1[0] = 0; 
		}
		else {
			b1[0] -= (c - b1[2]);
			b1[2] = c;
		}
		if (check[b1[0]][b1[1]][b1[2]] == false) {
			for (int i = 0; i < 3; i++) {
				e.bo[i] = b1[i];
			}
			q.push(e);
			check[b1[0]][b1[1]][b1[2]] = true;
		}
		for (int i = 0; i < 3; i++) b1[i] = temp_boul[i];
		if ((b1[1] + b1[0]) <= a) {
			b1[0] += b1[1];
			b1[1] = 0;
		}
		else {
			b1[1] -= (a - b1[0]);
			b1[0] = a;
		}
		if (check[b1[0]][b1[1]][b1[2]] == false) {
			for (int i = 0; i < 3; i++) {
				e.bo[i] = b1[i];
			}
			q.push(e);
			check[b1[0]][b1[1]][b1[2]] = true;
		}
		for (int i = 0; i < 3; i++) b1[i] = temp_boul[i];
		if ((b1[1] + b1[2]) <= c) {
			b1[2] += b1[1];
			b1[1] = 0; 
		}
		else {
			b1[1] -= (c - b1[2]);
			b1[2] = c;
		}
		if (check[b1[0]][b1[1]][b1[2]] == false) {
			for (int i = 0; i < 3; i++) {
				e.bo[i] = b1[i];
			}
			q.push(e);
			check[b1[0]][b1[1]][b1[2]] = true;
		}
		for (int i = 0; i < 3; i++) b1[i] = temp_boul[i];
		if ((b1[0] + b1[2]) <= a) {
			b1[0] += b1[2];
			b1[2] = 0;
		}
		else {
			b1[2] -= (a - b1[0]);
			b1[0] = a;
		}
		if (check[b1[0]][b1[1]][b1[2]] == false) {
			for (int i = 0; i < 3; i++) {
				e.bo[i] = b1[i];
			}
			q.push(e);
			check[b1[0]][b1[1]][b1[2]] = true;
		}
		for (int i = 0; i < 3; i++) b1[i] = temp_boul[i];
		if ((b1[2] + b1[1]) <= b) {
			b1[1] += b1[2];
			b1[2] = 0; 
		}
		else {
			b1[2] -= (b - b1[1]);
			b1[1] = b;
		}
		if (check[b1[0]][b1[1]][b1[2]] == false) {
			for (int i = 0; i < 3; i++) {
				e.bo[i] = b1[i];
			}
			q.push(e);
			check[b1[0]][b1[1]][b1[2]] = true;
		}
	}
}
int main() {
	cin >> a >> b >> c;
	brr[2] = c;
	bfs();
	for (int i = 1; i <= c; i++) {
		if (water_arr[i] == 1) cout << i << " ";
	}
	cout << endl;
	system("pause");
}