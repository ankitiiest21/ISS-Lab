#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
const int n=26;
char modifiedP[100];
int key[100];

int getNumByFisherYatesShuffle(int n)
{
 srand(time(NULL));
 int ind=rand()%n;
 int num=key[ind];
 key[ind]=key[ind]+key[n-1];
 key[n-1]=key[ind]-key[n-1];
 key[ind]=key[ind]-key[n-1];
 return num;
}

void generatePseudoRandomKeys(int l)
{
 FILE *fp=fopen("2B_key.txt","w");
 int i=0;
 for(i=0;i<l;i++)
  key[i]=i+1;
 for(i=l;i>0;i--)
  key[i-1]=getNumByFisherYatesShuffle(i);
 for(i=0;i<l;i++)
  fprintf(fp,"%d ",key[i]);
 fclose(fp);
}

void preprocess(char p[100],int l)
{
 int i,j=0;
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]==' ')
   continue;
  else 
   modifiedP[j++]=p[i];
 }
 modifiedP[j]='\0';
 if(strlen(modifiedP)%l!=0)
 {
  printf("\n\nInserting bogus character(s) to divide the plain-text into blocks of appropriate size..\n");
  while(strlen(modifiedP)%l!=0)
   modifiedP[strlen(modifiedP)]='x';
  modifiedP[strlen(modifiedP)]='\0';
  printf("\n\nThe modified plain-text is: %s\n",modifiedP);
 }
 return;
}

void encrypt(int l)
{
 int i=0,j=0,k=0;
 i=0;
 char c[100];
 char window[l];
 int size=0;
 for(i=0;i<strlen(modifiedP);i++)
 {
  if(size!=l)
  {
   window[size]=modifiedP[i];
   size++;
  }
  else
  {
   for(k=0;k<l;k++)
    c[j++]=window[key[k]-1];
   size=0;
   window[size]=modifiedP[i];
   size++;
  }
 }
 for(k=0;k<l;k++)
    c[j++]=window[key[k]-1];
 c[j]='\0';
 printf("%s\n\n",c);
 return;
}

int main()
{
 char p[100];
 int l,i;
 printf("\n\n--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("\nEnter the plain-text to be transmitted: ");
 scanf("%[^\n]s",p);
 printf("\n\nEnter the block size of key: ");
 scanf("%d",&l);
 int key[l];
 preprocess(p,l);
 printf("\n\nGenerating pseudo random-key stream and saving it in 2B_key.txt...\n");
 generatePseudoRandomKeys(l);
 printf("\n\nThe cipher text to be transmitted is: ");
 encrypt(l);
 return 0;
}