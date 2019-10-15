#include <iostream>
#include <fstream>
using namespace std;
class node
{   public:
	node* next;
	int marks;
	string subject;
};
class student
{
    public:
    int id;
    string name;
    node* exam;
};
/*node* addbeg(int m ,string s ,node* head)
{
	node* newnode = new node();
	newnode->marks = m;
	newnode->subject = s;
	newnode->next = head;
	head = newnode;
	return head;
}*/
node* addexam(int m, string s,node* head)
{
	if (head == NULL)
    {
        node* newnode = new node();
	    newnode->marks = m;
    	newnode->subject = s;
	    newnode->next = NULL;
	    head = newnode;
    }
	else
	{
		node* newnode = new node();
		newnode->marks = m;
		newnode->subject = s;
		node* ptr = head;
		while(ptr->next != NULL)
			ptr=ptr->next;
		newnode->next=NULL;
		ptr->next = newnode;
	}
	return head;
}

student* addstudent(int id, string name)
{
    student* stu = new student();
    stu->id=id;
    stu->name=name;
    return stu;
}

void displayexam(node* head)
{   node* ptr = head;
	node* ptr1 = head; 
	while(ptr != NULL)
	{	//cout<<"inside while display\n";
	    cout<<ptr->subject<<"\t\t";			
		ptr=ptr->next;
	}
	cout<<endl;
	while(ptr1 != NULL)
	{	cout<<ptr1->marks<<"\t\t";		
		ptr1=ptr1->next;
	}
}

void displaystudent(student* head)
{
    cout<<"ID:"<<head->id<<"\t\t";
    cout<<"Name:"<<head->name<<endl;
    displayexam(head->exam);
}



int main()
{
	ifstream f;
	int n;
	f.open("database1.txt");
	f>>n;//no of students
	//cout<<"no of stu"<<n<<endl;
	student* arr[n];
	for(int i = 0;i<n;i++)
	{
		arr[i] = NULL;
	}
	for(int i = 0;i<n;i++)
	{
		int s;
		//cout<<"\n\tStudent "<<i+1<<"\n";
		//cout<<"Enter no of Subjects:";
		string line;
		f>>line;
		if (line=="student")
		{   
		    int id;
		    string name;
		    f>>id;
		    f>>name;
		    arr[i] = addstudent(id,name);
		    f>>s;//no of subjects
		    //cout<<"no of sub"<<s<<endl;
            for(int j = 1; j <= s;j++)
            {
                
                int mark;
		        string sub;
                //cout<<"Enter subject "<<j<<" name:";
                //cin>>sub;
                f>>sub;
                //cout<<"Enter subject "<<j<<" marks:";
                //cin>>mark;
                f>>mark;
                arr[i]->exam = addexam(mark, sub, arr[i]->exam);
            }
        }   
    }
    f.close();
    cout<<"\n\n\n**The students and their marks**\n\n";
    for(int i = 0; i<n; i++)
    {
        //cout<<"Student "<<i+1<<endl;
        displaystudent(arr[i]);
        cout<<"\n\n";   
    }
    return 0;
}
