#include <iostream>
#include <string>
using namespace std;
class album {
public:
	int y;
	string name;
};

album a[25];
int main() {
	int n, s, e, cnt = 0;;
	cin >> n;
	a[0].y = 1967;a[0].name = "DavidBowie";
	a[1].y = 1969; a[1].name = "SpaceOddity";
	a[2].y = 1970; a[2].name = "TheManWhoSoldTheWorld";
	a[3].y = 1971; a[3].name = "HunkyDory";
	a[4].y = 1972; a[4].name = "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars";
	a[5].y = 1973; a[5].name = "AladdinSane";
	a[6].y = 1973; a[6].name = "PinUps";
	a[7].y = 1974; a[7].name = "DiamondDogs";
	a[8].y = 1975; a[8].name = "YoungAmericans";
	a[9].y = 1976; a[9].name = "StationToStation";
	a[10].y = 1977; a[10].name = "Low";
	a[11].y = 1977; a[11].name = "Heroes";
	a[12].y = 1979; a[12].name = "Lodger";
	a[13].y = 1980; a[13].name = "ScaryMonstersAndSuperCreeps";
	a[14].y = 1983; a[14].name = "LetsDance";
	a[15].y = 1984; a[15].name = "Tonight";
	a[16].y = 1987; a[16].name = "NeverLetMeDown";
	a[17].y = 1993; a[17].name = "BlackTieWhiteNoise";
	a[18].y = 1995; a[18].name = "1.Outside";
	a[19].y = 1997; a[19].name = "Earthling";
	a[20].y = 1999; a[20].name = "Hours";
	a[21].y = 2002; a[21].name = "Heathen";
	a[22].y = 2003; a[22].name = "Reality";
	a[23].y = 2013; a[23].name = "TheNextDay";
	a[24].y = 2016; a[24].name = "BlackStar";
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		for (int k = 0; k < 25; k++) {
			for (int j = s; j <= e; j++) {
				if (a[k].y == j) cnt++;
			}
		}
		cout << cnt << endl;
		for (int k = 0; k < 25; k++) {
			for (int j = s; j <= e; j++) {
				if (a[k].y == j) {
					cout << a[k].y << " " << a[k].name << endl;
				}
			}
		}
		cnt = 0;
	}
	system("pause");
}