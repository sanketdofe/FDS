#include<iostream>

using namespace std;

class stack 
{
	public:
		int stacks[50];
		int top;
		char str[50];
		int m;
		char *l;
		stack() 
        {
			top = -1;
		}
		void push(char item) 
        {
			top++;
			stacks[top] = item;
		}

		char pop() 
        {
			int item = stacks[top];
			top--;
			return item;
		}

		int operation(int a,int b,char oprtr)
        {
			switch(oprtr) 
            {
				case '+':return a+b;
				case '-':return a-b;
				case '*':return a*b;
				case '/':return a/b;
				default: return 0;
			}
		}

		void calculate(string);
		int display()
		{
			return stacks[0];
		}
};

void stack::calculate(string l) 
{	//while ( *l )
	for(int i=0;i<=l.length();i++)
		{	
		    int a,b,c;
		    if ( l[i] == ' ' || l[i] == '\t' )
			{
				continue ;
			}
			if ( isdigit ( l[i] ) )
			{
				m = l[i] - '0' ;
				push ( m ) ;
			}
			else
			{
				a = pop( ) ;
				b = pop( ) ;
				c = operation( a, b, l[i]);
				push(c);
			}
		}
}

int main() 
{
	stack s;
	string b;
	cout<<"Enter expression to be evaluated:";
	cin>>b;
	s.calculate(b);
	cout << "the result is " << s.display() << endl;
    return 0;
}
