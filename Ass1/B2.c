#include<stdio.h>

int findGCDByExtendedEuclideanAlgorithm(int a,int b,int *s,int *t)
{
 if(a<b){
     a=a+b;
     b=a-b;
     a=a-b;
 }
 int a0=a,b0=b,t0=0,s0=1,iter=1;
 int q=a0/b0;
 int r=a0-q*b0;
 while(r>0)
 {
  printf("In Iteration: %d, Quotient: %d and Remainder: %d, x: %d, y: %d\n",iter,q,r,*s,*t);
  int temp=t0-q*(*t);
  t0=*t;
  *t=temp;
  temp=s0-q*(*s);
  s0=*s;
  *s=temp;
  a0=b0;
  b0=r;
  q=a0/b0;
  r=a0-q*b0;
  iter++;
 }
 r=b0;
 return r;
}

int main()
{
 int a,b,s=0,t=1;
 printf("Enter a: ");
 scanf("%d",&a);
 printf("Enter b: ");
 scanf("%d",&b);
 int gcd=findGCDByExtendedEuclideanAlgorithm(a,b,&s,&t);
 printf("GCD(%d,%d) is: %d\n",a,b,gcd);
 if(gcd==1){
     if(a<b){
      a=a+b;
      b=a-b;
      a=a-b;
     }
     if(s<0)
      s+=b;
     if(t<0)
      t+=a;
     printf("%d^(-1) mod %d is: %d\n",a,b,s);
     printf("%d^(-1) mod %d is: %d\n",b,a,t);
 }
 else{
     printf("Modulo multiplicative inverse doesn't exist since GCD!=1\n");
 }
}