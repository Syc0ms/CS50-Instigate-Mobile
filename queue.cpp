#include <iostream>
using namespace std;

struct node {
        int data;
        struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
void Insert(int val) {
        if (rear == NULL) {
                rear = new node;
                rear->next = NULL;
                rear->data = val;
                front = rear;
        } else {
                temp=new node;
                rear->next = temp;
                temp->data = val;
                temp->next = NULL;
                rear = temp;
        }
}


int initQueue () {
        int first, second, third, forth, fivth; 
        cout<<"Enter the first num: "<<endl;
        cin >> first;
        cout<<"Enter the second num:"<<endl;
        cin >> second;
        cout<<"Enter the third num:"<<endl;
        cin >> third;
        cout<<"Enter the forth num:"<<endl;
        cin >> forth;
        cout<<"Enter the fivth num:"<<endl;
        cin >> fivth;
        Insert(first);
        Insert(second);
        Insert(third);
        Insert(forth);
        Insert(fivth);
               
        return 0;
}
int main() {
        initQueue();
}
