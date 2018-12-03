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
void encrypt(char str[],int k1,int k2)
{
	for(int i=0;str[i]!='\0';i++)
	{
		str[i]=((((str[i]-97)*k1)+k2)%26)+97;
		if(str[i]>122)
			str[i]=96+(str[i]%122);
	}
}
void decrypt(char str[],int k1,int k2)
{
	int c;
	for(int i=0;str[i]!='\0';i++)
	{
		c=(int)(((str[i]-97)-k2)%26);
	if(c<0)
		c=((c+26)%26);
	c=((c*k1)%26);
	str[i]=(char)(c+97);
	}
}
int main()
{
	char str[100];
	int k1,k2;
	cout<<"Enter the string:";
	cin>>str;
	cout<<"\nEnter the keys:";
	cin>>k1>>k2;
	encrypt(str,k1,k2);
	cout<<"\nThe encrypted string is:"<<str<<endl;
	int dk1=gcd(k1);
	decrypt(str,dk1,k2);
	cout<<"\nThe decrypted string is:"<<str<<endl;
	return 0;
}
