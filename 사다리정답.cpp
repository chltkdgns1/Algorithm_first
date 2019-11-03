#include <cstdio>
#include <climits>
#include <Windows.h>

const int MAXROW = 30;
const int MAXCOL = 10;

bool map[MAXROW + 1][MAXCOL + 2]; //�¿� �е�
int N, M, H; //���Ǽ�, �־��� ��ٸ� ��, ���� ��
int ans = INT_MAX;
int recur;

bool simulate() {
	bool ret = false;
	int corret = 0, copy = 0;
	int j = 1, i = 1;
	for (j = 1; j <= N; ++j) { // �� �ݺ�
		copy = j;
		for (i = 1; i <= H; ++i) { //�� �ݺ�
			if (map[i][copy]) {
				copy++;
			}
			else if (map[i][copy - 1]) {
				copy--;
			}
		}
		if (copy == j) {
			corret += 1;
			//            printf("original: %d, copy:%d\n", j, copy);
		}
		else {
			break;  //�ϳ��� �ٸ��� �ǹ̾���.
		}
	}
	if (corret == N) {
		ret = true;
	}

	return ret;
}

void go(int rowPos, int cnt, int goal) {
	// rowPos���� ��ٸ� cnt�� �߰��Ͽ� i��° ���� ��ٸ� Ÿ�� i��°�� ������ Ȯ���ϴ� �Լ�

//    recur++;
//    printf("cnt: %d ��ٸ� ����: %d\n", recur, cnt);
//    for (int k = 1; k <= H ; ++k) {
//        for (int i = 1; i <= N; ++i) {
//            printf("%d ", map[k][i]);
//        }
//        printf("\n");
//    }
//    printf("\n");


	if (cnt == goal) {
		if (simulate()) {
			//            printf("here\n");
			ans = cnt;
		}
		return;
	}
	else {
		for (int i = rowPos; i <= H; ++i) { // �� �ݺ�
			for (int j = 1; j < N; ++j) { // �� �ݺ� ������ ������ ��ٸ� �߰��ǹ� ��
				if (!map[i][j] && !map[i][j - 1] && !map[i][j + 1]) {
					map[i][j] = true;
					if (ans != INT_MAX) {
						return;
					}
					go(i, cnt + 1, goal);

					map[i][j] = false;
				}
			}
		}
	}
}

int main() {

	scanf_s("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		map[a][b] = true;
	}

	for (int i = 0; i < 4; ++i) {
		go(1, 0, i);
		if (ans != INT_MAX) {
			break;
		}
	}
	if (ans == INT_MAX) {
		ans = -1;
	}
	printf("%d\n", ans);
	Sleep(10000);

	return 0;
}