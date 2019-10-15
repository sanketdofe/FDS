#include <iostream>
using namespace std;
class node
{
    public:
    char data;
    node* left;
    node* right;
    node()
    {
        left=NULL;
        right=NULL;
    }
};

node* newnode(char data)
{
    node* temp = new node();
    temp->data = data;
    return temp;
}

int height(node* parent)
{
    int lheight,rheight;
    if(parent==NULL)
    {
        return 0;
    }
    else
    {
        lheight=height(parent->left);
        rheight=height(parent->right);
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }
    
}

node* head;
int main()
{
    node* head = NULL;
    head = newnode('A');
    head->left = newnode('B');
    head->right = newnode('C');
    head->left->left = newnode('D');
    head->left->right = newnode('E');
    head->right->right = newnode('F');
    head->right->right->left = newnode('G');
    head->right->right->right = newnode('H');
    int h = height(head);
    cout<<"The height of tree is "<<h<<endl;   
}
