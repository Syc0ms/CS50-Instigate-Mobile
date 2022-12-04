#include <iostream>
#include <list>

int initLinkedList ();
using namespace std;

class Node {
public:
        int data;
        Node* next;
};

int main (){
        initLinkedList();

}

int initLinkedList () {
        Node* head;
        Node* one = NULL;
        Node* two = NULL;
        Node* three = NULL;

        one = new Node();
        two = new Node();
        three = new Node();
        
        int first, second, third;
        cout << "Type first item of linked list" << endl ;
        cin >> first;
        one->data = first;
        cout << "Type second item of linked list" << endl;
        cin >> second;
        two->data = second;
        cout << "Type third item of linked list" << endl;
        cin >> third;
        three->data = third;
        
        one->next = two;
        two->next = three;
        three->next = NULL;

        head = one;
        while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
        }
}

