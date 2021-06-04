#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
const int n=26;

 int multiplicative_inverse(int k){
    int i=0;
    for(i=0;i<n;i++){
      if((i*k)%n==1){
         return i;
      }
    }
    return -1;
}

void encrypt(char p[100],int k1,int k2)
{
 int i=0,j=0;
 k2=k2%n;
 k1=k1%n;
 char c[100];
 for(i=0;p[i]!='\0';i++){
  if(p[i]==' ')
   continue;
  if(islower(p[i]))
   c[j++]=(char)((int)((p[i]-97)*k1+k2)%n+65);
  else if(isupper(p[i]))
   c[j++]=(char)((int)((p[i]-65)*k1+k2)%n+97);
 }
 c[j]='\0';
 printf("%s",c);
 return;
}

int main()
{
 char p[100];
 int k1,k2;
 printf("--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("Enter the plain-text to be transmitted: ");
 scanf("%[^\n]s",p);
 printf("Enter the shared secret key (k1): ");
 scanf("%d",&k1);
 printf("Enter the shared secret key (k2): ");
 scanf("%d",&k2);
 if(multiplicative_inverse(k1)==-1)
  printf("Warning!!! Please enter appropriate key k1 whose multiplicative inverse is existent!!!!");
 else{
    printf("The cipher text to be transmitted is: ");
    encrypt(p,k1,k2);
 }
 return 0;
}