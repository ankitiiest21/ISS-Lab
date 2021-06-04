#include<stdio.h>

int findGCDByEuclideanAlgorithm(int a,int b){
    int q,r,iter=1;
    if(a<b){
        a=a+b;
        b=a-b;
        a=a-b;
    }
    while(b>0){
        q=a/b;
        r=a-q*b;
        printf("In Iteration: %d, Quotient: %d and Remainder: %d\n",iter,q,r);
        a=b;
        b=r;
        iter++;
    }
    return a;
}

int main()
{
 int a,b;
 printf("Enter a: ");
 scanf("%d",&a);
 printf("Enter b: ");
 scanf("%d",&b);
 int gcd=findGCDByEuclideanAlgorithm(a,b);
 printf("The GCD of (%d,%d) is: %d ",a,b,gcd);
 return 0;
}