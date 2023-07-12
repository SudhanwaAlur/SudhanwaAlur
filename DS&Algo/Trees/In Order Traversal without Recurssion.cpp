#include<iostream>
#include<stack>
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
	stack<Node*> s;
	Node* temp=root;
	//s.push(root);
	while(!s.empty() || temp !=NULL)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		cout<<temp->data<<"\t";
		temp=temp->right;
	}
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
	inorder(root);
}
