#include <iostream>
#include <string>
using namespace std;

char map[30][200];
char arr[10][5][3] = {
	{
		{' ','-',' '},
		{'|',' ','|'},
		{' ',' ',' '},
		{'|',' ','|'},
		{' ','-',' '}
	},
	{
		{' ',' ',' '},
		{' ',' ','|'},
		{' ',' ',' '},
		{' ',' ','|'},
		{' ',' ',' '}
	},
	{
		{' ','-',' '},
		{' ',' ','|'},
		{' ','-',' '},
		{'|',' ',' '},
		{' ','-',' '}
	},
	{
		{' ','-',' '},
		{' ',' ','|'},
		{' ','-',' '},
		{' ',' ','|'},
		{' ','-',' '}
	},
	{
		{' ',' ',' '},
		{'|',' ','|'},
		{' ','-',' '},
		{' ',' ','|'},
		{' ',' ',' '}
	},
	{
		{' ','-',' '},
		{'|',' ',' '},
		{' ','-',' '},
		{' ',' ','|'},
		{' ','-',' '}
	},
	{
		{' ','-',' '},
		{'|',' ',' '},
		{' ','-',' '},
		{'|',' ','|'},
		{' ','-',' '}
	},
	{
		{' ','-',' '},
		{' ',' ','|'},
		{' ',' ',' '},
		{' ',' ','|'},
		{' ',' ',' '}
	},
	{
		{' ','-',' '},
		{'|',' ','|'},
		{' ','-',' '},
		{'|',' ','|'},
		{' ','-',' '}
	},
	{
		{' ','-',' '},
		{'|',' ','|'},
		{' ','-',' '},
		{' ',' ','|'},
		{' ','-',' '}
	}
};
int x;// 시작 좌표
void input(int num, int cnt, int size) { // 만들어낼 숫자 그리고 몇번째인지 크기
	int y = 0, e = size - 1;;
	bool check;
	for (int i = 0; i < 5; i++) {
		check = 0;
		for (int k = 0; k < 3; k++) {
			if (arr[num][i][k] == '-') {
				for (int z = 0; z < size; z++) map[i + y][k + x + z] = '-';
			}
			else if (arr[num][i][k] == '|') {
				if (!k) {
					for (int z = 0; z < size; z++) map[i + z + y][k + x] = '|';
					if (!check) y += size - 1, check = 1;
				}
				else {
					if (check) y -= size - 1, check = 0;
					for (int z = 0; z < size; z++) map[i + z + y][k + x + e] = '|';
					if (!check) y += size - 1, check = 1;
				}
			}
		}
	}
	x += size + 3;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string n;
	int s; cin >> s >> n;
	for (int i = 0; i < n.length(); i++) {
		input(n[i] - 48, 0, s);
	}
	for (int i = 0; i < 2 * s + 3; i++) {
		for (int k = 0; k < n.length() * (s + 2) + n.length() - 1; k++) {
			cout << map[i][k];
		}
		cout << "\n";
	}
	system("pause");
}