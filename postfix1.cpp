#include <iostream>
using namespace std;
class stack
{	public:
	char arr[100];
	int top ;
	int m;
	char *l;
	stack()
	{	top = -1;
	}
	void set( char *str )
	{
		l = str ;
	}
	void push(char l)
	{	top++;
		arr[top]=l;	
	}
	char pop()
	{	char k=arr[top];
		arr[top]=0;
		top--;
		return k;
	}
	void display()
	{	for(int i=top;i>=0;i--)
		cout<<arr[i]<<endl;
	}
	void calculate()
	{
		while ( *l )
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
				switch ( *l )
				{
					case '+' :
						c = b + a ;
						break ;
					case '-' :
						c = b - a ;
						break ;
					case '/' :
						c = b / a ;
						break ;
					case '*' :
						c = b * a;
						break ;
					default :
						cout << "Unknown operator" ;
						break;
						
				}
 				push ( c ) ;
			}
			l++ ;
		}
	}
};
int main()
{	stack s;
	char b[100];
	cout<<"Enter expression to be evaluated:";
	cin.getline(b , 100);
	s.set( b );
	s.calculate();
	s.display();
	return 0;
}
	 
