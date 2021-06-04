#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
const int n=26;
char key[5][5]={{'L','G','D','B','A'},{'Q','M','H','E','C'},{'U','R','N','I','F'},{'X','V','S','O','K'},{'Z','Y','W','T','P'}};

void decrypt(char c[100])
{
 int i=0,j=0,k=0,kr1,kc1,kr2,kc2,row,col,flag=0;
 char p[100];
 for(i=0;c[i]!='\0';i++)
 {
   flag=0;
   if(i%2==1)
   {
    for(row=0;row<5;row++)
    {
     for(col=0;col<5;col++)
     {
      if(key[row][col]==c[i])
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
     p[j++]=key[kr1][(kc1-1+5)%5]-'A'+'a';
     p[j++]=key[kr2][(kc2-1+5)%5]-'A'+'a';
    }
    else if(kc1==kc2)
    {
     p[j++]=key[(kr1-1+5)%5][kc1]-'A'+'a';
     p[j++]=key[(kr2-1+5)%5][kc2]-'A'+'a';
    }
    else
    {
     p[j++]=key[kr1][kc2]-'A'+'a';
     p[j++]=key[kr2][kc1]-'A'+'a';
    }
   }
   else
   {
    for(row=0;row<5;row++)
    {
     for(col=0;col<5;col++)
     {
      if(key[row][col]==c[i])
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
 p[j]='\0';
 printf("%s\n",p);
 return;
}

int main()
{
 char c[100];
 printf("--------------------------------------------------AT BOB'S END---------------------------------------------\n");
 printf("Enter the cipher text to be received: ");
 scanf("%[^\n]s",c);
 printf("The plain text decrypted is: ");
 decrypt(c);
 return 0;
}