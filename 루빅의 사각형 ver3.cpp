#include <cstdio>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

// 상태 노드는 string
// 이전 상태 노드의 정보를 모두 가지고 있는 struct
struct PrevNode {
	string ps; // "": initial state(start 또는 end)
	bool rc; // 0: 행, 1: 열 연산
	int n, k; // 연산에 사용된 값
	PrevNode() : ps("") {} // 기본 생성자: 이곳이 initial state
	PrevNode(string p, bool rc1, int n1, int k1) : ps(p), rc(rc1), n(n1), k(k1) {}
};
// 상태 노드: bool값이 false면 start에서, true면 end에서 출발한 탐색
typedef pair<string, bool> QNode;
// 각 상태마다 이전 상태, 그리고 이 상태로 온 연산을 저장한 map
typedef map<string, PrevNode> NodeMap;

// 결과값들로 이루어진 struct
struct ResultVals {
	bool rc;
	int n, k;
	ResultVals() {}
	ResultVals(bool rc1, int n1, int k1) : rc(rc1), n(n1), k(k1) {}
};

// 세 개의 정수값과 현재 상태를 받아, 연산을 적용한 상태를 리턴
string getNext(string curr, bool rc, int n, int k) {
	// 열 로테이션
	if (rc) {
		for (int i = 0; i < k; i++)
			for (int j = 2; j >= 0; j--)
				swap(curr[j * 4 + n], curr[(j + 1) * 4 + n]);
	}
	// 행 로테이션
	else {
		for (int i = 0; i < k; i++)
			for (int j = 2; j >= 0; j--)
				swap(curr[n * 4 + j], curr[n * 4 + j + 1]);
	}
	return curr;
}



int main() {
	// start, end state에서 출발한 각 영역이 구분되어야 함
	NodeMap sourceStart, sourceEnd;
	// start, end state 제작(end state가 [그림 1]임)
	string start = "", end = "";
	for (int i = 1; i <= 16; i++) {
		int n;
		scanf("%d", &n);
		start.push_back(n);
		end.push_back(i);
	}

	// initial state들이 정보를 큐와 map에 넣음
	sourceStart[start] = PrevNode();
	sourceEnd[end] = PrevNode();
	queue<QNode> Q;
	Q.push(QNode(start, false));
	Q.push(QNode(end, true));

	// 양방향 BFS 시작
	while (1) {
		int qSize = Q.size();
		for (int q = 0; q < qSize; q++) {
			string curr = Q.front().first;
			bool s = Q.front().second;
			Q.pop();

			// source는 이 노드가 시작한 영역, opposite는 반대쪽 영역 map
			NodeMap &source = (s ? sourceEnd : sourceStart);
			NodeMap &opposite = (s ? sourceStart : sourceEnd);

			// 반대쪽 영역에도 이 값이 존재한다면, 두 영역이 만난 것: 결과 출력
			if (opposite.find(curr) != opposite.end()) {
				// 덱을 사용하여 결과를 양쪽에 이어 붙임
				deque<ResultVals> result;
				// 현재 상태로부터 start state로 따라가면서 연산 정보 삽입
				for (string t = curr; t != start;) {
					PrevNode &pt = sourceStart[t];
					result.push_front(ResultVals(pt.rc, pt.n, pt.k));
					t = pt.ps;
				}
				// 현재 상태로부터 end state로 따라가면서 연산 정보 삽입
				for (string t = curr; t != end;) {
					PrevNode &pt = sourceEnd[t];
					result.push_back(ResultVals(pt.rc, pt.n, 4 - pt.k));
					t = pt.ps;
				}

				// 결과 출력
				printf("%d\n", result.size());
				for (ResultVals &r : result)
					printf("%d %d %d\n", r.rc + 1, r.n + 1, r.k);
				return 0;
			}

			// 아직 탐색하지 않은 다음 상태 노드들을 큐에 넣음
			for (int i = 0; i < 4; i++)
				for (int j = 1; j < 4; j++)
					for (int k = 0; k < 2; k++) {
						string next = getNext(curr, k, i, j);
						if (source.find(next) != source.end()) continue;
						Q.push(QNode(next, s));
						source[next] = PrevNode(curr, k, i, j);
					}
		}
	}
}

