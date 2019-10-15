#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node()
    {
        left=right=NULL;
    }
};
node* newnode(int data)
{
    node* ptr = new node();
    ptr->data=data;
    ptr->left=ptr->right=NULL;
    return ptr;
}
/*
void prepost(char preelement,char pre[]),char post[])
{
    //preelement = pre[0];
    parent->left = node(pre[1]);
    char temp;
    int index;
    for (int i=0;i<len(post);i++)
    {
        temp=post[i];
        index = i;
        if(post[i]==pre[1])
        {    
            break;
        }
    }
    char leftpost[index+1];
    for(int i=0;i<=index;i++)
    {   
        leftpost[i]=post[i];
    }
    char rightpost[len(post)-index-2)
    for(int i=index+2;i<len(post);i++)
    {
        rightpost[i]=post[i];
    }
    prepost(preelement++;pre[];leftpost);
    prepost(pre)
}
*/


node* prepost(int pre[], int post[], int* preindex, int l, int h, int size)  
{  
    // Base case  
    if (*preindex >= size || l > h)  
        return NULL;  
  
    // The first node in preorder traversal is root. So take the node at  
    // preIndex from preorder and make it root, and increment preIndex  
    node* root = newnode( pre[*preindex] );  
    ++*preindex;  
  
    // If the current subarry has only one element, no need to recur  
    if (l == h)  
        return root; 
  
    // Search the next element of pre[] in post[]
    int i;    
    for (int j = l; j <= h; ++j)
    {
        i=j;  
        if (pre[*preindex] == post[j])  
            break;  
    }
    // Use the index of element found in postorder to divide  
        // postorder array in two parts. Left subtree and right subtree  
    if (i <= h)  
    {  
        root->left = prepost(pre, post, preindex,l, i, size);  
        root->right = prepost(pre, post, preindex,i + 1, h, size);  
    }  
  
    return root;  
}

void displayinorder(node* root)
{
    if (root==NULL)
        return;
    displayinorder(root->left);
    cout<<root->data<<"\t";
    displayinorder(root->right);
}
int main()
{
    
    int pre[9] = {1,2,4,8,9,5,3,6,7};
    int post[9] = {8,9,4,5,2,6,7,3,1};
    int index = 0;
    int size=sizeof(pre)/sizeof(pre[0]);
    node* root = prepost(pre,post,&index,0,size-1,size);
    cout<<"The inorder traversal is ";
    displayinorder(root);
    return 0;
}
