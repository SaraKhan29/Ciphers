#include<iostream>
using namespace std;
void cipher(char str[],int key)
{
	for(int i=0;str[i]!='\0';i++)
	{
		str[i]=str[i]+key;
		if(str[i]>122)
			str[i]=96+(str[i]%122);
	
	
	}
}
void decipher(char str[],int key)
{
	int x;
	for(int i=0;str[i]!='\0';i++){
		str[i]=str[i]-key;
		if(str[i]<97){
			x=97-str[i];
			str[i]=123-x;	
		}
	
	
	}
}
int main()
{
	char str[100];
	int key;
	cout<<"Enter the Plain text:";
	cin>>str;
	cout<<"\nEnter the key:  (0-25)";
	cin>>key;
	cipher(str,key);
	cout<<"\n AFTER ENCRYPTION:"<<str<<endl;
	decipher(str,key);
	cout<<"\n AFTER DECRYPTION:"<<str<<endl;
	return 0;

}
