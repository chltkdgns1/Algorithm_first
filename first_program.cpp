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

//  ����Ʈ 





/*
#include <iostream>
using namespace std;

class Node_M{ // ��Ʋ�׶��� ĳ���Ϳ� ���� ���
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
	Node_M *cur;  // ��ġ
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

// ���� ĳ����



/*#include <stdio.h>
#include <windows.h>

int main() {
	int number;
	printf("hello world");
	scanf_s("%d", &number);
	printf("hello world");
	sleep(1000);
}*/  //��ο���


//#include <iostream>
//using namespace std;
//
//int main() {
//	int number1;
//	int number2;
//	cin >> number1;
//	cin >> number2;
//	if (number1 <= 0 || 10 <= number2) {
//		cout << "����" << endl;
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

int QuickSort(int first_left, int first_right, int *numbers) { // ġŲ �Ÿ� ����
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

class Node_M { // ġŲ�� ������
public:
	int xpos; // x ��ǥ
	int ypos; // y ��ǥ
	int distance_sum; // �Ÿ��� ����
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
	Node_M *cur;  // ��ġ
	int map[50][50] = {};  // �ִ� ������
	int checking[13] = {}; //
	int map_size; // ������
	int chicken_alive; //��Ƴ��� ġŲ����
	int count_chicken = 0; // ġŲ ���� ��������
	int order_data = 0; // ġŲ ���Ե��� �ִ� �Ÿ��� ��

	Chicken() {
		head = new Node_M();
		cur = head;
	}

	void NewChick(int xpos, int ypos) {
		Node_M *New = new Node_M(xpos, ypos);
		cur->next = New;
		cur = New;
	}

	void PrintChar() {  // ġŲ�� ������ ��ȯ ���
		for (Node_M *circle = head->next; circle!= NULL; circle = circle->next) {
			cout << "�ջ갪 : "<<circle->distance_sum <<" "<< endl;
		}
	}

	int InputData() {
		cin >> map_size;
		if (map_size < 2 || map_size>50) {
			return -1;  // ���� ó��
		}
		cin >> chicken_alive;
		if (chicken_alive < 1 || chicken_alive>13) {
			return -1; // ���� ó��
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
			return -1; // ���� ó�� 
		}

		Node_M *circle = head->next;
		cout << "1" << endl;
		for (int i = 0; circle != NULL; i++, circle = circle->next) { //�Ÿ� ���
			ChickHomeDistanceSum(circle, i); // ��� �Է�
		}

		QuickSort(0, count_chicken - 1, checking); // �� ���� ����
		//�ִ� �츮�� ������ �� ġŲ���� ���� count_chicken-chicken_alive �ؼ� ���� �ε����� ���� ��ġ�ϴ� ���Ḯ��Ʈ�� ����

		cout << "����Ʈ" << endl;
		for (int i = 0; i < count_chicken; i++) {
			cout << checking[i] << endl;
		}

		cout << "333333" << endl;
		cout << "count chick : " << count_chicken << endl;
		cout << "count alive : " << chicken_alive << endl;

		PrintChar();
		cout << "������ ��ü �ջ� ��" << endl;
		Node_M *temp = new Node_M();

		int remove_count = 0; // �ջ� ���� ���� ������ �� ����� ���� ���� ����
		for (int i = 0; i < count_chicken - chicken_alive;i++) {
			for (Node_M *circle = head->next; circle!= NULL; circle = circle->next) {
				cout << "22222" << endl;  // ���� ū �ջ� �� ��� ����
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
							remove_count++; // ���� �ѹ��� ����
						}
						else {
							temp->next = circle->next;
							circle->next = NULL;
							free(circle);
							circle = temp;
							remove_count++; // ���� �ѹ��� ����
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
		checking[index] = exe->distance_sum; // ������
	}

	void RemoveChick(Node_M *remove) { // ��� ���� 
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


	int CalDistance(int xpos1, int ypos1, int xpos2, int ypos2) { // �Ÿ� ����
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
}*/ //ġŲ��

// �˰��� �ϴ� �ϳ��� ġŲ���� ���Ѵ�
// �׸��� �� ġŲ���� �� �� �ִ� ��� ���� �Ÿ��� ����Ѵ�.
// �̷��� ������ ġŲ�� ��� ����ϰ�
// ġŲ���� 5�� �̰� m �� 3 �� ��� 2���� ����� ��Ų��.
// �׸��� ���� ����Ҹ� 0 ���� ġȯ�� �� ������ ���� ����� 
// ġŲ���� �����ϰ� �Ÿ��� ���Ѵ�.
// �׷������� ��� �� ������ ���Ѵ�.