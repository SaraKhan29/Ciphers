#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

int main()
{
	string s;
	cout<<"Enter text:"<<endl;
	cin>>s;
	int n=s.length();
	int key[n];
	srand(time(NULL));	
	for(int i=0;i<n;i++)
	{
		key[i]=rand()%26;
	}
				
	for(int i=0;i<n;i++)	
	{	

		if(s[i]>='a' && s[i]<='z')
					s[i]=(((s[i]-97)+key[i])%26)+97;
		
	}
	cout<<"after encryption:"<<endl;
	for(int j=0;j<n;j++)
		cout<<s[j];
		cout<<endl;		
	int x;		
	for(int i=0;i<n;i++)	
	{	
			x=(((s[i]-97)-key[i])%26);
			if(x<0)		
			{
				x=(x+26)%26;
			}
			s[i]=x+97;
	}
	cout<<"after decryption:"<<endl;
	for(int j=0;j<n;j++)
	cout<<s[j];			
return 0;
}


