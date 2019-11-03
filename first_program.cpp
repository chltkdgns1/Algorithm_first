/*
#include <iostream>
using namespace std;

int QuickSort(int first_left, int first_right, int *numbers);

int main() {
	int numbers[10];
	int input_number;
	int pivot = 0;
	for (int i = 0; i < 10; i++) {
		cin >> input_number;
		numbers[i] = input_number;
	}
	cout << "1" << endl;
	QuickSort(0, 9, numbers);
	for (int i = 0; i < 10; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}

int QuickSort(int first_left,int first_right,int *numbers) {
	if (first_left >= first_right) {
		return 0;
	}
	int left = first_left;
	int right = first_right;
	int temp;
	int temp2;
	for (int i = left; i <= right; i++) {
		if (numbers[left] > numbers[i]) {
			if (i - left == 1) {
				temp = numbers[left];
				numbers[left] = numbers[i];
				numbers[i] = temp;
				left = i;
			}
			else {
				temp = numbers[left];
				temp2 = numbers[left + 1];
				numbers[left] = numbers[i];
				numbers[left + 1] = temp;
				numbers[i] = temp2;
				left = left + 1;
			}
		}
	}
	QuickSort(first_left, left-1, numbers);
	QuickSort(left + 1, first_right, numbers);
}
*/

//  3 2 0 1 5 5 8 7 4 6 9 1 2 2 2 2 2 2 21 21 21 212 1 1 12 1 2

//  퀵소트 





/*
#include <iostream>
using namespace std;

class Node_M{ // 배틀그라운드 캐릭터에 대한 노드
public:
	int hp;
	int jump;
	int walk;
	Node_M *next;
	Node_M() {
		next = NULL;
		hp = 100;
		jump = 10;
		walk = 20;
	}
};

class BattleGround {
public:
	Node_M *head;
	Node_M *cur;  // 위치
	BattleGround() {
		head = new Node_M();
		cur = head;
	}

	void NewCharecter() {
		Node_M *New = new Node_M();
		cur->next = New;
		cur = New;
	}

	void PrintChar() {
		cout << "1";
		for (Node_M *circle = head; circle->next != NULL; circle = circle->next) {
			cout << circle->hp << endl;
			cout << circle->jump << endl;
			cout << circle->walk << endl;
		}
	}
};


int main() {

	BattleGround *All = new BattleGround();
	All->NewCharecter();
	All->NewCharecter();
	All->NewCharecter();
	All->PrintChar();
}
*/

// 게임 캐릭터



/*#include <stdio.h>
#include <windows.h>

int main() {
	int number;
	printf("hello world");
	scanf_s("%d", &number);
	printf("hello world");
	sleep(1000);
}*/  //헬로월드


//#include <iostream>
//using namespace std;
//
//int main() {
//	int number1;
//	int number2;
//	cin >> number1;
//	cin >> number2;
//	if (number1 <= 0 || 10 <= number2) {
//		cout << "오류" << endl;
//		return 0;
//	}
//	cout << number1 + number2<<endl;
//} A+B

/*int QuickSort(int first_left, int first_right, int *numbers) {
	if (first_left >= first_right) {
		return 0;
	}
	int left = first_left;
	int right = first_right;
	int temp;
	int temp2;
	for (int i = left; i <= right; i++) {
		if (numbers[left] > numbers[i]) {
			if (i - left == 1) {
				temp = numbers[left];
				numbers[left] = numbers[i];
				numbers[i] = temp;
				left = i;
			}
			else {
				temp = numbers[left];
				temp2 = numbers[left + 1];
				numbers[left] = numbers[i];
				numbers[left + 1] = temp;
				numbers[i] = temp2;
				left = left + 1;
			}
		}
	}
	QuickSort(first_left, left - 1, numbers);
	QuickSort(left + 1, first_right, numbers);
}*/


#include <iostream>
using namespace std;

int QuickSort(int first_left, int first_right, int *numbers) { // 치킨 거리 순위
	if (first_left >= first_right) {
		return 0;
	}
	int left = first_left;
	int right = first_right;
	int temp;
	int temp2;
	for (int i = left; i <= right; i++) {
		if (numbers[left] > numbers[i]) {
			if (i - left == 1) {
				temp = numbers[left];
				numbers[left] = numbers[i];
				numbers[i] = temp;
				left = i;
			}
			else {
				temp = numbers[left];
				temp2 = numbers[left + 1];
				numbers[left] = numbers[i];
				numbers[left + 1] = temp;
				numbers[i] = temp2;
				left = left + 1;
			}
		}
	}
	QuickSort(first_left, left - 1, numbers);
	QuickSort(left + 1, first_right, numbers);
}

class Node_M { // 치킨집 데이터
public:
	int xpos; // x 좌표
	int ypos; // y 좌표
	int distance_sum; // 거리의 총합
	Node_M *next;
	Node_M() {
		next = NULL;
		xpos = -1;
		ypos = -1;
		distance_sum = -200;
	}
	Node_M(int xpos, int ypos) {
		this->xpos = xpos;
		this->ypos = ypos;
		distance_sum = 0;
		next = NULL;
	}
};

class Chicken {
public:
	Node_M *head;
	Node_M *cur;  // 위치
	int map[50][50] = {};  // 최대 사이즈
	int checking[13] = {}; //
	int map_size; // 사이즈
	int chicken_alive; //살아남을 치킨가게
	int count_chicken = 0; // 치킨 가게 개수세기
	int order_data = 0; // 치킨 가게들의 최단 거리의 합

	Chicken() {
		head = new Node_M();
		cur = head;
	}

