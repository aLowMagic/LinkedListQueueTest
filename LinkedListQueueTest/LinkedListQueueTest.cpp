//队列的链式存储-单链表
#include<iostream>
using namespace std;
typedef struct rdQNode {
	int data;
	rdQNode *next;
}rdQNode;
typedef struct {
	rdQNode *Head, *Rear;
}LinkNode;
void initQueue(LinkNode &Q) {
	Q.Head = Q.Rear = new rdQNode;
	Q.Head->next = NULL;
	Q.Head->data = NULL;
}
bool isEmpty(LinkNode Q) {
	if (Q.Head == Q.Rear) {
		return true;
	}
	return false;
}
void enterQueue(LinkNode &Q, int x) {
	rdQNode *mid = new rdQNode;
	if (isEmpty(Q)) {
		Q.Head->next = mid;
		mid->data = x;
		mid->next = NULL;
	}
	else {
		mid->data = x;
		mid->next = NULL;
		Q.Rear->next = mid;
	}
	Q.Rear = mid;
}
bool deQueue(LinkNode &Q, int &x) {
	if (isEmpty(Q)) {
		return false;
	}
	if (Q.Head->next == Q.Rear) {
		Q.Head = Q.Rear;
		x = Q.Head->data;
		return true;
	}
	x = Q.Head->next->data;
	rdQNode *mid = Q.Head->next;
	Q.Head->next = mid->next;
	free(mid);
	return true;
}
int main() {
	LinkNode Q;
	initQueue(Q);
	enterQueue(Q, 1);
	enterQueue(Q, 2);
	enterQueue(Q, 3);
	enterQueue(Q, 7);
	int out;
	while (!isEmpty(Q)) {
		deQueue(Q, out);
		cout << out << '\t';
	}
	cout << endl;
	system("pause");
	cout << (isEmpty(Q) ? "true" : "false") << endl;
	system("pause");
}

