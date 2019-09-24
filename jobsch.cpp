#include<iostream>
using namespace std;
class queue
{	int q[int size],front,rear;
	public:
	queue(int s)
	{
		size=s;
		front=-1;
		rear=-1;
	}
	void enqueue(int l)
	{	
		/*if(isfull())
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
			for(int i=rear;i<=front;i--)
			{
				if(q[i]>l)
				{
					q[i]=q[i+1];
				}
			}
			q[i+1]=x;
			rear++;
		 */
		if (isfull()) 
    	{ 
        	printf("\nQueue is Full"); 
        	return; 
   		} 
  
    	else if(front == -1) /* Insert First Element */
    	{ 
        	front = rear = 0; 
        	q[rear] = value; 
    	} 
  
    	else if (rear == size-1 && front != 0) 
    	{ 
        	rear = 0; 
        	q[rear] = value; 
    	} 
  
    	else
    	{ 
        	rear++; 
        	q[rear] = value; 
    	}
	}
	bool isfull()
	{
		if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
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
		/*if(isempty()
			return;
		else
		{	int l=q[front];
			q[front]=0;
			front=front+1;
		}
		return l;
		}
		int front1()
		{
		if(isempty())
			return -1;
		else
		{
			return q[front];
		}*/
		{ 
    	if (isempty()) 
    	{ 
        	printf("\nQueue is Empty"); 
      		return 0; 
   		} 
  
    	int data = q[front]; 
    	q[front] = -1; 
    	if (front == rear) 
    	{ 
    	    front = -1; 
    	    rear = -1; 
   		} 
    	else if (front == size-1) 
        	front = 0; 
    	else
        	front++; 
  
  		return data; 
} 
	}
};

