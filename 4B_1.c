#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
const int n=26;
int key[100];
char modifiedP[100];

void encrypt(char p[100])
{
 FILE *fp=fopen("4B_key.txt","w");
 int i=0,j=0,s0,a,b;
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]==' ')
   continue;
  else
  {
   modifiedP[j++]=p[i];
  }
 }
 modifiedP[j]='\0';
 printf("\nEnter the seed: ");
 scanf("%d",&s0);
 printf("\nEnter A and B respectively: ");
 scanf("%d %d",&a,&b);
 printf("Generating pseudo random-key stream and saving it in 4B_key.txt...\n");
 for(i=0;modifiedP[i]!='\0';i++)
 {
  if(i==0)
  {
   key[i]=s0;
   fprintf(fp,"%d ",key[i]);
  }
  else
  {
   key[i]=(a*key[i-1]+b%n)%n;
   fprintf(fp,"%d ",key[i]);
  }
 }
 char c[100];
 for(i=0;modifiedP[i]!='\0';i++)
 {
  c[i]=(char)(((int)modifiedP[i]-48)^key[i]+48);
 }
 printf("\n\nThe cipher text to be transmitted is: ");
 c[i]='\0';
 printf("%s\n\n",c);
 fclose(fp);
 return;
}

int main()
{
 char p[100];
 int s0,a,b,i;
 srand(time(0));
 printf("\n\n--------------------------------------ONE TIME PAD WITH GIVEN PRNG FUNCTION--------------------------------\n");
 printf("\n--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("\nEnter the plain-text to be transmitted: ");
 scanf("%[^\n]s",p);
 encrypt(p);
 return 0;
}