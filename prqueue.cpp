#include<iostream>
using namespace std;
class queue
{	int q[100],front,rear,i;
	public:
	queue()
	{
		front=-1;
		rear=-1;
	}
	void enqueue(int l)
	{	
		if(isfull())
		{	
			return;
		}
		else if(isempty())
		{
			front = rear = 0;
			q[rear]=l;
		}
		else
		{
			for(i=rear;i>=front;i--)
			{
				if(q[i]>l)
				{
					q[i+1]=q[i];
				}
				else break;
			}
			q[i+1]=l;
			rear++;
			
		}
	}
	bool isfull()
	{
		if(rear==499)
			return true;
		else
			return false;
	}
	bool isempty()
	{
		if(front==-1 && rear==-1)
			return true;
		else
			return false;
	}
	/*void front()
	{
		if(isempty())
			return;
		else
				*/
	int dequeue()
	{
		if(isempty())
			return -1;
		else
		{	int l=q[front];
			q[front]=0;
			front=front+1;
			return l;
		}

	}
	int front1()
	{
		if(isempty())
			return -1;
		else
		{
			return q[front];
		}
	}
	void print()
	{	cout<<"The queue contains:";
		for(int i=front;i<=rear;i++)
		{	cout<<q[i]<<"\t";
		}
	}
};
int main()
{
	queue kick;
	int choice,l;
	cout<<"1.Display the queue\n2.Add an element.\n3.Delete an element\n4.Display the first element.\n5.Exit\n";
	while(choice!=5)
	{	cout<<"\nEnter a choice:";
		cin>>choice;
		switch(choice)
		{	case 1:kick.print();break;
			case 2:cout<<"Enter an element:";cin>>l;kick.enqueue(l);break;
			case 3:kick.dequeue();break;
			case 4:cout<<"The first element is "<<kick.front1();break;

		}
	}
	return 0;
}
		
