#include <iostream>
using namespace std;
class node
{
	node* next;
	int marks;
	char subject[10];
}
void addbeg(int m ,char s[10] ,node* head)
{
	node* newnode = new node();
	newnode->marks = m;
	newnode->subject = s;
	newnode->next = head;
	head = newnode;
}
void addend(int data, node* head)
{
	if (head == NULL);
		cout<<"The list is empty!!\n";
	else
	{
		node* newnode = new node();
		newnode->marks = m;
		newnode->subject = s[];
		while(ptr->next != NULL)
			ptr=ptr->next;
		newnode->next=NULL;
		ptr->next = newnode;
	}
}
void delparti(char s[10],node* head)
{	node* ptr = head;
	node* preptr;
	while(ptr->subject != s)
	{
		preptr = ptr;			
		ptr=ptr->next;
	}
	preptr->next = ptr->next;
	delete ptr;
}
void display(node* head)
{
	node* ptr = head;
	node* ptr1 = head; 
	while(ptr != NULL)
	{	cout<<ptr->subject<<"\t";			
		ptr=ptr->next;
	}
	while(ptr != NULL)
	{	cout<<ptr1->marks<<"\t";		
		ptr1=ptr1->next;
	}
}

int main()
{
	int n,j;
	cout<<"Enter the no of students:";
	cin>>n;
	node* arr[n];
	for(int i = 0;i<n;i++)
	{
		arr[i] = NULL;
	}
	for(int i = 0;i<n;i++)
	{
		cout<<"Student "<<i+1<<"\n";
		cout<<"Enter no of Subjects:";
		cin>>j;
		




	
	
