#include<iostream>
using namespace std;

//linked list implementation

struct node
{
        int key;
	int data;
	node *next;	
        node *link;
};

class list
{
		private:
		node *head, *tail;
		public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		void createNode(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void printList()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\n";
				temp=temp->next;
			}
		}
                void insertStart(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void insertPosition(int pos, int value)
		{
			node *pre=new node;
			node *cur=new node;
			node *temp=new node;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->data=value;
			pre->next=temp;
			temp->next=cur;
		}
                void deleteFirst()
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		void deleteLast()
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			while(current->next!=NULL)
			{
				previous=current;
				current=current->next;
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void deletePosition(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
};

// Queue implementation

class Queue
{
        public:
  	        node *front;
  	        node *rear;

        Queue() {
                front = NULL;
                rear = NULL;
        }

        bool isEmpty() {
    	        if(front==NULL && rear==NULL) {
    		return true;
	        }
		else {
			return false;
		}
	}

	 bool checkIfNodeExist(node *n) {
	 	node *temp = front;
	 	bool exist=false;
	 	while(temp!=NULL) {
	 		if(temp->key==n->key) {
                                exist=true;
                                break;
                        }
      	                temp=temp->next;
		}
		return exist;
	 }

	void enqueue(node *n){
                if (isEmpty()) {
                        front = n;
                        rear = n;
                        cout<<"Node  ENQUEUED successfully"<<endl;
                }
                else if(checkIfNodeExist(n)) {
                        cout<<"Node already exist with this Key value."
                        <<"Enter different Key value"<<endl;
                }
                else {
                        rear->next=n;
                        rear=n;
                        cout<<"Node  ENQUEUED successfully"<<endl;
                }

        }

	node* dequeue() {
                node *temp=NULL;
                if (isEmpty()) {
                        cout << "Queue is Empty" << endl;
                        return NULL;
                }
                else {
                        if(front==rear){
                                temp=front;
                                front = NULL;
                                rear = NULL;
                                return temp;
                        }
                        else {
                                temp=front;
                                front = front->next;
                                return temp;
                        }

                }
        }

	int count() {
                int count=0;
                node *temp=front;
                while(temp!=NULL) {
                        count++;
                        temp=temp->next;
    	        }
        return count;
        }

	void display() {
                if(isEmpty()) {
                        cout << "Queue is Empty" << endl;
                }
                else {
                        cout << "All values in the Queue are :" << endl;
                        node *temp=front;
                        while(temp!=NULL) {
                                cout<<"("<<temp->key<<","<<temp->data<<")"<<" -> ";
                                temp=temp->next;
                        }
                        cout<<endl;
                }

        }


};

//Stack implementation 

node *top = NULL;

bool isempty(){
        if(top == NULL)
        return true; else
        return false;
}

void push (int value) {
        node *ptr = new node();
        ptr->data = value;
        ptr->link = top;
        top = ptr;
}

void pop ( ) {
        if (isempty())
                cout<<"Stack is Empty";
                else {
                        node *ptr = top;
                        top = top -> link;
                        delete(ptr);
                }
}

void showTop() {
        if (isempty())
                cout<<"Stack is Empty";
        else
                cout<<"Element at top is : "<< top->data;
}

void displayStack() {
        if ( isempty() )
                cout<<"Stack is Empty";
        else {
                node *temp=top;
                while(temp!=NULL) {   
                        cout<<temp->data<<" ";
                        temp=temp->link;
                }
                cout<<"\n";
        }
}
int main() {

        return 0;
}

