#include <iostream>
using namespace std;
int map[6][6];
char place[2];
int start_x, start_y;
bool checkPlace(int number,int xpos,int ypos) {
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			if (map[y][x] == number - 1) {
				if (x - 2 == xpos && y - 1 == ypos ) return true;		
				else if (x - 1 == xpos && y - 2 == ypos ) return true;
				else if (x - 1 == xpos && y + 2 == ypos ) return true;
				else if (x - 2 == xpos && y + 1 == ypos ) return true;
				else if (x + 1 == xpos && y - 2 == ypos ) return true;
				else if (x + 2 == xpos && y - 1 == ypos ) return true;
				else if (x + 2 == xpos && y + 1 == ypos ) return true;
				else if (x + 1 == xpos && y + 2 == ypos ) return true;
				return false;
			}
		}
	}
}

bool checkFirstFinal(int xpos,int ypos) {
	if (start_x - 2 == xpos && start_y - 1 == ypos) return true;
	else if (start_x - 1 == xpos && start_y - 2 == ypos) return true;
	else if (start_x - 1 == xpos && start_y + 2 == ypos) return true;
	else if (start_x - 2 == xpos && start_y + 1 == ypos) return true;
	else if (start_x + 1 == xpos && start_y - 2 == ypos) return true;
	else if (start_x + 2 == xpos && start_y - 1 == ypos) return true;
	else if (start_x + 2 == xpos && start_y + 1 == ypos) return true;
	else if (start_x + 1 == xpos && start_y + 2 == ypos) return true; 
	else return false;
}
int main() {
	int number = 1;
	bool key = true;
	for (int i = 0; i < 36; i++) {
		cin >> place;
		int xpos, ypos;
		xpos = place[0] - 65; 
		ypos = 54 - place[1];
		if (key == true) {
			if (i == 0) {
				start_x = xpos;
				start_y = ypos;
				map[ypos][xpos] = number; 
				number++;
			}
			else {
				if (checkPlace(number, xpos, ypos) == true) {
					map[ypos][xpos] = number;
					if (number == 36) {
						if (checkFirstFinal(xpos, ypos) == false) key = false;
					}
					number++;
				}
				else {
					key = false;
				}
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == 0) key = false;
		}
	}
	if (key == true) cout << "Valid" << endl;
	else cout << "Invalid" << endl;
}