#include <iostream>
using namespace std;

void Triangle(int xpos, int ypos);
void Check(int xpos, int ypos);
char array_[8000][8000] = {' '};
bool del_array[8000][8000];
int n;

int main() {
	cin >> n;
	int xpos = n, ypos=0;
	Triangle(xpos, ypos);

	for (int i = 0; i < xpos; i++) {
		for (int j = 0; j < 2 * xpos - 1; j++) {
			if (array_[i][j - 1] == '*'  &&array_[i][j] == '*' && array_[i][j + 2] == '*') {
				if (array_[i + 1][j + 1] == '*' && del_array[i-2][j-2]==true && del_array[i - 2][j + 4] == true) {
					del_array[i + 1][j + 1] = true;
				}
				else if (array_[i + 1][j + 1] == '*' && del_array[i - 2][j - 2] != true && del_array[i - 2][j + 4] != true) {
					del_array[i + 1][j + 1] = true;
				}
			}
		}
	}
	
	for (int i = 0; i < xpos; i++) {
		for (int j = 0; j < 2 * xpos - 1; j++) {
			if (del_array[i][j] == true) {
				Check(j + 1, i);
			}
		}
	}
	
	for (int i = 0; i < xpos; i++) {
		for (int j = 0; j < 2 * xpos - 1; j++) {
			printf("%c",array_[i][j]);
		}
		printf("\n");
	}
	system("pause");
}

void Check(int xpos,int ypos) {
	array_[ypos][xpos - 1] = ' ';
	array_[ypos + 1][xpos - 2] = ' ';
	array_[ypos + 1][xpos] = ' ';
	for (int i = 0; i < 5; i++) {
		array_[ypos + 2][xpos - 3 + i] = ' ';
	}
}

void Triangle(int xpos, int ypos) {
	if (array_[ypos][xpos - 1] == '*') {
		return;
	}
	array_[ypos][xpos - 1] = '*';
	array_[ypos + 1][xpos - 2] = '*';
	array_[ypos + 1][xpos] = '*';
	for (int i = 0; i < 5; i++) {
		array_[ypos + 2][xpos - 3 + i] = '*';
	}
	if (xpos == 0 || ypos == n - 3) return;
	Triangle(xpos - 3, ypos + 3);
	Triangle(xpos + 3, ypos + 3);
}

