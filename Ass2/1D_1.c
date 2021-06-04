#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

const int n=26;
char key[5][5]={{'L','G','D','B','A'},{'Q','M','H','E','C'},{'U','R','N','I','F'},{'X','V','S','O','K'},{'Z','Y','W','T','P'}};


char findBogusCharacter(char currChar)
{
 char ch;
 int curr=(int)(currChar-'a');
 while(curr==(int)(currChar-'a'))
  curr=rand()%26;
 return (char)(curr+97);
}


void encrypt(char p[100])
{
//  srand(time(0));
 int i=0,j=0,k=0,kr1,kc1,kr2,kc2,row,col,flag=0;
 char c[100];
 char modifiedP[200];
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]==' ')
   continue;
  if(i==0)
   modifiedP[j++]=((p[i]=='j')?'i':p[i]);
  else if((p[i]==p[i-1])||(p[i]=='i'&&p[i-1]=='j')||(p[i]=='j'&&p[i-1]=='i'))
  {
   char ch='x';
   modifiedP[j++]=ch;
   modifiedP[j++]=((p[i]=='j')?'i':p[i]);
  }
  else
   modifiedP[j++]=((p[i]=='j')?'i':p[i]);
 }
 if(j%2==1)
 {
  char ch='x';
  modifiedP[j++]=ch;
 }
 modifiedP[j]='\0';
 printf("The modified plain text to be transmitted is: ");
 printf("%s\n",modifiedP);
 j=0;
 for(i=0;modifiedP[i]!='\0';i++)
 {
   flag=0;
   if(i%2==1)
   {
    for(row=0;row<5;row++)
    {
     for(col=0;col<5;col++)
     {
      if(key[row][col]==modifiedP[i]-'a'+'A')
      {
        kr2=row;
        kc2=col;
        flag=1;
        break;
      } 
     }
     if(flag)
       break;
    }
    if(kr1==kr2)
    {
     c[j++]=key[kr1][(kc1+1)%5];
     c[j++]=key[kr2][(kc2+1)%5];
    }
    else if(kc1==kc2)
    {
     c[j++]=key[(kr1+1)%5][kc1];
     c[j++]=key[(kr2+1)%5][kc2];
    }
    else
    {
     c[j++]=key[kr1][kc2];
     c[j++]=key[kr2][kc1];
    }
   }
   else
   {
    for(row=0;row<5;row++)
    {
     for(col=0;col<5;col++)
     {
      if(key[row][col]==modifiedP[i]-'a'+'A')
      {
        kr1=row;
        kc1=col;
        flag=1;
        break;
      } 
     }
     if(flag)
       break;
    }
   }
 }
 c[j]='\0';
 printf("The cipher text to be transmitted is: ");
 printf("%s\n",c);
 return;
}

int main()
{
 char p[100];
 int k;
 printf("--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("Enter the plain-text to be transmitted ([a,z]-{x}): ");
 scanf("%[^\n]s",p);
 encrypt(p);
 return 0;
}