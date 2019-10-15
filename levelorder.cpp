#include <iostream>
using namespace std;
class Node 
{ 
	public:
	int data; 
	Node* left;
	Node* right; 
}; 

class queue
{	Node* q[100];
    int front,rear;
	public:
	queue()
	{
		front=-1;
		rear=-1;
	}
	bool isfull()
	{
		if(rear==99)
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
	void enqueue(Node* l)
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
			rear++;
			q[rear]=l;
		}
		//cout<<"\nenqueued.\n";
	}
	void dequeue()
	{
		if(isempty())
		{	
		    return;
		}
		/*else if(front=rear)
		{
		    q[front]=NULL;
		    front=-1;
		    rear=-1;
		}*/
		else
		{	//Node* l=q[front];
			//q[front]=NULL;
			front++;
			//return l;
		}
        //cout<<"\ndequeued\n";
	}
	Node* peek()
	{
		if(isempty())
			return NULL;
		else
		{
			return q[front];
		}
	}
	void print()
	{	cout<<"The queue contains:";
		for(int i=front;i<=rear;i++)
		{	cout<<q[i]->data<<"\t";
		}
	}
};


// A Binary Tree Node 

// Iterative method to find height of Bianry Tree 
void printLevelOrder(Node* root) 
{ 
	// Base Case 
	if (root == NULL)
	    return; 

	// Create an empty queue for level order tarversal 
	queue q; 

	// Enqueue Root and initialize height 
	q.enqueue(root); 

	while (q.isempty() == false) 
	{ 
		// Print front of queue and remove it from queue 
		//q.print();
		Node* node = q.peek(); 
		cout << "\n"<<node->data << " "; 
		q.dequeue(); 

		/* Enqueue left child */
		if (node->left != NULL) 
		{	q.enqueue(node->left);
		}	

		/*Enqueue right child */
		if (node->right != NULL) 
		{	q.enqueue(node->right);
		}	
		
	}
	
} 

// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
	Node* temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	// Let us create binary tree shown in above diagram 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	cout << "Level Order traversal of binary tree is \n"; 
	printLevelOrder(root); 
	return 0; 
} 

