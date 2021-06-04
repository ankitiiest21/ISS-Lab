#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
const int n=26;



void decrypt(char c[100])
{
 FILE *fp=fopen("4B_key.txt","r");
 int key[strlen(c)];
 int i=0,j=0;
 for(i=0;i<strlen(c);i++)
  fscanf(fp,"%d",&key[i]);
 i=0;
 char p[100];
 for(i=0;c[i]!='\0';i++)
 {
  p[i]=(char)(((int)c[i])^key[i]);
 }
 p[i]='\0';
 printf("%s\n\n",p);
 fclose(fp);
 return;
}

int main()
{
 char c[100];
 printf("\n\n-----------------------------------------ONE TIME PAD WITH GIVEN PRNG FUNCTION-----------------------------\n");
 printf("\n\n--------------------------------------------------AT BOB'S END---------------------------------------------\n");
 printf("\n\nEnter the cipher text to be received: ");
 scanf("%[^\n]s",c);
 printf("\n\nThe plain text decrypted is: ");
 decrypt(c);
 return 0;
}