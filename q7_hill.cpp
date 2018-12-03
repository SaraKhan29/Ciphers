//for testing use key matrix 4 1 19 1
//invrse matrix 19 7 3 24

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


int d=0,d2=0,i,j,n=3;
int temp[3][3],tmp[3][3];
void determinant(int k_mat[3][3])
{
   temp[0][0]=k_mat[1][1]*k_mat[2][2]-k_mat[2][1]*k_mat[1][2];
   temp[0][1]=k_mat[1][0]*k_mat[2][2]-k_mat[2][0]*k_mat[1][2];
   temp[0][2]=k_mat[1][0]*k_mat[2][1]-k_mat[2][0]*k_mat[1][1];
   d=(k_mat[0][0]*temp[0][0]-k_mat[0][1]*temp[0][1]+k_mat[0][2]*temp[0][2]);
  // cout<<"det before mod"<<d<<endl;
   if(d==0){
   	cout<<"Singular matrix cannot apply Hill Cipher "<<endl;
   	return;
   }
   if(d<0)
   {
   	d=-(d);
   	d=d%26;
   	d=26-d;
   }
   else
   {
      d=d%26;
  }
   
   //cout<<"determinant= "<<d<<endl;
}

void determinant_inverse()
{
int r1,r2,t1,t2,q,r,t;
 r1=26;
 r2=d;
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
   if(r1==1) d2=t1;
   if(d2<0){ d2=d2+26; }
   //std::cout<<"inverse determinant=   "<<d2<<endl;
 
}

void find_cofactor_matrix(int k_mat[3][3])
{
   temp[0][0]=(k_mat[1][1]*k_mat[2][2]-k_mat[2][1]*k_mat[1][2]);
   temp[0][1]=-(k_mat[1][0]*k_mat[2][2]-k_mat[2][0]*k_mat[1][2]);
   temp[0][2]=(k_mat[1][0]*k_mat[2][1]-k_mat[2][0]*k_mat[1][1]);
   temp[1][0]=-(k_mat[0][1]*k_mat[2][2]-k_mat[2][1]*k_mat[0][2]);
   temp[1][1]=((k_mat[0][0]*k_mat[2][2])-(k_mat[2][0]*k_mat[0][2]));
   //cout<<(int)temp[1][1]<<(int)k_mat[0][0]<<(int)k_mat[2][2]<<(int)k_mat[2][0]<<(int)k_mat[0][2];
   temp[1][2]=-(k_mat[0][0]*k_mat[2][1]-k_mat[2][0]*k_mat[0][1]);
   temp[2][0]=(k_mat[0][1]*k_mat[1][2]-k_mat[1][1]*k_mat[0][2]);
   temp[2][1]=-(k_mat[0][0]*k_mat[1][2]-k_mat[1][0]*k_mat[0][2]);
   temp[2][2]=(k_mat[0][0]*k_mat[1][1]-k_mat[1][0]*k_mat[0][1]);
 
}


void find_transpose()
{
	int i,j;

   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) {
         tmp[i][j] = temp[j][i];
      }
   }
   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) {
         temp[i][j] = tmp[i][j];
      }
   }
   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) 
	  {
         if(temp[i][j]<0)
         {
         	temp[i][j]=-(temp[i][j]);
         	temp[i][j]=temp[i][j]%26;
         	temp[i][j]=26-temp[i][j];
		 }
		 else
		 {
		 	temp[i][j]=temp[i][j]%26;
		 }
      }
   }
  
  
}



void inverse(int key[][3])
{
	determinant(key);
    determinant_inverse();
    find_cofactor_matrix(key);
    find_transpose();
}







int main()
{
	int x;
	string str;
	cout<<"Enter the string of length >=7"<<endl;
	cin>>str;
	int k=str.length();
//	int n;
//	cout<<"Enter the no of columns in the key matrix"<<endl;
//	n=3;
	int key[3][3]={2,3,7,5,7,9,1,2,11};
	
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			key[i][j]=0;
		}
	}
	*/

bool bogus=0;
	int l;
	if(k%n==0)
		l=k/n;
	else
	{
		l=(k/n)+1;
		bogus=1;
	//	int h=n-(k%n);
	}
		
	int plain[l][n];
	
	int count=0;
//	cout<<k<<l<<endl;
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(count==k)
						break;
			x=str[count];
			plain[i][j]=x-97;
			//cout<<plain[i][j]<<" ";
			count++;
		}
	}
		
	
	if(bogus==1)
	{
		for(int j=(k%n);j<n;j++)
		{	
			plain[l-1][j]=('x'-97);
		}	
	}	
		
		/*	for(int i=0;i<l;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<plain[i][j]<<" ";
				}
			cout<<endl;	
			}*/
	
		
/*	cout<<"Enter the key(The key matrix should be 3*3 and its determinant should not be 0)"<<endl;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>key[i][j];
			}
		}	
	*/
	
	
		int cipher[l][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cipher[i][j]=0;
			
		
		int u,sum=0;
		//matrix mult	
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<n;j++)
			{
				sum=0,u=0;
				for(int k=0;k<n;k++)
				{
					u=plain[i][k]*key[k][j];
					//cout<<u<<" ";
					u=u%26;
					//cout<<u<<endl;
					sum+=u;
					sum=sum%26;
					cipher[i][j]=sum;
				}
			}
		}
		
		cout<<"Text after encryption"<<endl;
		for(int i=0;i<l;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<char(cipher[i][j]+97)<<" ";
				}
				cout<<endl;	
			}
		//int keyinv[3][3];
			inverse(key);
		//cout<<"\nEnter the inverse matrix in mod26"<<endl;
		//for(int i=0;i<n;i++)
		//	for(int j=0;j<n;j++)
		//				cin>>keyinv[i][j];
					
				
			//matrix mult
			int dec[l][n];	
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<n;j++)
			{	
				sum=0,u=0;
				for(int k=0;k<n;k++)
				{
					
					u=cipher[i][k]*temp[k][j];
				//	cout<<cipher[i][k]<<" "<<key[k][j]<<" "<<u<<endl;
					sum+=u;
					sum=sum%26;
					dec[i][j]=sum;
				
				}
				
			}
		}
		
		cout<<"\nText after decryption"<<endl;
		for(int i=0;i<l;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<char(dec[i][j]+97)<<" ";
				}	
				cout<<endl;
			}
			
	

	return 0;
}
