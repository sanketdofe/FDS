#include <iostream>
using namespace std;
void toh(int n, char a[], char b[], char c[])
{	if(n>0)
	{	toh(n-1,a,c,b);
		cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
		toh(n-1,b,a,c);
	}
}
int main()
{	int k;
	char x[] ="A";
	char y[] ="B";
	char z[] ="C";
	cout<<"Enter the no of disks:";
	cin>>k;
	toh(k,x,y,z);
	return 0;
}
