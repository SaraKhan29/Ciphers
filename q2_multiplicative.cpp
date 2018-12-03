#include<iostream>
using namespace std;
int gcd(int key)
{
	int r1=26,r2=key;
	int t1=0,t2=1;
	int q=0,r=0,t=0;
	while(r2 > 0)
	{
		q=r1/r2;
		r=(r1-(q*r2));
		r1=r2;
		r2=r;
		
		t=(t1-(q*t2));
		t1=t2;
		t2=t;
	}
	
	if(r1==1)
		return ((t1+26)%26);
return -1;	
}
void encrypt(char str[],int key)
{
	for(int i=0;str[i]!='\0';i++)
	{
		str[i]=(((str[i]-97)*key)%26)+97;
		if(str[i]>122)
			str[i]=96+(str[i]%122);
	}
}
void decrypt(char str[],int key)
{
	int j=0;
	for(int i=0;str[i]!='\0';i++)
	{
		str[i]=(((str[i]-97)*key)%26)+97;
		if(str[i]>122)
			str[i]=96+(str[i]%122);
	}
}
int main()
{
	char str[100];
	int key;
	cout<<"Enter the string:";
	cin>>str;
	cout<<"\nEnter the key:";
	cin>>key;
	encrypt(str,key);
	cout<<"\nAfter Encryption:"<<str<<endl;
	int deckey;
	deckey=gcd(key);
	decrypt(str,deckey);
	cout<<"\nAfter Decryption:"<<str<<endl;
	return 0;
}
