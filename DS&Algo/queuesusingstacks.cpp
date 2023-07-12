#include<bits/stdc++.h>
using namespace std;
class Queue{
	stack<int> s1,s2;
	public:
		void push(int item);
		int pop();
};
void Queue::push(int item){
	s1.push(item);
}
int Queue::pop(){
	while(s1.size()!=0){
		s2.push(s1.top());
		s1.pop();
	}
	int element=s2.top();
	s2.pop();
	return element;
}
main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout<< q.pop();
	cout<<q.pop();
}
