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
void inorder(Node* root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}
void deleteRightMostNode(Node* root, Node* d_node)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();
		if(temp->data==d_node->data)
		{
			delete temp;
			return;	
		}
		if(temp->right->data==d_node->data)
		{
			delete temp->right;
			return;	
		}
		else
		q.push(temp->right);	
		if(temp->left->data==d_node->data)
		{
			delete temp->left;
			return;	
		}
		else
		q.push(temp->left);
	}	
}
int findRightMostNodeKeyNode(Node* root,int key)
{
	queue<Node*> q;
	q.push(root);
	Node* key_node=NULL;
	Node* temp=NULL;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->data==key)
		key_node=temp;
		if(temp->left!=NULL)
		{
			q.push(temp->left);	
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);	
		}
	}
	int x=temp->data;
	deleteRightMostNode(root,temp);
	key_node->data=x;
	return x;
}
int main()
{
	struct Node* root=createNode(1);
	//cout<<root->data;
	root->left=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(5);
	root->right=createNode(6);
	root->right->right=createNode(7);
	cout<<"Befor Deletion\n";
	inorder(root);
	int rightMostNode=findRightMostNodeKeyNode(root,1);
	cout<<rightMostNode;
	//insertNode(12,root);
	//insertNode(20,root);
	cout<<"\nAfter deletion\n";
	inorder(root);
}
