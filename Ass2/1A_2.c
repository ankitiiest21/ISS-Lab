#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
const int n=26;

int additive_inverse(int k){
    return ((n-(k%n))%n);
}

void decrypt(char c[100],int k)
{
 int i=0;
 
 char p[100];
 for(i=0;c[i]!='\0';i++){
  if(islower(c[i]))
   p[i]=(char)(((int)(c[i]-97)+additive_inverse(k))%n+65);
  else if(isupper(c[i]))
   p[i]=(char)(((int)(c[i]-65)+additive_inverse(k))%n+97);
  else
   p[i]=c[i];
 }
 p[i]='\0';
 printf("%s",p);
 return;
}

int main()
{
 char c[100];
 int k;
 printf("--------------------------------------------------AT BOB'S END---------------------------------------------\n");
 printf("Enter the cipher text to be received: ");
 scanf("%[^\n]s",c);
 printf("Enter the shared secret key: ");
 scanf("%d",&k);
 printf("The plain text decrypted is: ");
 decrypt(c,k);
 return 0;
}