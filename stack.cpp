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

int isEmpty(StackNode* root) {
	return !root;
}

void push(StackNode** root, int data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " - this number pushed in stack \n";
}
int main() {
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    return 0;
}
