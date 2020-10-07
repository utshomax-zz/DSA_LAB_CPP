#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* right;
	struct Node* left;
};
int Height(struct Node* root)
{
	if(root==NULL)
	return 0;
	int l=Height(root->left);
	int r=Height(root->right);
	if(l>r)
	return l+1;
	else
	return r+1;
}
struct Node* traverse(struct Node* root, int level) 
{ 
    if (root == NULL) 
        return NULL; 
    if (level == 1) 
        {
        	if(root->left==NULL||root->right==NULL)
        	return root;
		}
    else if (level > 1) 
    { 
        struct Node* l=traverse(root->left, level-1); 
        struct Node* r=traverse(root->right, level-1); 
        if(l->left==NULL||l->right==NULL)
        return l;
        else if(r->right==NULL||r->left==NULL)
        return r;
    } 
}
struct Node* empty(struct Node* root) 
{ 
    int h = Height(root); 
    int i; 
    struct Node* e;
    for (i=1; i<=h; i++) 
    {
	e=traverse(root, i);
	if(e->left==NULL||e->right==NULL)
	return e;
	} 
    return e;
} 
struct Node* insert(int data,struct Node* root)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->right=NULL;
	temp->left=NULL;
	temp->data=data;
		if(root==NULL)
		{
			root=temp;
			return root;
		}
	struct Node* last=empty(root);
	if(last->left==NULL)
	last->left=temp;
	else if(last->right==NULL)
	last->right=temp;
		
return root;
}

void Preorder(struct Node* root)
{
	if(root==NULL)
	return;
	cout << root->data <<" ";
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(struct Node* root)
{
	if(root==NULL)
	return;
	Postorder(root->left);
	Postorder(root->right);
	cout <<root->data <<" ";
}
void Inorder(struct Node* root)
{
	if(root==NULL)
	return;
	Inorder(root->left);
	cout <<root->data <<" ";
	Inorder(root->right);
}
int main()
{
	struct Node* root=NULL;
    int opt,val,cval,i;
    do
    {
        cout << "1. Insert 2.Result 3.Exit\nEnter Your Choice :";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "How many value you want to Insert ? : ";
            cin >> cval;
            cout << "Enter values to Insert : \n";
            for(i=0;i<cval;i++){
            cin >> val;
            root=insert(val,root);
            }
            break;
        case 2:
            cout << "Height : " << Height(root)<<"\n";
            cout << "Inorder : ";
            Inorder(root); cout<<"\n";
            cout << "Preorder : ";
            Preorder(root);cout <<"\n";
            cout << "Postorder : ";
            Postorder(root);cout <<"\n";
        case 3:
            break;    
        default:
            break;
        }
       
    } while (opt!=3);
	
}