#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
};
Node* createNode(int data)
{
	return (new Node(data));
}
void breadthFirstSearch(Node* root)
{
	queue<Node*> q;
	Node* temp=NULL;
	if(root!=NULL)
	{
		q.push(root);
		temp=q.front();
		cout<<temp->data<<"\t";
	}
	else return;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->left!=NULL)
		{
			cout<<temp->left->data<<"\t";
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			cout<<temp->right->data<<"\t";
			q.push(temp->right);
		}
	}
}
int main()
{
	Node* root=createNode(1);
	root->left=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(5);
	root->right=createNode(6);
	root->right->right=createNode(7);
	breadthFirstSearch(root);
}
