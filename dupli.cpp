#include <iostream>
using namespace std;
class node
{	public:
	node* next;
	int data;
};
node* head;  
void addbeg(int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}
void addend(int data)
{
	if(head == NULL)
	{	
		cout<<"The list is empty!!\n";
	}
	else
	{
		node* newnode = new node();
		newnode->data = data;
		node* ptr = head;
		while(ptr->next != NULL)
			ptr=ptr->next;
		newnode->next=NULL;
		ptr->next = newnode;
	}
}
void delparti(int value)
{	node* ptr = head;
	node* preptr;
	while(ptr->data != value)
	{
		preptr = ptr;			
		ptr=ptr->next;
	}
	preptr->next = ptr->next;
	delete ptr;
}
void display()
{
	if(head == NULL)
	{
		cout<<"The list is empty!!\n";
	}
	else
	{
		cout<<"The list contains:";
		node* ptr = head;
		while(ptr != NULL)
		{	
			cout<<ptr->data<<"\t";			
			ptr=ptr->next;
		}
		cout<<endl;
	}		
}
void removedup()
{
	node* temp = head;
	node* ptr;
	node* preptr;
	node* temp1;
	int flag;
	while(temp != NULL)
	{	
		ptr = temp->next;
		preptr = temp;
		flag = 0;
		while(ptr != NULL && flag ==0)
		{	
			if(ptr->data == temp->data)
			{
				if(ptr->next == NULL)
				{
					flag = 1;
					preptr->next = NULL;
					delete ptr;
					
				}	
				else
				{	temp1 = ptr;
					preptr->next = ptr->next;
					ptr = ptr->next->next;
					delete temp1;
				/*temp1 = temp;
				temp = temp->next;
				head = temp;					
				delete temp1;*/
				}
			}
			else
			{
				preptr = ptr;
				ptr = ptr->next;
			}	
		}
		/*if(flag == 0)
		{	
			
			temp = temp->next;
		}*/
		temp = temp->next;
	}
}

int main()
{
	head = NULL;
	int n,data;
	cout<<"\t\t**Enter 0 to exit**\n1.Display the List\n2.Add at the Beginning\n3.Add at the end\n4.Delete a particular data\n5.Remove Duplicates\n";
	while(n!=0)
	{	
		cout<<"Enter your choice:";
		cin>>n;
		switch(n)
		{
			case 1:display();break;
			case 2:cout<<"Enter the no:";cin>>data;addbeg(data);break;
			case 3:cout<<"Enter the no:";cin>>data;addend(data);break;
			case 4:cout<<"Enter the no to be deleted:";cin>>data;delparti(data);break;
			case 5:cout<<"The duplicates have been removed.\n";removedup();break;
		}	
	}
}
