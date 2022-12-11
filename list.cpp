#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;	
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
};
int main()
{
	list obj;
	obj.createNode(25);
	obj.createNode(50);
	obj.createNode(90);
	obj.createNode(40);
	obj.printList();
	return 0;
}
