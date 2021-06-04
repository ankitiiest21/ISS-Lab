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
char favourableP[100];

int additive_inverse(int k)
{
  int temp=n;
  while(temp>=k)
   temp+=n;
  return ((temp-k)%n);
}


int multiplicative_inverse(int k)
{
  int i=0;
  for(i=0;i<n;i++){
    if((i*k)%n==1){
        return i;
    }
  }
  return -1;
}

int binaryToDecimal(int l,int r)
{
 int dec=0,temp=1,i;
 for(i=r;i>=l;i--)
 {
  dec+=key[i]*temp;
  temp*=2;
 }
 return dec;
}

void startCryptanalysis()
{
 int i=0,j=0,s0,a,b,s1,s2;
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]==' ')
   continue;
  else if(j==15)
   break;
  else
   favourableP[j++]=p[i];
 }
 favourableP[j]='\0';
 for(i=0;i<strlen(favourableP);i++)
  key[i]=((int)(favourableP[i])-48)^((int)c[i]-48);
 s0=binaryToDecimal(0,4);
 s1=binaryToDecimal(5,9);
 s2=binaryToDecimal(10,14);
 int mulInv=multiplicative_inverse(s1+additive_inverse(s0));
 if(mulInv==-1)
  printf("\n\n Cryptanalysis can't be done as the multiplicative inverse of (s1-s0) can't be found!!!!");
 else
 {
  a=((mulInv%n)*((s2+additive_inverse(s1))%n))%n;
  b=((mulInv%n)*(((s1*s1+additive_inverse(s0*s2))%n)%n))%n;
  printf("\n\n***********Cryptanalysis is successful with the following results*************");
  printf("\nS0 is: %d",s0);
  printf("\na is: %d",a);
  printf("\nb is: %d",b);
 }
}


int main()
{
 printf("\n\n--------------------------------------ONE TIME PAD WITH GIVEN PRNG FUNCTION--------------------------------\n");
 printf("\n-------------------------------------------AT EVE'S(ADVERSARY) END-------------------------------------------\n");
 printf("\nEnter the atleast 15 bits of intercepted cipher text: ");
 scanf("%[^\n]s",c);
 fflush(stdin);
 printf("\nEnter the 15 bits of the intercepted plain text: ");
 scanf("%[^\n]s",p);
 if(strlen(c)<15||strlen(p)<15)
 {
  printf("\n\nWarning, Please enter the appropriate number of bits as required!!!!!!");
 }
 else
 {
  startCryptanalysis();
 }
 return 0;
}