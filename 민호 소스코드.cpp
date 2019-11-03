#include <iostream>
#include <vector>
using namespace std;

class node {
public:
   int data;
   node* next;
   int check;
   node(int da) {
      data = da;
      next = NULL;
      check = 0;

   }
   node() {
      data = 0;
      next = NULL;
      check = 0;
   }
};
class stack {
private:
   node* head;
   node* tail;
public:
   stack() {
      head = NULL;
      tail = NULL;
   }
   ~stack() {
      while (!isEmpty()) {
         node* tmp = head;
         head = head->next;
         if (head == NULL)return;
         delete tmp;
      }
   }
   void push(int num) {
      if (isEmpty()) {
         node* p = new node;
         p->data = num;
         tail = p;
         head = p;
         tail->next = NULL;
      }
      else {
         node* tmp = head;
         node* p = new node;
         while (tmp->next != NULL)
            tmp = tmp->next;
         p->data = num;
         tmp->next = p;
         tail = p;
         tail->next = NULL;
      }
   }
   int pop() {
      int num;
      if (isEmpty())return NULL;
      else if (head == tail) {
         num = head->data;
         head = NULL;
         tail = NULL;
         delete head;
         return num;
      }
      else {
         node* tmp;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         tail = tmp;
         tmp = tmp->next;
         num = tmp->data;
         tail->next = NULL;
         delete tmp;
         return num;
      }
   }
   bool isEmpty() {
      return head == NULL;
   }
   void print() {
      node* tmp = new node;
      tmp = head;
      for (tmp = head; tmp != NULL; tmp = tmp->next) {
         cout << tmp->data << " ";
      }
   }

};
class graph {
   friend class stack;
   node* head[10];
   int n;
public :
   graph(int num) {
      n = num;
      for (int i = 1; i <= n; i++) {
         head[i] = new node(i);
         head[i]->next = NULL;
      }
   }
   void addEdge(int num1, int num2) {
      node* tmp = head[num1];
      node* p = new node(num2);
      while (tmp->next != NULL)
         tmp = tmp->next;
      tmp->next = p;
      p->next = NULL;

      node* temp = head[num2];
      node* k = new node(num1);
      while (temp->next != NULL)
         temp = temp->next;
      temp->next = k;
      k->next = NULL;
   }
   void print() {
      for (int i = 1; i <= n; i++) {
         node* temp = head[i];
         temp = temp->next;
         cout << i << " : ";
         while (temp) {
            cout << temp->data<<' ';
            temp = temp->next;
         }
         cout << endl;
      }
   }
   void dfs() {
      stack s;
      node* temp = head[1];
      temp->check = 1;
      s.push(temp->data);
      while (!s.isEmpty()) {
         int num = s.pop();
         cout << num << " ";
         node* tmp = head[num];
         tmp = tmp->next;
         while (1) {
            if (head[tmp->data]->check == 0) {
               
               s.push(tmp->data);
               head[tmp->data]->check = 1;
               if (tmp->next == NULL)break;
               tmp = tmp->next;
            }
            else {
               if (tmp->next == NULL)break;
               tmp = tmp->next;
            }

         }
      }

   }
};

int main() {
   graph g(9);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(2, 4);
   g.addEdge(3, 4);
   g.addEdge(3, 5);
   g.addEdge(4, 5);
   g.addEdge(4, 6);
   g.addEdge(6, 7);
   g.addEdge(6, 8);
   g.addEdge(7, 8);
   g.addEdge(8, 9);
   g.dfs();
}