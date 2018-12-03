#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class RabinCipher
{
	private:
		int i,j,len,key,n,p,q,a1,a2,b1,b2,C,P;
	public:
		void rabin_key_generation();
		void rabin_encryption();
	    int multiplicative_inverse(int r1,int r2,int n);
		int chinese_remainder_theorem(int a,int b,int p,int q);
		void rabin_decryption();		
};

void RabinCipher::rabin_key_generation()
{
	cout<<"Enter two Prime Numbers of form 4*k+3";
	cin>>p>>q;
	n=p*q;
	cout<<"Public key   "<<n<<endl;
	
}

void RabinCipher::rabin_encryption()
{
	cout<<"Enter any integer to be encrypted";
	cin>>P;
	C=(P*P)%n;
	cout<<"Encrypted Value=  "<<C<<endl;
	
}
void RabinCipher::rabin_decryption()
{
	int P1,P2,P3,P4;
	int temp1,temp2,temp3;
	temp1=C % p;
	temp2=(p+1)/4;
	temp3=pow(temp1,temp2);
	a1=+(temp3 % p);
	a2=-(temp3 % p);
	a2=a2+p;
	
	temp1=C%q;
	temp2=(q+1)/4;
	temp3=pow(temp1,temp2);
	b1=+(temp3 % q);
	b2=-(temp3 % q);
	b2=b2+q;
	P1=chinese_remainder_theorem(a1,b1,p,q);
	P2=chinese_remainder_theorem(a1,b2,p,q);
	P3=chinese_remainder_theorem(a2,b1,p,q);
	P4=chinese_remainder_theorem(a2,b2,p,q);
	P1=P1 % n;
	P2=P2 % n;
	P3=P3 % n;
	P4=P4 % n;
	cout<<" Four possible Decrypted Numbers are  "<<P1<<"   "<<P2<<"   "<<P3<<"   "<<P4;
}
int RabinCipher::multiplicative_inverse(int r1,int r2,int n)
{
	int r,q,t1,t2,t;
	t1=0;
	t2=1;

	while(r2>0)
    {
      q=r1/r2;

     r=r1-q*r2;
     r1=r2;
     r2=r;

     t=t1-q*t2;
     t1=t2;
     t2=t;
   } 
	if(t1<0){t1=t1+n;}
    t1=t1 % n;
	return t1;
}
int RabinCipher::chinese_remainder_theorem(int a,int b,int p,int q)
{
	int M,M1,M2,y1,y2,X;
	M=p*q;
	M1=M/p;
	M2=M/q;
	//cout<<"value of M M1 M2 "<<M<<"   "<<M1<<"    "<<M2<<endl;
	y1=multiplicative_inverse(p,M1,p);
	y2=multiplicative_inverse(q,M2,q);
	//cout<<"value of y1 y2"<<y1<<"   "<<y2<<endl;
	X=a*M1*y1+b*M2*y2;
	return X;
	
}
int main()
{
	RabinCipher b;
	b.rabin_key_generation();
	b.rabin_encryption();
	b.rabin_decryption();
	return 0;
}

