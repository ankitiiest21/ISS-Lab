#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
const int n=26;

int additive_inverse(int k){
    return ((n-k)%n);
}

void decrypt(char c[100],int l)
{
 FILE *fp=fopen("2A_key.txt","r");
 int key[l];
 int i=0,j=0;
 for(i=0;i<l;i++)
  fscanf(fp,"%d",&key[i]);
 i=0;
 char p[100];
 for(i=0;c[i]!='\0';i++)
 {
   if(islower(c[i]))
    p[i]=(char)(((int)(c[i]-97)+additive_inverse(key[i%l]))%n+65);
   else if(isupper(c[i]))
    p[i]=(char)(((int)(c[i]-65)+additive_inverse(key[i%l]))%n+97);
  }
 p[i]='\0';
 printf("%s",p);
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
 printf("\n\nEnter the size of the key stream: ");
 scanf("%d",&l);
 printf("\n\nThe plain text decrypted is: ");
 decrypt(c,l);
 return 0;
}