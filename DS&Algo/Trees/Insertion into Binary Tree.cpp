#include<iostream>
#include<queue>
using namespace std;
//Structure of Node
struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};
Node* createNode(int data)
{
	return (new Node(data));
}
void insertNode(int data,Node* root)
{
	if(root==NULL)
	return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
	struct Node *temp=q.front();
	q.pop();
	if(temp->left==NULL)
	{
		struct Node* newNodeLeft=createNode(data);
		temp->left=newNodeLeft;
		return;
	}
	else
	q.push(temp->left);
	if(temp->right==NULL)
	{
		struct Node* newNodeRight=createNode(data);
		temp->right=newNodeRight;
		return;
	}
	else
	q.push(temp->right);
	}
	
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
	//cout<<root->data;
	root->left=createNode(11);
	root->left->left=createNode(7);
//	root->left->right=createNode(5);
	root->right=createNode(9);
	root->right->right=createNode(8);
	root->right->left=createNode(15);
	cout<<"Befor Insertion\n";
	inorder(root);
	insertNode(12,root);
	//insertNode(20,root);
	cout<<"\nAfter Insertion\n";
	inorder(root);
}
