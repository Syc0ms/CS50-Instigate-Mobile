#include <iostream>
#include <climits>
using namespace std;

class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data) {
	StackNode* stack = new StackNode();
	stack->data = data;
	stack->next = NULL;
	return stack;
}

int isEmpty(StackNode* root)
{
	return !root;
}
