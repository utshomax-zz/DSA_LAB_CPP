//UTSAB OJHA
//119CS0145
//g++ compiler
#include <bits/stdc++.h> 
using namespace std;
void enqueue(char que[8][15],char d,int p)
{
	for(int i=0;i<15;i++)
	{
		if(que[p-1][i]==' ')
		{que[p-1][i]=d;return;}
	}
	cout<<"OVERFLOW IN QUEUE ";
}
void dequeue(char que[8][15])
{
	for(int i=4;i>=0;i--)
	{
		for(int j=9;j>=0;j--)
		{
			if(que[i][j]!=' ')
			{que[i][j]=' ';return;}
		}
	}
	cout<<"UNDERFLOW ";
}
int main()
{
	char que[8][15];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<15;j++)
		que[i][j]=' ';
	}
    cout<<"Performing Enequeue";
	enqueue(que,'D',1);
	enqueue(que,'E',2);
	enqueue(que,'F',3);
	enqueue(que,'G',4);
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<15;j++)
		cout<<que[i][j]<<" ";
		cout<<"\n";
	}
    cout<<"Performing Dequeue";
    dequeue(que);
    for(int i=0;i<8;i++)
	{
		for(int j=0;j<15;j++)
		cout<<que[i][j]<<" ";
		cout<<"\n";
	}
}