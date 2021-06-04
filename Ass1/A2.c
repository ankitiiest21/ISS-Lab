#include<stdio.h>
int n=26;

int multiplicative_inverse(int k){
    int i=0;
    for(i=0;i<n;i++){
      if((i*k)%n==1){
         return i;
      }
    }
    return -1;
}

int main(int argc,char *argv[])
{
 int k;
 printf("Enter the number: ");
 scanf("%d",&k);
 int b=multiplicative_inverse(k);
 if(b!=-1)
  printf("Multiplicative Inverse of %d wrt %d is %d\n",k,n,b);
 else
  printf("Multiplicative Inverse of %d wrt %d is not possible!!!\n",k,n);
 return 0;
}