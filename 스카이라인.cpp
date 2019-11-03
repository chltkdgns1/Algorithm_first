#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class Data {
public:
	int x1, y , x2;
};
Data d[100001];
list <pair< int, pair<int,int>>> v;
int a[1000000000];
bool cmp(const Data&a, const Data&b) {
	return a.x1 < b.x1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	list <pair<int,pair<int, int>>>::iterator iter;
	list <pair<int,pair<int, int>>>::iterator t;
	for (int i = 0; i < n; i++) cin >>d[i].x1 >> d[i].y >> d[i].x2;
	sort(d, d + n, cmp);
	for (int i = 0; i < n; i++) {
		if (v.empty()) {
			v.push_back({ d[i].y,{ d[i].x1,d[i].y } });
			v.push_back({ d[i].y,{ d[i].x2,d[i].y } });
			iter = v.begin();
		}
		else {
			 // d[i].x1; 이 값이 새로운 cur_a 값
			if (v.back().second.first < d[i].x1) {
				v.back().first = 0;
				v.push_back({d[i].y, { d[i].x1,d[i].y } });
				iter = --v.end();
				v.push_back({d[i].y, { d[i].x2,d[i].y } });
			}
			else { // 이 경우 현재의 cur_a 와 비교
				for (t = iter; t != v.end(); t++) {
					if ((*t).second.first > d[i].x1 && (*t).second.second < d[i].y) {
						iter = v.insert(t, { d[i].y,{ d[i].x1,d[i].y } });
						break;
					}
					if ((*t).second.first == d[i].x1 && (*t).second.second <= d[i].y) {
						(*t).second.first = d[i].x1, (*t).second.second = d[i].y;
						iter = t;
						break;
					}
				}
				t = iter;
				t++;
				for (; t != v.end(); t++) {  // current_b 의 위치 확인
					if ((*t).second.first > d[i].x2) {
						t--;
						if ((*t).second.second <= d[i].y) {
							t++;
							t = v.insert(t, {(*t).second.second,{ d[i].x2,d[i].y } });
							break;
						}
						t++;
					}
					else if ((*t).second.first < d[i].x2) {
						if ((*t).second.second <= d[i].y) { // 작거나 같다면 제거해준다.
							t = v.erase(t);		
							t--;
						}
						else {
							if ((*t).first > d[i].y) (*t).first = d[i].y;
						}
					}
					else {
						if ((*t).second.second < d[i].y) {
							(*t).second.second = d[i].y;
							break;
						}
					}
					if (t == --v.end()) {
						if ((*t).second.first < d[i].x2) {
							v.push_back({ d[i].y,{ d[i].x2,d[i].y } });
							break;
						}
					}
				}
			}
		}
	}
	for (t = v.begin(); t != v.end(); t++) {
		if(t == v.begin()) cout << (*t).second.first << " " << (*t).first;
		else if(t == --v.end()) cout <<" "<< (*t).second.first << " " <<0;
		else cout <<" "<< (*t).second.first << " " << (*t).first ;
	}
}