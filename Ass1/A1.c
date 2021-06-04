#include<stdio.h>
int n=26;
int additive_inverse(int k){
    return ((n-k)%n);
}


int main(int argc,char *argv[])
{
 int k;
 printf("Enter the number: ");
 scanf("%d",&k);
 int a=additive_inverse(k);
 printf("Additive Inverse of %d wrt %d is %d\n",k,n,a);
 return 0;
}