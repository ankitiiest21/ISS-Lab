#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

const int n=26;
int N,size=0;
int perKey[100];
char modifiedP[100];


void preprocess(char p[500])
{
 int i=0,pf=0,j=0;
 size=0;
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]!=' ')
   modifiedP[j++]=p[i],size++;
 }
 modifiedP[j]='\0';
 if(strlen(modifiedP)%N!=0)
 {
  printf("\n\nAdding bogus character(s) to make the matrix multiplication compatible.....\n");
  while(size%N!=0)
   modifiedP[size]='x',size++;
  modifiedP[size]='\0';
  printf("The modified plain text is: %s\n",modifiedP); 
 }
 else
 {
   printf("\n\nNo need to add bogus character(s)!!!!!!!!!!!\n");
   printf("The modified plain text is: %s\n",modifiedP);
 }
 return;
}

void encrypt(int key[N][N])
{
  int i,j,k;
  char c[500];
  int pmat[size/N][N];
  int cmat[size/N][N];
  for(i=0;i<size;i++)
  {
   if(isupper(modifiedP[i]))
    pmat[i/size][i%size]=(int)(modifiedP[i]),cmat[i/size][i%size]=0;
   else
    pmat[i/size][i%size]=(int)(modifiedP[i]),cmat[i/size][i%size]=0;
  }

  printf("\n\nThe modified plain text in matrix form is:\n");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
    printf("%d ",pmat[i][j]);
   printf("\n");
  }
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
   {
    for(k=0;k<N;k++)
     cmat[i][j]=(cmat[i][j]+(pmat[i][k]*key[k][j]));
   }
  }
  printf("\n\nThe cipher text to be transmitted in matrix form is:\n");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
    printf("%d ",cmat[i][j]);
   printf("\n");
  }
  printf("\n\n\nCipher text in string format is: ");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
   {
    c[N*i+j]=(char)(cmat[i][j]);
   }
  }
  c[size]='\0';
  printf("%s\n",c);
  return;
}

int main()
{
 char p[500];
 int i,j;
 printf("\n\n--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("\nEnter the plain-text to be transmitted: ");
 scanf("%[^\n]s",p);
 printf("\nEnter the key size: ");
 scanf("%d",&N);
 printf("\nEnter the permutation key: ");
 for(i=0;i<N;i++)
  scanf("%d",&perKey[i]);
 int key[N][N];
 for(j=0;j<N;j++)
 {
  for(i=0;i<N;i++)
  {
   if(i==perKey[j]-1)
    key[i][j]=1;
   else
    key[i][j]=0;
  }
 }
 printf("\n\nKey matrix to be used in this case: \n");
 for(i=0;i<N;i++)
 {
  for(j=0;j<N;j++)
   printf("%d ",key[i][j]);
  printf("\n");
 }
  
 preprocess(p);
 encrypt(key);
 return 0;
}