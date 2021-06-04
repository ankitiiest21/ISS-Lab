#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
const int n=26;



void decrypt(char c[100],int l)
{
 FILE *fp=fopen("2B_key.txt","r");
 int key[l],inverseKey[l+1],window[l];
 int i=0,j=0,size=0,k=0;
 for(i=0;i<l;i++)
  fscanf(fp,"%d",&key[i]);
 for(i=1;i<=l;i++)
  inverseKey[key[i-1]]=i;
 i=0;
 char p[100];
 for(i=0;i<strlen(c);i++)
 {
  if(size!=l)
  {
   window[size]=c[i];
   size++;
  }
  else
  {
   for(k=1;k<=l;k++)
    p[j++]=window[inverseKey[k]-1];
   size=0;
   window[size]=c[i];
   size++;
  }
 }
 for(k=1;k<=l;k++)
    p[j++]=window[inverseKey[k]-1];
 p[j]='\0';
 printf("%s\n\n",p);
 fclose(fp);
 return;
}

int main()
{
 char c[100];
 int l;
 printf("\n\n--------------------------------------------------AT BOB'S END---------------------------------------------\n");
 printf("\nEnter the cipher text to be received: ");
 scanf("%[^\n]s",c);
 printf("\n\nEnter the block size of key: ");
 scanf("%d",&l);
 printf("\n\nThe plain text decrypted is: ");
 decrypt(c,l);
 return 0;
}