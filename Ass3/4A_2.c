#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
const int n=26;



void decrypt(char c[100])
{
 FILE *fp=fopen("4A_key.txt","r");
 int key[strlen(c)];
 int i=0,j=0;
 for(i=0;i<strlen(c);i++)
  fscanf(fp,"%d",&key[i]);
 i=0;
 char p[100];
 for(i=0;c[i]!='\0';i++)
 {
    p[i]=(char)(((int)c[i]-48)^key[i]+48);
 }
 p[i]='\0';
 printf("%s",p);
 fclose(fp);
 return;
}

int main()
{
 char c[100];
 printf("\n\n--------------------------------------------------ONE TIME PAD---------------------------------------------\n");
 printf("\n\n--------------------------------------------------AT BOB'S END---------------------------------------------\n");
 printf("\nEnter the cipher text(binary string) to be received: ");
 scanf("%[^\n]s",c);
 printf("\n\nThe plain text(binary string) decrypted is: ");
 decrypt(c);
 return 0;
}