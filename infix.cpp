#include<iostream>

using namespace std;

class stack 
{
	public:
		char stacks[100];
		int top1;
		stack() 
        {
			
			top1 = -1;
		}

		void push(char item) 
        {
			top1++;
			stacks[top1] = item;
		}
		char top()
		{
			return stacks[top1];
		}
		void pop() 
        {
			top1--;
		}

		int display()
		{
			return stacks[top1];
		}
};
int precedence(char op)
{ 
	if(op == '+'||op == '-') 
		return 1; 
	else if(op == '*'||op == '/') 
		return 2; 
	else
		return 0; 
}
int operation(int a,int b,char oprtr)
{	
	/*cout<<"called"<<a<<b<<endl;
	cout<<"oprtr"<<oprtr<<endl;*/
	switch(oprtr) 
    {
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	
				
	}
}
int evaluate(string in)
{ 
    int i; 
    stack values;
    stack ops;
    ops.push('t');
      
    for(i = 0; i < in.length(); i++)
    { 
        
        if(in[i] == ' ') 
            continue; 
	
	    if(isdigit(in[i]))
	    { 
            int val = in[i];
            values.push(val); 
     	}
        else
        { 
            while(ops.top() != 't' && precedence(ops.top()) >= precedence(in[i]))
	    { 
                int val2;
		        val2 = values.top();
                values.pop(); 
                  
                int val1; 
		        val1 = values.top();
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(operation(int(val1)-48, int(val2)-48, op)); 
        } 

            ops.push(in[i]); 
        } 
    } 
    while(ops.top() != 't')
    { 
       int val2;
		 val2 = values.top();
                values.pop(); 
                  
                int val1; 
		val1 = values.top();
                values.pop();  
                  
        	char op = ops.top(); 
		ops.pop(); 
                  
	        values.push(operation(int(val1)-48, int(val2)-48, op)); 
	
    } 

    return values.display(); 
}

int main() 
{ 
	string l;
	cout << "Enter an expression:";
	cin>>l; 
    cout << "Result:"<<evaluate(l) << "\n";  
    return 0; 
}  
