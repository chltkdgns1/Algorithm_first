#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	Node *next;
	int hp;
};

Node head;
Node *cur;
void a(int n) {
	Node *a = new Node();
	a->hp = 80;
	cur->next = a;
	cur = cur->next;
}

void find(int n,int hp) {
	int a = 0;
	for (Node *first = head.next; first->next != NULL; first = first->next) {
		a++;
		if (a == n) {
			first->hp = hp;
		}
	}
}
int main() {
	cur = &head;
	a(10);
}