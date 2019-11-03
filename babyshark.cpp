#include <iostream>
#include <Windows.h>
using namespace std;

int map[20][20] = {};
int map_size;
bool map_[20][20] = { false };

int ComapareNumber(int number1, int number2);

class Node_S{
private:
	int xpos;
	int ypos;
	int time;
public:
	Node_S() {
		xpos = -1;
		ypos = -1;
		time = INT_MAX;
	}

	void InitXypos(int xpos, int ypos) {
		this->xpos = xpos;
		this->ypos = ypos;
	}


	void InputTime(int time) {
		if (this->time > time) {
			this->time = time;
		}
	}

	int OutTime() {
		return time;
	}

	void PrintXyps() {
		cout << "[ " << xpos << " , " << ypos << " ] " << endl;
	}

	bool CompareXypos(int xpos, int ypos) {
		if (this->xpos == xpos && this->ypos == ypos) {
			return true;
		}
		return false;
	}
};

class BabyShark {
private:
	int *distance;
	int distance_index;
	int xpos;
	int ypos;
	int level;
	int time;
	int eatting;
	Node_S *can_go;
	int can_go_index;
public:
	BabyShark() {
		distance_index = 0;
		eatting = 0;
		level = 2;
		time = 0;
		xpos = -1;
		ypos = -1;
	}

	void PrintCanGo() {
		for (int i = 0; i < can_go_index; i++) {
			can_go[i].PrintXyps();
		}
	}

	void PrintCangoTime() {
		for (int i = 0; i < can_go_index; i++) {
			can_go[i].PrintXyps();
			cout << "time : " << can_go[i].OutTime() << endl;
		}
	}
	int OutTime() {
		return time;
	}

	void InitCanGo(int number) {
		can_go = new Node_S[number*number];
		can_go_index = 0;
	}

	void LevelUp() {
		if (eatting == level) {
			level++;
		}
	}


	void InputXypos(int xpos, int ypos) {
		this->xpos = xpos;
		this->ypos = ypos;
	}

	int OutXpos() {
		return xpos;
	}

	int OutYpos() {
		return ypos;
	}

	void SharkCanGo(int xpos,int ypos) {
		if (xpos >= 0 && xpos <= map_size - 1 && ypos >= 0 && ypos <= map_size - 1) {
			int return_cnt = 0;
			for (int i = 1; i < 5; i++) {
				if (GoFish(xpos, ypos, i) == true) {
					switch (i) {
					case 1:
						can_go[can_go_index].InitXypos(xpos - 1, ypos);
						can_go_index++;
						break;
					case 2:
						can_go[can_go_index].InitXypos(xpos, ypos-1);
						
						can_go_index++;
						break;
					case 3:
						can_go[can_go_index].InitXypos(xpos+1, ypos);
						
						can_go_index++;	
						break;
					case 4:
						can_go[can_go_index].InitXypos(xpos, ypos+1);
						
						can_go_index++;
						break;
					}
				}
				else {
					return_cnt++;
				}
			}
			if (return_cnt == 4) {
				return;
			}
			if (map[ypos][xpos + 1] <= level) {
				SharkCanGo(xpos + 1, ypos);
			}
			if (map[ypos][xpos - 1] <= level) {
				SharkCanGo(xpos - 1, ypos);
			}
			if (map[ypos + 1][xpos] <= level) {
				SharkCanGo(xpos, ypos + 1);
			}
			if (map[ypos-1][xpos] <= level) {
				SharkCanGo(xpos, ypos - 1);
			}
		}
		else {
			return;
		}
	}

	void Eatting() {
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				if (map[i][j] < level) {
					for (int k = 0; k < can_go_index; k++) {
						if (can_go[k].CompareXypos(j, i) == true) {
							// 거리 계산값을 
						}
					}
				}
			}
		}
	}

	void MiniDistance(int xpos,int ypos) {

	}

	bool GoFish(int xpos, int ypos, int index) {
		switch (index) {
		case 1:
			if (xpos != 0) {
				if (level >= map[ypos][xpos - 1] && map_[ypos][xpos - 1] == false) {
					//cout << "ccccc" << endl;
					xpos--;
					map_[ypos][xpos] = true;
					return true;
				}
			}
			break;
		case 2:
			if (ypos != 0) {
				if (level >= map[ypos - 1][xpos] && map_[ypos - 1][xpos] == false) {
					ypos--;
					map_[ypos][xpos] = true;
					return true;
				}
			}
			break;
		case 3:
			if (xpos != map_size - 1) {
				if (xpos != map_size - 1) {
					if (level >= map[ypos][xpos + 1] && map_[ypos][xpos + 1] == false) {
						xpos++;
						map_[ypos][xpos] = true;
						return true;
					}
				}
			}
			break;
		case 4:
			if (ypos != map_size - 1) {
				if (ypos != map_size - 1) {
					if (level >= map[ypos + 1][xpos] && map_[ypos + 1][xpos] == false) {
						ypos++;
						map_[ypos][xpos] = true;
						return true;
					}
				}
			}
			break;
		}
		return false;
	}

	void InitMap_() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				map_[i][j] = false;
			}
		}
	}

};

