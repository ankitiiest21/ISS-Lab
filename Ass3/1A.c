#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
const int n=26;

void encrypt(char p[100],int k1)
{
 int i=0,j=0,flag=1;
 k1=k1%n;
 char c[100];
 for(i=0;p[i]!='\0';i++){
  if(p[i]==' ')
   continue;
  if(flag)
  {
   flag=0;
   if(islower(p[i]))
    c[j++]=(char)((int)(p[i]+k1-97)%n+65);
   else if(isupper(p[i]))
    c[j++]=(char)((int)(p[i]+k1-65)%n+97);
  }
  else
  {
   int ind=i-1;
   while(ind>0&&p[ind]==' ')
    ind--;
   if(islower(p[i]))
    c[j++]=(char)((int)(p[i]+p[ind]-97-97)%n+65);
   else if(isupper(p[i]))
    c[j++]=(char)((int)(p[i]+p[ind]-65-65)%n+97);
  }
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
 printf("Enter the shared secret key (k1): ");
 scanf("%d",&k);
 printf("The cipher text to be transmitted is: ");
 encrypt(p,k);
 return 0;
}