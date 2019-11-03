#include <iostream>
using namespace std;

class p {
public:
	int x, y;
};
p xy[3];
int ccw(p a, p b, p c) {
	return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}
int main() {
	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> xy[i].x >> xy[i].y;
		}
		cout << ccw(xy[0], xy[1], xy[2]) << "\n";
	}
}