int main() {
	int time[4] = { 0 };
	BabyShark *shark = new BabyShark();
	cin >> map_size;
	if (map_size >= 2 && map_size <= 20) {
		shark->InitCanGo(map_size);
		int shark_count = 0;
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				cin >> map[i][j];
				if (map[i][j] == 9) {
					shark_count++;
					if (shark_count == 2) {
						return 0;
					}
					shark->InputXypos(j, i);
				}
			}
		}
		map_[shark->OutYpos()][shark->OutXpos()] = true;
		shark->SharkCanGo(shark->OutXpos(), shark->OutYpos());
		//shark->PrintCanGo();
		shark->PrintCangoTime();
		system("pause");
	}
}

/*

	int CheckDistance(int xpos, int ypos) {
		int x_distance;
		int y_distance;
		if (this->xpos > xpos) {
			x_distance=this->xpos - xpos;
		}
		else {
			x_distance = xpos - this->xpos;
		}
		if (this->ypos > ypos) {
			y_distance = this->ypos - ypos;
		}
		else {
			y_distance = ypos - this->ypos;
		}
		return x_distance + y_distance;
	}

*/

/*
bool Move(int xpos, int ypos) {
	//cout << "bbbbb" << endl;
	if (shark_xpos != 0) {
		if (map[shark_ypos][shark_xpos] >= map[shark_ypos][shark_xpos - 1] && map_[shark_ypos][shark_xpos - 1] == false) {
			//cout << "ccccc" << endl;
			shark_xpos--;
			map_[shark_ypos][shark_xpos] = true;
			return true;
		}
	}
	if (shark_ypos != 0) {
		if (map[shark_ypos][shark_xpos] >= map[shark_ypos - 1][shark_xpos] && map_[shark_ypos - 1][shark_xpos] == false) {
			shark_ypos--;
			map_[shark_ypos][shark_xpos] = true;
			return true;
		}
	}
	if (shark_xpos != map_size - 1) {
		if (shark_xpos != map_size - 1) {
			if (map[shark_ypos][shark_xpos] >= map[shark_ypos][shark_xpos + 1] && map_[shark_ypos][shark_xpos + 1] == false) {
				shark_xpos++;
				map_[shark_ypos][shark_xpos] = true;
				return true;
			}
		}
	}
	if (shark_ypos != map_size - 1) {
		if (shark_ypos != map_size - 1) {
			if (shark_xpos != 0 && map[shark_ypos][shark_xpos] >= map[shark_ypos + 1][shark_xpos] && map_[shark_ypos + 1][shark_xpos] == false) {
				shark_ypos++;
				map_[shark_ypos][shark_xpos] = true;
				return true;
			}
		}
	}
	return false;
}
*/


/*
if (shark_xpos == ago_xpos && shark_ypos == ago_ypos) {

				}
				if (ypos < shark_ypos && xpos < shark_xpos) {
					if (map[shark_ypos][shark_xpos] <= map[shark_ypos][shark_xpos - 1]) {
						shark_xpos--;
					}
					else if (map[shark_ypos][shark_xpos] <= map[shark_ypos - 1][shark_xpos]) {
						shark_ypos--;
					}
					else if (map[shark_ypos][shark_xpos] <= map[shark_ypos][shark_xpos + 1]) {
						shark_xpos++;
					}
					else if (map[shark_ypos][shark_xpos] <= map[shark_ypos + 1][shark_xpos]) {
						shark_ypos++;
					}
					else {
						return -1;
					}
					time++;
					ago_xpos = shark_xpos;
					ago_ypos = shark_ypos;
				}
				if (xpos == shark_xpos && ypos == shark_ypos) {
					if (low_time > time) {
						low_time = time;
					}
					shark_xpos = this->xpos;
					shark_ypos = this->ypos;
					ago_xpos = 0;
					ago_ypos = 0;
				}
				else if (time == fast_distance && xpos == shark_xpos && ypos == shark_ypos) {
					return fast_distance;
				}

*/


/*
	bool GoFish(int xpos, int ypos) {
		cout << "xpos : " << xpos << endl;
		cout << "ypos : " << ypos << endl;
		shark_xpos = this->xpos;
		shark_ypos = this->ypos;
		int big_data_x;
		int big_data_y;
		big_data_x = ComapareNumber(xpos, shark_xpos);
		big_data_y = ComapareNumber(ypos, shark_ypos);
		for (int i = 0; i < (big_data_x + 1)*(big_data_y + 1); i++) {
			InitMap_();
			map_[this->ypos][this->xpos] = true;
			shark_xpos = this->xpos;
			shark_ypos = this->ypos;
			for (int j = 0; j < (big_data_x + 1)*(big_data_y + 1) - 1 ; j++) {
				//cout << "forforfor" << endl;
				if (Move(xpos, ypos) == false) {
					cout << "---------------------" << endl;
					break;
				}
				else {
					cout << "shark_xpos : " << shark_xpos << " ";
					cout << "shark_ypos : " << shark_ypos << endl;
				}
				if (shark_xpos == xpos && shark_ypos == ypos) {
					cout << "qqqqq" << endl;
					return true;
				}
			}

		}
		return false;
	}

*/