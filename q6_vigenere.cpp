#include<iostream>
#include<string>
using namespace std;
string encrypt(string str,string key){
	int i,x;
	for(i=0;str[i]!='\0';i++){
		x=((str[i]-97)+(key[i]-97))%26;
		str[i]=97+x;
	}
	return str;
}
string decrypt(string str,string key){
	int i,x;
	for(i=0;str[i]!='\0';i++){
		x=str[i]-key[i];
		if(x<0){
			x=0-x;
			str[i]=123-x;
		}
		else{
			str[i]=97+x;
		}
	}
	return str;
}
int main()
{
	
	string str,key;
	cout<<"Enter text:";
	cin>>str;
	cout<<"Enter key:";
	cin>>key;
	for(;str.length()>key.length();key.append(key)){
	}
	str=encrypt(str,key);
	cout<<"\nAfter Encryption:"<<str<<endl;
	str=decrypt(str,key);
	cout<<"\nAfter Decryption:"<<str<<endl;
	return 0;
}
