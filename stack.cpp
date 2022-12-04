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

int isEmpty(StackNode* main) {
	return !main;
}

void push(StackNode** main, int data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = *main;
    *main = stackNode;
    cout << data << " - this number pushed in stack \n";
}

int pop(StackNode** main) {
        if(isEmpty(*main))
                return INT_MIN;
        StackNode* temp = *main;
        *main = (*main)->next;
        int popped = temp->data;
        free(temp);

        return popped;
        
}

int peek(StackNode* main) {
    if (isEmpty(main))
        return INT_MIN;
    return main->data;
}

int initStack(){ 
    StackNode* main = NULL;
  
    push(&main, 10);
    push(&main, 20);
    push(&main, 30);
    cout << pop(&main) << " - this number is popped from stack\n";
    cout << "Top element is " << peek(main) << endl;
    return 0;
}
int main() {
        initStack();
}
