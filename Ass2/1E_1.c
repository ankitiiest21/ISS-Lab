#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

const int n=26;
int N,size=0;


int multiplicative_inverse(int k){
    int i=0;
    for(i=0;i<n;i++){
      if((i*k)%n==1){
         return i;
      }
    }
    return -1;
}

int additive_inverse(int k){
    return ((n+k)%n);
}

void fillCofactor(int mat[N][N],int temp[N][N],int r,int c){
	int i=0,j=0,row=0,col=0;
	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			if(row!=r&&col!=c){
				temp[i][j++]=mat[row][col];
				if(j==N-1){
					j=0;
					i++;
				}
			}
		}
	}
}

int findDeterminant(int mat[N][N],int dim){
	int res=0;
	if(dim==1)
	  return mat[0][0];
	int temp[N][N],sign=1,col=0;
	for(col=0;col<dim;col++){
		fillCofactor(mat,temp,0,col);
		res+=sign*mat[0][col]*findDeterminant(temp,dim-1);
		// printf("%d\n",res);
		sign=-sign;
	}
	return res;
}

void fillAdjoint(int mat[N][N],int adj[N][N]){
	if(!N){
		adj[0][0]=1;
		return;
	}
	int sign=1,temp[N][N],i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			fillCofactor(mat,temp,i,j);
			sign=(((i+j)%2)?-1:1);
			adj[j][i]=sign*(findDeterminant(temp,N-1));
		}
	}
}

int findInverse(int mat[N][N],int inv[N][N]){
    int det=findDeterminant(mat,N);
    printf("The determinant of the key matrix is: %d\n",det);
    int detInv=multiplicative_inverse(det);
    int temp;
    if(det==0)
      return 0;
    if(detInv==-1)
    	return -1;
    int adj[N][N],i,j;
    fillAdjoint(mat,adj);
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    		temp=((adj[i][j]%n)*(detInv%n))%n;
    		if(temp<0)
    		  inv[i][j]=additive_inverse(temp);
    		else
    		  inv[i][j]=temp;
    		// printf("%d\n",temp );
    	}
    }
	return 1;
}

void preprocess(char p[500])
{
 int i=0,pf=0,j=0;
 char modifiedP[500];
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]!=' ')
   modifiedP[j++]=p[i];
 }
 modifiedP[j]='\0';
 for(i=0;modifiedP[i]!='\0';i++)
  p[i]=modifiedP[i];
 p[i]='\0';
 size=i;
 if(size%N!=0)
 {
  printf("Adding bogus character(s) to make the matrix multiplication compatible.....\n");
  while(size%N!=0)
   p[i++]='x',size++;
  p[i]='\0';
  printf("The modified plain text is: %s\n",p); 
 }
 else
 {
   printf("No need to add bogus character(s)!!!!\n");
 }
 return;
}

void encrypt(char p[500],int key[N][N])
{
 int inv[N][N],i,j,k;
 int res=findInverse(key,inv);
 char c[500];
//  printf("%s\n",p);
 if(!res)
 {
  printf("Inverse of this singular key matrix doesn't exist!!\n");
  printf("Please enter suitable key matrix!!!\n");
 }
 else if(res==-1)
 {
  printf("Inverse of key matrix is non-existent as multiplicative inverse of its determinant doesn't exist!!");
  printf("Please enter suitable key matrix!!!\n");
 }
 else
 {
  int pmat[size/N][N];
  int cmat[size/N][N];
  for(i=0;i<size;i++)
   pmat[i/size][i%size]=(int)(p[i]-'a'),cmat[i/size][i%size]=0;
  printf("The modified plain text in matrix form is:\n");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
    printf("%d ",pmat[i][j]);
   printf("\n");
  }
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
   {
    for(k=0;k<N;k++)
     cmat[i][j]=(cmat[i][j]+(pmat[i][k]*key[k][j]));
    cmat[i][j]%=n;
   }
  }
  printf("The cipher text to be transmitted in matrix form is:\n");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
    printf("%d ",cmat[i][j]);
   printf("\n");
  }
  printf("Cipher text in string format is: ");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
   {
     c[N*i+j]=(char)((int)cmat[i][j]+65);
   }
  }
  c[size]='\0';
  printf("%s\n",c);
 }
 return;
}

int main()
{
 char p[500];
 printf("--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("Enter the plain-text to be transmitted: ");
 scanf("%[^\n]s",p);
 printf("Enter the dimensions of key matrix: ");
 scanf("%d",&N);
 int key[N][N],i,j;
 printf("Enter the shared secret key: \n");
 for(i=0;i<N;i++)
  for(j=0;j<N;j++)
   scanf("%d",&key[i][j]);
 preprocess(p);
 encrypt(p,key);
 return 0;
}