//testing 
//0 1 1 1 0 0     1 0 1 0 1 0        1 1 0 0 0 1
#include<iostream>
#include<cmath>
using namespace std;
void bin(int);
bool mult();
void transpose(int**);
void weight();
int size,rows,cols;
int *v,**h,**ht;
/**************************************************************************************************/
int **valid_codes,vcount=1;
int **error_codes,ecount=0;
int* add_XOR(int *a,int*b){
	int* c=new int[size];
	for(int i=0;i<size;i++)
		c[i]=a[i]+b[i];
	for(int i=0;i<size;i++)
		c[i]=c[i]%2;
	return c;
}
/**************************************************************************************************/
int main(){
	int i,j,z;
	cout<<"Enter the size of H matrix:";
	cin>>rows>>cols;
	h=new int*[rows];
	for(i=0;i<rows;i++)
		h[i]=new int[cols];
	cout<<"Enter array elements : \n";	
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++)
			cin>>h[i][j];
	}
	size=cols;
	
	v=new int[size];
//	i=pow(2,rows);
	valid_codes=new int*[i];
	//i=pow(2,cols-rows);
	//error_codes=new int*[i];
	j=pow(2,rows);
	for(i=0;i<j;i++)
		valid_codes[i]=new int[size];
//	j=pow(2,cols-rows);
//	for(i=0;i<j;i++)
//		error_codes[i]=new int[size];
/**************************************************************************************************/
	int temp=pow(2,size)-pow(2,rows);		
	error_codes=new int*[temp];
	for(i=0;i<temp;i++)
		error_codes[i]=new int[size];	
	temp=pow(2,size-rows);	
		
		
/**************************************************************************************************/
	transpose(h);
//	cout<<"valid codes :\n";
	for(i=0;i<size;i++)
		valid_codes[0][i]=0;

	z=pow(2,size);
	for(i=1;i<z;i++){
		bin(i);
		if(mult()){
			for(int count=0;count<size;count++)
				valid_codes[vcount][count]=v[count];
			vcount++;
		}
		else{
			for(int count=0;count<size;count++)
				error_codes[ecount][count]=v[count];
			ecount++;
		}
		
	}
/**************************************************************************************************/
cout<<"\n\n*************************************VALID CODES*************************************\n";
/**************************************************************************************************/
	for(i=0;i<vcount;i++){
		for(j=0;j<size;j++)
			cout<<valid_codes[i][j];
		cout<<"\n";
	}
cout<<"************************************************************************************************";	
	
/**************************************************************************************************/
cout<<"\n\n\n*************************************STANDARD ARRAY*************************************\n";
/**************************************************************************************************/
	int *new_array=new int[size];
	for(i=0;i<vcount;i++){
		for(j=0;j<size;j++)
			cout<<valid_codes[i][j];
		cout<<"\t";
	}
	cout<<"\n";
	for(i=0;i<temp;i++){
		for(int k=0;k<size;k++)
			cout<<error_codes[i][k];
		cout<<"\t";
		for(j=1;j<vcount;j++){
			new_array=add_XOR(error_codes[i],valid_codes[j]);
			for(int count=0;count<size;count++)
				cout<<new_array[count];
			cout<<"\t";
		}
		cout<<"\n";
	}
cout<<"************************************************************************************************";	

cout<<"\n\n\n*************************************SYNDROMES*************************************\n";
/**************************************************************************************************/
	for(int count=0;count<temp;count++){
		int *x;
		x=new int[cols];
		for(i=0;i<cols;i++)
			x[i]=0;
		for(i=0;i<cols;i++){
			for(j=0;j<rows;j++){
				x[i]+=error_codes[count][j]*ht[j][i];
			}
		}
		for(int k=0;k<cols;k++)
			cout<<x[k];
		cout<<"\n";
	}
cout<<"************************************************************************************************";

}
void bin(int n){
	int i;
	for(i=size-1;i>-1;i--){
		v[i]=n%2;
		n=n/2;
	}
}
void transpose(int** h){
	int i,j,temp;
	ht=new int*[cols];
	for(i=0;i<cols;i++)
		ht[i]=new int[rows];
	for(i=0;i<cols;i++){
		for(j=0;j<rows;j++){
			ht[i][j]=h[j][i];
		}
	}
	i=rows;
	rows=cols;
	cols=i;
}
bool mult(){
	int *x,i,j,k;
	x=new int[cols];
	for(i=0;i<cols;i++)
		x[i]=0;
	for(i=0;i<cols;i++){
		for(j=0;j<rows;j++){
			x[i]+=v[j]*ht[j][i];
		}
	}
	
	for(i=0;i<cols;i++){
		if(x[i]%2!=0){
			//cout<<"f ";
			return false;
		}
	}
	cout<<"\t";
	return true;
}
void weight(){
	int i,j=0;
	for(i=0;i<size;i++){
		if(v[i]==1)
			j++;
	}

}
