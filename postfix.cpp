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
		void set( char *f )
		{
			l = f ;
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

		void calculate();
		int display()
		{
			return stacks[0];
		}
};

void stack::calculate() 
{	while ( *l )
		{	int a,b,c;
		if ( *l == ' ' || *l == '\t' )
			{
				l++ ;
				continue ;
			}
			if ( isdigit ( *l ) )
			{
				m = *l - '0' ;
				push ( m ) ;
			}
			else
			{
				a = pop( ) ;
				b = pop( ) ;
				c = operation( a, b, *l);
				push(c);
			}
			l++;
		}
}

int main() 
{
	stack s;
	char b[50];
	cout<<"Enter expression to be evaluated:";
	cin.getline(b , 50);
	s.set( b );
	s.calculate();
	cout << "the result is " << s.display() << endl;
    return 0;
}
