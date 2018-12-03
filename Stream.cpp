#include<iostream>
#include<cctype>
#include<cmath>
#include<cstring>
#include<stdlib.h>
using namespace std;

char plaintext[100],ciphertext[100],key[100];
int len,i,k,d;

int main(){
	cout<<"Enter Text : "<<endl;
	cin>>plaintext;
	len=strlen(plaintext);

    
	for(k=0;k<=len-1;k++)
	{
		d=rand()%2;
		key[k]=d;
		ciphertext[k]=plaintext[k]^key[k];
	}

	cout<<"Encrypted Text : "<<ciphertext<<endl;

	for(i=0;i<=len-1;++i)
	{
		plaintext[i]=ciphertext[i]^key[i];
	}

	cout<<"Decrypted  Text : "<<plaintext<<endl;
}