	void NewChick(int xpos, int ypos) {
		Node_M *New = new Node_M(xpos, ypos);
		cur->next = New;
		cur = New;
	}

	void PrintChar() {  // 치킨집 데이터 순환 출력
		for (Node_M *circle = head->next; circle!= NULL; circle = circle->next) {
			cout << "합산값 : "<<circle->distance_sum <<" "<< endl;
		}
	}

	int InputData() {
		cin >> map_size;
		if (map_size < 2 || map_size>50) {
			return -1;  // 오류 처리
		}
		cin >> chicken_alive;
		if (chicken_alive < 1 || chicken_alive>13) {
			return -1; // 오류 처리
		}
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					count_chicken++;
					NewChick(i, j);
				}
			}
		}

		if (count_chicken < chicken_alive || count_chicken>13) {
			return -1; // 오류 처리 
		}

		Node_M *circle = head->next;
		cout << "1" << endl;
		for (int i = 0; circle != NULL; i++, circle = circle->next) { //거리 계산
			ChickHomeDistanceSum(circle, i); // 모두 입력
		}

		QuickSort(0, count_chicken - 1, checking); // 총 합을 정렬
		//최대 살리는 갯수와 총 치킨집을 감함 count_chicken-chicken_alive 해서 남은 인덱스의 값과 일치하는 연결리스트를 제거

		cout << "퀵솔트" << endl;
		for (int i = 0; i < count_chicken; i++) {
			cout << checking[i] << endl;
		}

		cout << "333333" << endl;
		cout << "count chick : " << count_chicken << endl;
		cout << "count alive : " << chicken_alive << endl;

		PrintChar();
		cout << "위에는 전체 합산 값" << endl;
		Node_M *temp = new Node_M();

		int remove_count = 0; // 합산 값이 같은 값들을 다 지우는 것을 예방 변수
		for (int i = 0; i < count_chicken - chicken_alive;i++) {
			for (Node_M *circle = head->next; circle!= NULL; circle = circle->next) {
				cout << "22222" << endl;  // 가장 큰 합산 값 노드 삭제
				if (checking[count_chicken - 1 - i] == circle->distance_sum) {
					if (remove_count == count_chicken - chicken_alive - 1) {
						break;
					}
					else {
						if (circle == head->next) {
							head->next = circle->next;
							circle->next = NULL;
							free(circle);
							circle = head;
							remove_count++; // 삭제 한번당 증가
						}
						else {
							temp->next = circle->next;
							circle->next = NULL;
							free(circle);
							circle = temp;
							remove_count++; // 삭제 한번당 증가
						}
					}
				}
				else {
					temp = circle;
				}
			}
			cout << "666666" << endl;
		}
		cout << "333333" << endl;
		PrintChar();
		FastChickDistance();
		cout << "order_data : " << order_data << endl;
		system("pause");
	}



	void ChickHomeDistanceSum(Node_M *exe, int index) {
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				if (map[i][j] == 1) {
					int data;
					exe->distance_sum = exe->distance_sum + CalDistance(exe->xpos, exe->ypos, i, j);
				}
			}
		}
		checking[index] = exe->distance_sum; // 퀵정렬
	}

	void RemoveChick(Node_M *remove) { // 노드 삭제 
		for (Node_M *circle = head; circle->next != NULL; circle = circle->next) {
			if (circle->next == remove ) {
				circle->next = remove->next;
				remove->next = NULL;
				free(remove);
			}
		}
	}

	void ResetCompareBox(int *compare_box) {
		for (int i = 0; compare_box[i] != NULL; i++) {
			compare_box[i] = 0;
		}
	}

	void FastChickDistance() {
		int compare_box[13] = {};
		int index_count = 0;
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				if (map[i][j] == 1) {
					for (Node_M *circle = head->next; circle!= NULL; circle = circle->next) {
						compare_box[index_count] = CalDistance(circle->xpos, circle->ypos, i, j);
						index_count++;
						cout << "circle index xypos : " << circle->xpos << " , " << circle->ypos << endl;
					}
					cout << "index_count : " << index_count << endl;
					QuickSort(0, index_count- 1, compare_box);
					cout << "compare_box : " << compare_box[0] << endl;
					order_data = order_data + compare_box[0];
					ResetCompareBox(compare_box);
					index_count = 0;
				}
			}
		}
	}


	int CalDistance(int xpos1, int ypos1, int xpos2, int ypos2) { // 거리 측정
		int xpos;
		int ypos;
		if (xpos1 - xpos2 < 0) {
			xpos = xpos2 - xpos1;
		}
		else {
			xpos = xpos1 - xpos2;
		}
		if (ypos1 - ypos2 < 0) {
			ypos = ypos2 - ypos1;
		}
		else {
			ypos = ypos1 - ypos2;
		}
		return xpos + ypos;
	}

};

int main() {
	Chicken *all = new Chicken();
	if (all->InputData() == -1) {
		return 0;
	}
}



/*
void caldata(int map_size) {
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {

		}
	}
}*/ //치킨집

// 알고리즘 일단 하나의 치킨집을 구한다
// 그리고 그 치킨집이 갈 수 있는 모든 집의 거리를 계산한다.
// 이렇게 나머지 치킨집 모두 계산하고
// 치킨집이 5개 이고 m 이 3 일 경우 2개만 폐업을 시킨다.
// 그리고 기억된 폐업소를 0 으로 치환한 후 집에서 가장 가까운 
// 치킨집을 선택하고 거리를 더한다.
// 그런식으로 계산 후 총합을 구한다.