#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		left=NULL;
		right=NULL;
		data=x;
	}
};
Node* createNode(int data)
{
	return (new Node(data));
}
Node* insertNode(Node* root,int data)
{
	if(root==NULL)
	return createNode(data);
	if(root->data>data)
	{
	root->left= insertNode(root->left,data);
	}
	if(root->data<data)
	{
	root->right= insertNode(root->right,data);
	}
	return root;	
}
void inorder(Node* root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}
int main()
{
	struct Node* root=createNode(10);
	insertNode(root,5);
	insertNode(root,4);
	insertNode(root,7);
	insertNode(root,13);
	insertNode(root,12);
	insertNode(root,15);
	inorder(root);
}
