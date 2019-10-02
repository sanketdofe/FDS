#include <iostream>
using namespace std;
class node
{   public:
	node* next;
	int marks;
	string subject;
};
node* addbeg(int m ,string s ,node* head)
{
	node* newnode = new node();
	newnode->marks = m;
	newnode->subject = s;
	newnode->next = head;
	head = newnode;
	return head;
}
void addend(int m, string s,node* head)
{
	if (head == NULL)
		cout<<"The list is empty!!\n";
	else
	{
		node* newnode = new node();
		newnode->marks = m;
		newnode->subject = s;
		node* ptr = head;
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
{   node* ptr = head;
	node* ptr1 = head; 
	while(ptr != NULL)
	{	//cout<<"inside while display\n";
	    cout<<ptr->subject<<"\t";			
		ptr=ptr->next;
	}
	cout<<endl;
	while(ptr1 != NULL)
	{	cout<<ptr1->marks<<"\t";		
		ptr1=ptr1->next;
	}
}

int main()
{
	int n;
	cout<<"Enter the no of students:";
	cin>>n;
	node* arr[n];
	for(int i = 0;i<n;i++)
	{
		arr[i] = NULL;
	}
	for(int i = 0;i<n;i++)
	{
		int s = 0;
		cout<<"\n\tStudent "<<i+1<<"\n";
		cout<<"Enter no of Subjects:";
		cin>>s;
        for(int j = 1; j <= s;j++)
        {
            int mark;
		    string sub;
            cout<<"Enter subject "<<j<<" name:";
            cin>>sub;
            cout<<"Enter subject "<<j<<" marks:";
            cin>>mark;
            if(j == 1)
            {    
                arr[i] = addbeg(mark, sub, arr[i]);
            }
            else
            {
                addend(mark, sub, arr[i]);
            }
        }
    }
    cout<<"\n\n\n**The students and their marks**\n\n";
    for(int i = 0; i<n; i++)
    {
        cout<<"Student "<<i+1<<endl;
        display(arr[i]);
        cout<<"\n\n";   
    }
    return 0;
}
