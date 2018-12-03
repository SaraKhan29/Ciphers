//caesar cipher
#include<iostream>
#include<string>
using namespace std;

int main()
{
int i,n,key;	
string s;
cout<<"Enter the text to be ciphered"<<endl;
getline(cin,s);
cout<<"Enter the value of key"<<endl;
cin>>key;
char c;	
n=s.length();
//caesar algo
for(i=0;i<n;i++)	
{

	if(s[i]>='a' && s[i]<='z')
	{
		c=(int)(((s[i]-97)+key)%26);
		s[i]=(char)(c+97);
	}
	
}

cout<<"Text after encryption:"<<endl;
cout<<s<<endl;
for(i=0;i<n;i++)	
{

	if(s[i]>='a' && s[i]<='z')
	{
		c=(int)(((s[i]-97)-key)%26);
		if(c<0)
				c=(c+26)%26;
		s[i]=(char)(c+97);
	}
}

cout<<endl<<"Text after decryption:"<<endl;
cout<<s<<endl;
	
	
	return 0;
}
