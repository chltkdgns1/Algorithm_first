#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <time.h>
using namespace std;

void Color(unsigned short text = 15, unsigned short back = 0) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back<<4));
}

int first = 0;
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char Dir[4] = { 's','w','d','a' };

class xypos {
public:
	int xpos, ypos;
	int dir ,first ,len;
	int range_up ;
	xypos() { xpos = 0, ypos = 0; first = 0; }
};

class monster {
public:
	xypos x[200];
	int x_index;
	int cnt;
	monster() { x_index = 0; cnt = 0; }
	void createMonster(int xp, int yp) {
		if (cnt >= 100) return;
		cnt++;
		srand(time(NULL));
		int xpos = rand() % 56 + 2;
		int ypos = rand() % 27 + 2;
		x[x_index].xpos = xpos, x[x_index].ypos = ypos;
		x_index++;
	}
	void move() {
		srand(time(NULL));
		for (int i = 0; i < x_index; i++) {
			int index = rand() % 4;
			gotoxy(x[i].xpos, x[i].ypos);
			cout << " ";
			x[i].xpos += dx[index];
			x[i].ypos += dy[index];
			if (x[i].xpos < 2) x[i].xpos = 2;
			if (x[i].ypos < 2) x[i].ypos = 2;
			if (x[i].xpos > 57) x[i].xpos = 56;
			if (x[i].ypos > 28) x[i].ypos = 28;
			gotoxy(x[i].xpos, x[i].ypos);
			cout << "@";
		}
	}

	void Die(int index) {
		gotoxy(x[index].xpos, x[index].ypos);
		cout << " ";
		xypos del;
		for (int i = index; i < x_index; i++) x[i] = x[i + 1];
		x[x_index - 1] = del;
		x_index--;
	}
};

class print {
public:
	int score;
	print() { score = 0; }
	void printScore() {
		gotoxy(70,0);
		cout <<"score - "<<score << "                  ";
	}

	void printMap() {
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■                                                        ■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
};

class Shoot {
public:
	xypos xy[100];
	int index;

	void deleteShoot(int i) {
		xypos del;
		for (int idex = i; idex < index - 1; idex++) {
			xy[idex] = xy[idex + 1];
		}
		if (index != 100) xy[index] = del;
		index--;
	}
};

class item {
public:
	xypos tem[100];
	int index;
	item() { index = 0; }
	void makeItem(int xpos,int ypos) {
		srand(time(NULL));
		int x = rand() % 30 + 10;
		int y = rand() % 20 + 5;
		if (x == xpos && ypos == x) return;
		tem[index].xpos = x;
		tem[index].ypos = y;
		tem[index].range_up = rand() % 10;
		index++;
	}

	void printItem() {
		for (int i = 0; i < index; i++) {
			gotoxy(tem[i].xpos, tem[i].ypos);
			switch (tem[i].range_up) {
			case 0:
				cout << "※";
				break;
			case 1:
				cout << "☆";
				break;
			case 2:
				cout << "★";
				break;
			case 3:
				cout << "○";
				break;
			case 4:
				cout << "●";
				break;
			case 5:
				cout << "◎";
				break;
			case 6:
				cout << "＠";
				break;
			case 7:
				cout << "◇";
				break;
			case 8:
				cout << "■";
				break;
			case 9:
				cout << "♠";
				break;
			}
		}
	}

	void remove(int idex) {
		xypos null;
		for (int i = idex; i < index; i++) {
			tem[i] = tem[i + 1];
		}
		tem[index - 1] = null;
		index--;
	}

	void printGetMotion(int xpos,int ypos) {
		gotoxy(xpos, ypos - 3);
		cout << "아이템 획득!";
		while (1) {
			if (_kbhit() == 1) {
				gotoxy(xpos, ypos - 3);
				cout << "            ";
				break;
			}
		}
	}
};

class airport : xypos{
public: // 이부분 class 사용으로 수정해야됨
	int hp, mp;
	int nomal_cool_time;
	int speed;
	int range;
	airport() {
		xpos = 25, ypos = 25;
		hp = 1, mp = 100;
		nomal_cool_time = 20;
		speed = 1;
		range = 10;
    }

