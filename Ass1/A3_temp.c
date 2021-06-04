#include<stdio.h>
int N,n=26;

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
    return ((n-(k%n))%n);
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
    printf("The determinant of the matrix is: %d\n",det);
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
    		temp=(adj[i][j]*detInv);
    		inv[i][j]=additive_inverse(temp);
    		// printf("%d\n",temp );
    	}
    }
	return 1;
}



int main()
{
 printf("Enter the dimension of the matrix: ");
 scanf("%d",&N);
 int mat[N][N],i,j;
 int inv[N][N];
 printf("Enter the elements of the matrix:\n");
 for(i=0;i<N;i++){
 	for(j=0;j<N;j++){
 		scanf("%d",&mat[i][j]);
 	}
 }
 int res=findInverse(mat,inv);
 if(!res)
 	printf("Inverse of this singular matrix doesn't exist!!");
 else if(res==-1)
 	printf("Inverse of matrix is non-existent as multiplicative inverse of determinant doesn't exist!!");
 else{
   printf("The inverse of the matrix is:\n");
   for(i=0;i<N;i++){
   	for(j=0;j<N;j++){
   		printf("%d ",inv[i][j]);
   	}
   	printf("\n");
   }
 }
 return 0;
}