#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
const int n=26;
char modifiedP[100];

void encrypt(char p[100],int l)
{
 FILE *fp=fopen("4A_key.txt","w");
 int i=0,j=0;
 i=0;
 char c[100];
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
 printf("\n\nThe modified plain-text is: %s\n",modifiedP);
 int key[j];
 printf("\nGenerating pseudo random-key stream and saving it in 4A_key.txt...\n");
 for(i=0;i<j;i++)
 {
  key[i]=rand()%2;
  fprintf(fp,"%d ",key[i]);
 }
 j=0;
 for(i=0;modifiedP[i]!='\0';i++)
 {
  c[i]=(char)(((int)modifiedP[i]-48)^key[i]+48);
 }
 printf("\n\nThe cipher text to be transmitted is: ");
 c[i]='\0';
 printf("%s",c);
 fclose(fp);
 return;
}

int main()
{
 char p[100];
 int l,i;
 srand(time(0));
 printf("\n\n--------------------------------------------------ONE TIME PAD---------------------------------------------\n");
 printf("\n\n--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("\n\nEnter the plain-text(binary string) to be transmitted: ");
 scanf("%[^\n]s",p);
 encrypt(p,l);
 return 0;
}