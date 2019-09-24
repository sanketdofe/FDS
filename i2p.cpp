#include <iostream>
using namespace std;
class stack 
{
	public:
		char stacks[50];
		int top;
		stack() 
        	{
			top = -1;
		}
		int top1()
		{	
			return stacks[top];
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
	
		int display()
		{
			return stacks[0];
		}
};
int priority(char c) 
{	if(c == '*' || c == '/')
		return 1; 
	else if(c == '+' || c == '-')
		return 2;
	else
		return 0; 
} 
void i2p(string s) 
{ 
    stack st;
    st.push('t'); 
    int l = s.length(); 
    string n; 
    for(int i = 0; i < l; i++) 
    { 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
		n+=s[i]; 

        else
	{ 
            while(st.top1() != 't' && priority(s[i]) >= priority(st.top1())) 
            { 
                char c = st.top1();
		        st.pop();
                n += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(st.top1() != 't') 
    { 
        char c = st.top1();
	    st.pop();
        n += c; 
    } 
      
    cout << n << endl; 
  
}

int main() 
{ 
	string q;
 	cout<<"Enter an expression:";
	cin>>q;
	i2p(q);
	return 0; 
} 