	int getXpos() {
		return xpos;
	}
	int getYpos() {
		return ypos;
	}
	void printAirplane() {
		gotoxy(this->xpos, this->ypos);
		cout << "#";
	}
	void action(char c,char rember,monster *q,print *p,item *t) {
		if (c == 'w' || c == 's' || c == 'a' || c == 'd') {
			int index = 0;
			for (int i = 0; i < 4; i++) {
				if (Dir[i] == c) index = i;
			}
			gotoxy(xpos, ypos);
			cout << " ";
			xpos += dx[index];
			ypos += dy[index];
			for (int i = 0; i < t->index; i++) {
				if ((t->tem[i].xpos == xpos && t->tem[i].ypos == ypos) || (t->tem[i].xpos + 1== xpos && t->tem[i].ypos == ypos)) {
					gotoxy(xpos, ypos);
					cout << " ";
					t->remove(i);
					range += t->tem[i].range_up;
					t->printGetMotion(xpos, ypos);
				}
			}
			if (xpos < 2) xpos = 2;
			if (xpos > 57) xpos = 57;
			if (ypos < 2) ypos = 2;
			if (ypos > 28) ypos = 28;
			gotoxy(xpos, ypos);
			cout << "#";
		}
		else if (c == 't') {
			gotoxy(70, 3);
			cout << "정지합니다. 정지를 푸려면 t 를 눌러주세요" << endl;
			while (1) {
				if (_kbhit() == 1) {
					char c = _getch();
					if (c == 't') {
						gotoxy(70, 3);
						cout << "                                         ";
						break;
					}
				}
			}
		}
	}

	void Shooting(char c, char rember, monster *q, print *p, Shoot *s) {
		int index,br = 0;
		if (c == 'e') {
			for (int i = 0; i < 4; i++) {
				if (Dir[i] == rember) index = i;
			}
			s->xy[s->index].dir = index;
			s->xy[s->index].xpos = xpos + dx[index];
			s->xy[s->index].ypos = ypos + dy[index];
			if ((s->xy[s->index].xpos < 3 && rember == 'a') || (s->xy[s->index].xpos > 56 && rember =='d') ||  (s->xy[s->index].ypos < 2 && rember =='w' )|| (s->xy[s->index].ypos > 27 && rember=='s')) {
				s->xy[s->index].dir = 0;
				s->xy[s->index].xpos = 0;
				s->xy[s->index].ypos = 0;
				return;
			}
			s->xy[s->index++].len = range;
		}
		if (s->index != 0) {
			for (int i = 0; i < s->index; i++) {
				gotoxy(s->xy[i].xpos, s->xy[i].ypos);
				cout << " ";
				if ((s->xy[i].xpos < 3 && s->xy[i].dir == 3) || (s->xy[i].xpos > 56 && s->xy[i].dir == 2) || (s->xy[i].ypos < 2 && s->xy[i].dir == 1) || (s->xy[i].ypos > 27 && s->xy[i].dir == 0)) {
					s->deleteShoot(i);
					continue;
				}
				//if (s->xy[i].xpos < 3 || s->xy[i].xpos > 56 || s->xy[i].ypos < 2 || s->xy[i].ypos > 27) {
				//	s->deleteShoot(i);
				//	continue;
				//}
				s->xy[i].xpos += dx[s->xy[i].dir];
				s->xy[i].ypos += dy[s->xy[i].dir];
				for (int j = 0; j < q->x_index; j++) {
					if (s->xy[i].xpos == q->x[j].xpos && s->xy[i].ypos == q->x[j].ypos) {
						q->Die(j);
						p->score += 100;
						p->printScore();
						gotoxy(s->xy[i].xpos, s->xy[i].ypos);
						cout << " ";
						s->deleteShoot(i);
						br = 1;
						break;
					}
				}
				if (br == 1) { br = 0; continue; }
				gotoxy(s->xy[i].xpos, s->xy[i].ypos);
				cout << "*";
				s->xy[i].len--;
				if (s->xy[i].len == 0) { // 총알 삭제
					gotoxy(s->xy[i].xpos, s->xy[i].ypos);
					cout << " ";
					s->deleteShoot(i);
				}
			}
		}
	}
	void Die(monster *q) {
		for (int i = 0; i < q->x_index; i++) {
			if (q->x[i].xpos == xpos && q->x[i].ypos == ypos) {
				system("cls");
				gotoxy(20, 10);
				cout << "Die" << endl;
				Sleep(2000);
				exit(0);
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Shoot *s = new Shoot();
	print *p = new print();
	airport *a = new airport();
	monster *m = new monster();
	item *t = new item();
	gotoxy(0, 0);
	Color(1, 0);
	p->printMap();
	Color(2, 0);
	a->printAirplane();
	p->printScore();
	char rember = 'r';
	char c = 0;
	int t_get_time;
	int c_get_time;
	int get_time = c_get_time = t_get_time = GetTickCount();
	int b_time, c_time,t_time;
	while (1) {
		b_time = c_time =t_time = GetTickCount();
		if (_kbhit() == 1) {
			c = _getch();
			if (c == 'w' || c == 'a' || c == 's' || c == 'd')
				rember = c;
			a->action(c, rember, m, p,t);
		}
		a->Die(m);
		if (c_time - c_get_time > 50) {
			a->Shooting(c, rember, m, p, s);
			c_get_time = c_time;
			c = 0;
		}
		if (t_time - t_get_time > 2000) {
			t->makeItem(a->getXpos(), a->getYpos());
			t->printItem();
			t_get_time = t_time;
		}
		if (b_time - get_time > 1000) {
			m->createMonster(a->getXpos(), a->getYpos());
			m->move();
			get_time = b_time;
		}
	}
	system("pause");
}