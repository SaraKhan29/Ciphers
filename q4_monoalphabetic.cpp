#include<iostream>
#include<conio.h>
using namespace std;
void cipher(char* text,char* key)
{
	int j;
	for(int i=0;text[i]!='\0';i++)
	{
		if(text[i]>='a'&&text[i]<='z')
		{
			j=text[i]-97;
			text[i]=key[j];
		}
	}
}
void decipher(char* text,char* key)
{
	for(int i=0;text[i]!='\0';i++)
	{
		if(text[i]>='a'&&text[i]<='z')
		{
			for(int j=0;j<26;j++)
			{
		    	if(text[i]==key[j])
		    	{
		    		text[i]=j+97;
		    		break;
				}
			}
		}
	}

}
int main()
{
	char key[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	char text[200];
	int j;
	cout<<"Enter the text\n";
	gets(text);
	
	cipher(text,key);
	
	cout<<"\nEncrypted message is\n";
	puts(text);
	
	decipher(text,key);
	
	cout<<"\nDecrypted message is\n";
	puts(text);
	
	return 0;	
}

