#include<iostream>
#include<string>

void reverse(string s)
{
	int tmpIndex=0;
	string tmpStr;
	int j;
	for(int i=0;i<s.length();i++)
	{
		tmpStr[tmpIndex]=s[i];
		if(s[i]==' ')
		{
			j=tmpIndex-1;
			while(j>=0)
			{
				cout<<tmpStr[j];
				j--;
			}
			tmpIndex=0;
			
		}
		tmpIndex++;
	}
}
int main()
{
	reverse("Hello World");
}
