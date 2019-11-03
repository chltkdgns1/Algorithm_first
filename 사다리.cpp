#include <iostream>
#include "Ladder.h"
using namespace std;

int main() {
	int l_line;
	int w_line;
	int h_line;
	cin >> l_line;
	if (l_line < 2 || l_line>10) return 0;	
	cin >> w_line;
	cin >> h_line;
	if (h_line < 1 || h_line>30) return 0;
	if (w_line<0 || w_line>(l_line - 1)*h_line)return 0;
	Ladder *ladder = new Ladder(l_line,w_line,h_line);
	ladder->InputData();
	return 0;
}


