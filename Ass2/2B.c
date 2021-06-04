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

void bruteForceAttack(char c[100])
{
 int key=0,i,j;
 char p[100];
 for(key=0;key<n;key++)
 {
  int keyInv=multiplicative_inverse(key);
  if(keyInv==-1)
  {
   printf("<----------For key = %d--------->\n",key);
   printf("Key = %d is not in Z* \n\n\n",key);
  }
  else
  {
    for(j=0;c[j]!='\0';j++)
    {
    p[j]=(char)(((int)(c[j]-'A')*keyInv)%n+97);
    }
    printf("<----------For key = %d--------->\n",key);
    printf("Plain-text decrypted is: %s\n\n\n",p);
  }
 }
 return;
}


int main()
{
 char c[100];
 printf("--------------------------------------------------AT EVE'S END-------------------------------------------\n");
 printf("Enter the cipher-text which is intercepted: ");
 scanf("%[^\n]s",c);
 bruteForceAttack(c);
 return 0;
}