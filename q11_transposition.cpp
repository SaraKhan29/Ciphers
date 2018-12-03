#include<iostream>
using namespace std;
int main(){
	int *k,n,m;
	cout<<"Enter the size of key :";
	cin>>n;
	k=new int[n];
	cout<<"Enter the key"<<endl;
	for(int i=0;i<n;i++)
			cin>>k[i];
	string p;
	char c[100];
	cout<<"Enter the plaintext :";
	cin>>p;
	int len=p.length();
	if(m=len%n)
	{	
		for(int i=1;i<=(n-m);i++)
		{
			p[len+i-1]='z';
		}
	}
	p[len+(n-m)]='\0';
	
	cout<<"\nText after inserting bogus character :"<<p.c_str()<<endl;
	
	char **e,**d;
//	if((n-m)==n)
//		m=len/n;
//	else
//	m=(len+(n-m))/n;
	if((len%n)!=0)
			m=(len/n)+1;
	e=new char*[m];
	for(int i=0;i<m;i++)
		e[i]=new char[n];
	d=new char*[m];
	for(int i=0;i<m;i++){
		d[i]=new char[n];
	}
	
	int y=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			e[i][j]=p[y];
			y++;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			d[i][j]=e[i][k[j]-1];
		}
	}
	
	y=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c[y]=d[j][i];
			y++;
		}
	}
	
	c[y]='\0';
	string cipher=c;
	cout<<"\nEncrypted text :";
	cout<<cipher<<endl;
	p.clear();
	y=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			d[j][i]=c[y];
			y++;
		}
	}
	
	//decryption key
	int *dec;
	dec=new int[n];
	for(int i=0;i<n;i++){
		dec[k[i]-1]=i+1;
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			e[i][j]=d[i][dec[j]-1];
		}
	}
	
	y=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			p[y]=e[i][j];
			y++;
		}
	}
	
	p[y]='\0';
	cout<<"\nDecrypted text :";
	cout<<p.c_str()<<endl;
	return 0;
}
