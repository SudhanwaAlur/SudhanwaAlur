#include<bits/stdc++.h>
using namespace std;
class Stack{
	queue<int> q1,q2;
	public:
	void push(int item);
	int pop();
};
void Stack::push(int item){
	q1.push(item);
}
int Stack::pop(){
	while(q1.size()!=1){
	q2.push(q1.front());
	q1.pop();
	}
	int element=q1.front();
	q1.pop();
	queue<int> q;
	q=q1;
	q1=q2;
	q2=q;
	return element;
}
main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<s.pop();
	cout<<s.pop();
}
