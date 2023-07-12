#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* createNode(int data)
{
		Node* newnode=new Node();
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	
}
Node* insertNode(Node* root,int data)
{
	cout<<"InsertNode Entered";
	if(root==NULL)
	{
		root=createNode(data);
		return root;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();
		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left=createNode(data);
			cout<<"Insert Node Exited"<<temp->left->data;
			return temp->left;
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right=createNode(data);
			cout<<"Insert Node Exited"<<temp->right->data;
			return temp->right;
		}
	}
	
}
void inorder(Node* temp)
{
//	cout<<"Traversal Entered";
	if(temp==NULL)
	{
		cout<<"Hello";
		return;
	}
//	cout<<temp->data<<"\n";
	inorder(temp->left);
	cout<<"DATA:"<<temp->data<<"\n";
	inorder(temp->right);
	
}
main()
{
	Node* root=createNode(10);
	root->left=insertNode(root,5);
	root->right=insertNode(root,15);
//	root->left->right=insertNode(root,15);
//	root->left->left=insertNode(root,15);
	cout<<root->data;
	inorder(root);
	
	
}
