#include <iostream>

template<typename T>
class Vector{
	private:
		T *arr;
		int capacity;
		int current;
	public:
		Vector()
		{
			arr= new T[1];
			capacity=1;
			current=0;	
		}
		~Vector()
		{
			delete[] arr;
		}
		void push(T data)
		{
			if(current == capacity)
			{
				T *temp=new T[2*capacity];
				for(int i=0;i<capacity;i++)
				{
					temp[i]=arr[i];
				}
				delete[] arr;
				capacity*=2;
				arr=temp;	
			}
			arr[current]=data;
			current++;	
		}
		void push(T data,int pos)
		{
			if(pos==capacity)
				push(data);
			else
				arr[pos]=data;
		}
		void pop()
		{
			current--;	
		}
		int getSize()
		{
			return current;	
		}	
};
int main()
{
	Vector<int> vec1;
	vec1.push(10);
	return 0;
}
