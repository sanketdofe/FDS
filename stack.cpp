#include <iostream>
using namespace std;
class stack
{	public:
	char arr[100];
	int top=0 ;
	void push(char l)
	{	arr[top]=l;
		top++;	
	}
	void pop()
	{	arr[top]=0;
		top--;
	}
	void display()
	{	for(int i=top;i>=0;i--)
		cout<<arr[i]<<endl;
	}
};
int main()
{	stack s;
	int a;
	char d;
	cout<<"1.Push an element in the stack.\n2.Pop the top element from the stack.\n3.Display the elements of the stack.\n4.Exit the program.\n";
	do
	{	
		cout<<"Enter choice:";
		cin>>a;
		switch(a)
		{	case 1:cout<<"Enter an element:";cin>>d;s.push(d);break;
			case 2:s.pop();cout<<"Popped out successfully.\n";break;
			case 3:cout<<"The stack contains:";s.display();break;
			case 4:break;
			default:cout<<"Invalid selection.\n";break;
		}
	}
	while(a!=0);
	return 0;
}
