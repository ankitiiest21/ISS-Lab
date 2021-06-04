#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
const int n=26;
int key[100];
char p[100];
char c[100];
char modifiedP[100];

int multiplicative_inverse(int k){
    int i=0;
    for(i=0;i<n;i++){
      if((i*k)%n==1){
         return i;
      }
    }
    return -1;
}


void startCryptanalysis()
{
 int i=0,j=0,s0,a,b,s1,s2;
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]==' ')
   continue;
  else
   modifiedP[j++]=p[i];
 }
 modifiedP[j]='\0';
 s0=(int)(c[0]^modifiedP[0]);
 s1=(int)(c[1]^modifiedP[1]);
 s2=(int)(c[2]^modifiedP[2]);
 int temp=multiplicative_inverse(s1-s0);
 if(temp==-1)
  printf("\n\nCryptanalysis can't be performed as a can't be found!!!!\n\n");
 else
 {
  a=(temp%n)*((s2-s1+n)%n)%n;
  b=s1-(a*s0)%n;
  printf("\n\n-------------------------------Result of Cryptanalysis-----------------------------\n");
  printf("s0(seed): %d\n",s0);
  printf("a: %d\n",a);
  printf("b: %d\n\n",b);
  for(i=0;i<strlen(c);i++)
  {
   if(i==0)
    key[i]=s0;
   else
    key[i]=(a*key[i-1]+b%n)%n;
  }
  printf("\n\nThe key stream is: ");
  for(i=0;i<strlen(c);i++)
   printf("%d ",key[i]);
  printf("\n");
 }
}


int main()
{
 printf("\n\n--------------------------------------ONE TIME PAD WITH GIVEN PRNG FUNCTION--------------------------------\n");
 printf("\n-------------------------------------------AT EVE'S(ADVERSARY) END-------------------------------------------\n");
 printf("\nEnter the cipher text intercepted: ");
 scanf("%[^\n]s",c);
 fflush(stdin);
 printf("\nEnter atmost 15 bits of the intercepted plain text: ");
 scanf("%[^\n]s",p);
 startCryptanalysis();
 return 0;
}