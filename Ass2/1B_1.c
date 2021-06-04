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

void encrypt(char p[100],int k)
{
 int i=0,j=0;
 k=k%n;
 char c[100];
 for(i=0;p[i]!='\0';i++){
  if(p[i]==' ')
   continue;
  if(islower(p[i]))
   c[j++]=(char)((int)((p[i]-97)*k)%n+65);
  else if(isupper(p[i]))
   c[j++]=(char)((int)((p[i]-65)*k)%n+97);
 }
 c[j]='\0';
 printf("%s",c);
 return;
}

int main()
{
 char p[100];
 int k;
 printf("--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("Enter the plain-text to be transmitted: ");
 scanf("%[^\n]s",p);
 printf("Enter the shared secret key: ");
 scanf("%d",&k);
 if(multiplicative_inverse(k)==-1)
  printf("Warning!!! Please enter appropriate key whose multiplicative inverse is existent!!!!");
 else{
    printf("The cipher text to be transmitted is: ");
    encrypt(p,k);
 }
 return 0;
}