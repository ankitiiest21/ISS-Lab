#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
const int n=26;

int additive_inverse(int k)
{
 return ((n-k)%n);
}


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
 int k1=0,i,j,k2=0;
 char p[100];
 char ch[100];
 int flag=1;
 for(k1=0;k1<n&&flag==1;k1++)
 {
  int k1Inv=multiplicative_inverse(k1);
  printf("Enter YES to proceed further, else N0:");
  scanf("%s",ch);
  if(strcmp(ch,"NO")==0)
   break;
  if(k1Inv==-1)
  {
   printf("<----------For k1 = %d--------->\n",k1);
   printf("k1 = %d is not in Z*, so not searching for all domain of k2 for it!!!!\n\n\n",k1);
  }
  else
  {
    for(k2=0;k2<n;k2++)
    {
     int k2Inv=additive_inverse(k2);
     for(j=0;c[j]!='\0';j++)
     {
       p[j]=(char)(((((int)(c[j]-'A')+k2Inv)%n)*k1Inv)%n+97);
     }
     printf("<----------For k1 = %d , k2 = %d--------->\n",k1,k2);
     printf("Plain-text decrypted is: %s\n\n\n",p);
    }
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