#include "calculater.h"
#include "chicken.h"
using namespace std;

/*
수정 내용 : 일단 최소 거리의 가장 많이 나오는 경우의 수를 비교해서 삭제했음
          - 원래는 치킨 가게와 모든 도시의 거리의 총 합이 가장 큰 치킨 가게를 지우기로 했으나 최소 거리의 경우가 같을 경우를 대비해서
		    치킨 가게와 모든 도시의 거리 총 합을 또 한번 추가해주어야함. 그래야 완벽하게 최소 거리를 구할 수 있음
*/


int main() {
	Chicken *all = new Chicken();
	if (all->InputData() == -1) {
		return 0;
	}
}