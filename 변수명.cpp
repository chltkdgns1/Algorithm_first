#include <iostream>
using namespace std;
bool ConFirmArraySnakeCase(char *array, int index);
bool ConFirmArrayCamelPascal(char *array, int index);
void SnakeCase(char *array);
void CamelCase(char *array);
void PascalCase(char *array);
int strlen(char *array);
int length;
int main() {
	int excel_number;
	cin >> excel_number;
	char array[101];
	cin >> array;
	length = strlen(array);
	if (length > 100) {
		return 0;
	}
	switch (excel_number) {
	case 1: // ī�� ������ũ�� �Ľ�Į ���
		if (ConFirmArrayCamelPascal(array, length) == false) {
			return 0;
		}
		cout << array << endl;
		SnakeCase(array);
		cout << array << endl;
		PascalCase(array);
		cout << array << endl;
		// ���� ���� ���ĺ��� �ҹ��ڷθ� �̷���� �վ����
		break;
	case 2: // ������ũ
		if (ConFirmArraySnakeCase(array, length) == false) {
			return 0;
		}
		CamelCase(array);
		cout << array << endl;
		SnakeCase(array);
		cout << array << endl;
		PascalCase(array);
		cout << array << endl;
		// �ҹ��ڿ� ����ٷθ� �̷�������ϸ� ù���ڿ� ������ ���ڴ� ����ٰ� �ƴϰ� ����ٴ� �����ؼ� �ΰ� �̻� ��� �Ұ�
		break;
	case 3: // �Ľ�Į
		if (ConFirmArrayCamelPascal(array, length) == false) {
			return 0;
		}
		CamelCase(array);
		cout << array << endl;
		SnakeCase(array);
		cout << array << endl;
		PascalCase(array);
		cout << array << endl;
        // ���̽� 1�� ����
		break;
	}
	system("pause");
}

int strlen(char *array) {
	int cnt = 0;
	while (*array != NULL) {
		array++;
		cnt++;
	}
	return cnt;
}

bool ConFirmArraySnakeCase(char *array, int index) {
	if (array[0] == '_' || array[index - 1] == '_') {
		return false;
	}
	for (int i = 0; i < index; i++) {
		if (array[i] >= 97 && array[i] <= 122) {}
		else if (array[i] == '_') {
			if (array[i + 1] == '_') {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

bool ConFirmArrayCamelPascal(char *array,int index) {
	for (int i = 0; i < index; i++) {
		if (array[i] >= 65 && array[i] <= 90) {}
		else if (array[i] >= 97 && array[i] <= 122) {}
		else {
			return false;
		}
	}
	return true;
}

void PascalCase(char *array) {
	int camel_cnt = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] >= 65 && array[i] <= 90) {
			camel_cnt++;
		}
	}
	if (camel_cnt != 0) {
		array[0] = array[0] - 32;
		return;
	}
	else {
		array[0] = array[0] - 32;
		for (int i = 0; i < length; i++) {
			if (array[i] == '_') {
				for (int j = i; j < length; j++) {
					array[j] = array[j + 1];
				}
				array[length - 1] = NULL;
				array[i] = array[i] - 32;
				length--;
			}
		}
	}
}

void CamelCase(char *array) { // ī�� ǥ�ù����� ��ȯ ù��° ���ڸ� ������ �� �ܾ��� ù���ڸ� �빮�ڷ� ��ȯ
	int pascal_cnt = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] >= 65 && array[i] <= 90) {
			pascal_cnt++;
		}
	}
	if (pascal_cnt != 0) {
		array[0] = array[0] + 32;
		return;
	}
	else {
		for (int i = 0; i < length; i++) {
			if (array[i] == '_') {
				for (int j = i; j < length; j++) {
					array[j] = array[j + 1];
				}
				array[length - 1] = NULL;
				array[i] = array[i] - 32;
				length--;
			}
		}
	}
}

void SnakeCase(char *array) {
	for (int i = 0; i < length; i++) {
		if (array[i] >= 65 && array[i] <= 90 && i != 0) {
			for (int j = length - 1; j >= i; j--) {
				array[j + 1] = array[j];
			}
			length++;
			array[i] = '_';
			array[i + 1] = array[i + 1] + 32;
			array[length+1] = NULL;
		}
		else if (i == 0 && array[i] >= 65 && array[i] <= 90) {
			array[0] = array[0] + 32;
			return;
		}
	}
}
