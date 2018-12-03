#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void encryption(char msg[],char key[5][5])
{
	int len=strlen(msg);
	int t1,t2,t3,t4;
	for(int i=1;i<len;i++)
	{
		if(msg[i-1]==msg[i])
		{
			for(int j=len-1;j>=i;j--)
			{
				msg[j+1]=msg[j];
			}
			msg[i]='x';
			msg[len+1]='\0';
			len=len+1;
		}
	}
	if((len%2)!=0)
	{
		msg[len]='x';
		msg[len+1]='\0';
		len=len+1;
	}	
	for(int i=1;msg[i]!='\0';i=i+2)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				if(msg[i]==key[j][k])
				{
					t1=j;
					t2=k;
					break;
				}
			}
		}
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				if(msg[i-1]==key[j][k])
				{
					t3=j;
					t4=k;
					break;
				}
			}
		}
		if(t1==t3)
		{
			msg[i]=key[t1][(t2+1)%5];
			msg[i-1]=key[t3][(t4+1)%5];
		}
		else if(t2==t4)
		{
			msg[i]=key[(t1+1)%5][t2];
			msg[i-1]=key[(t3+1)%5][t4];
		}
		else
		{
			msg[i]=key[t1][t4];
			msg[i-1]=key[t3][t2];
		}
	}
	msg[len]='\0';
}
void decryption(char* msg,char key[5][5])
{
	int len=strlen(msg);
	int t1,t2,t3,t4;
	for(int i=1;msg[i]!='\0';i=i+2)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				if(msg[i]==key[j][k])
				{
					t1=j;
					t2=k;
					break;
				}
			}
		}
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				if(msg[i-1]==key[j][k])
				{
					t3=j;
					t4=k;
					break;
				}
			}
		}
		if(t1==t3)
		{
			if(t2==0)
			{
				t2=4;
			}
			else
				t2=t2-1;
			if(t4==0)
			{
				t4=4;
			}
			else
				t4=t4-1;
			msg[i]=key[t1][t2];
			msg[i-1]=key[t3][t4];
		}
		else if(t2==t4)
		{
			if(t1==0)
				t1=4;
			else
				t1=t1-1;
			if(t3==0)
				t3=4;
			else
				t3=t3-1;
			msg[i]=key[t1][t2];
			msg[i-1]=key[t3][t4];
		}
		else
		{
			msg[i]=key[t1][t4];
			msg[i-1]=key[t3][t2];
		}
	}
	msg[len]='\0';
//	cout<<endl<<msg;
	int j;
	for(int i=0;msg[i]!='\0';i++)
	{
		if(msg[i]=='x')
		{
			for(j=i+1;msg[j]!='\0';j++)
			{
				msg[j-1]=msg[j];
			}
			msg[j-1]='\0';
		}
	}
}
int main()
{
	char key[5][5]={{'l','g','d','b','a'},{'q','m','h','e','c'},{'u','r','n','i','f'},{'x','v','s','o','k'},{'z','y','w','t','p'}};
	char msg[200];
	
	cout<<"Enter the string\n";
	gets(msg);
	
	encryption(msg,key);
		
	cout<<"\nAfter Encryption\n";
	puts(msg);
	
	decryption(msg,key);
	
	cout<<"\nAfter Decryption is\n";
	puts(msg);
	
	return 0;	
}

