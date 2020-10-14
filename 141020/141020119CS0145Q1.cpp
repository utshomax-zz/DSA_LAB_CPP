#include<iostream>
using namespace std;
struct Node{
	char data;
	struct Node* right;
	struct Node* left;
};
struct Node* BSTSearch(int data,struct Node* root)
{

	if(root->data==data)
	return NULL;
	
	if(root->right==NULL&&root->left==NULL)
	return root;
	
	if(root==NULL)
	return NULL;
	
	if(data>root->data)
	{
		if(root->right==NULL)
		return root;
		return BSTSearch(data,root->right);
	}
	else
	{
		if(root->left==NULL)
		return root;
		return BSTSearch(data,root->left);
	}
	
	
}
struct Node* BSTInsert(int data,struct Node* root)
{
	struct Node* item=(struct Node *)malloc(sizeof(struct Node));
	item->data=data; item->right=NULL; item->left=NULL;
	
	if(root==NULL)return item;
	
	struct Node* found=BSTSearch(data,root);
	if(found==NULL)
	return root;
	if(data>found->data)
	found->right=item;
	else
	found->left=item;
	return root;	
}
void BSTInorderStack(struct Node* root,struct Node* arr[])
{
	struct Node* curr=root;
	int top=-1;
	while(curr||top>=0)
	{
		while(curr)
		{
			arr[++top]=curr;
			curr=curr->left;
		}
		curr=arr[top];
		top--;
		printf("%c ",curr->data);
		curr=curr->right;
	}	
}
int main()
{
	struct Node* root=NULL;
	struct Node* arr[100];
    int len,i;
    char v;
    cout << "Inter length: ";
    cin >> len;
    cout << "Inter values: \n";
    for(i=0;i<len; i++){
       cin >> v;
       root=BSTInsert(v,root);
    }
	BSTInorderStack(root,arr);
}