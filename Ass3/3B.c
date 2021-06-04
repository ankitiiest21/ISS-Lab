#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
const int n=26;
int N,size=0;
int perKey[100];


void decrypt(char c[100],int key[N][N])
{
  int i,j,k;
  char p[500];
  for(i=0;c[i]!='\0';i++)
   size++;
  int pmat[size/N][N];
  int cmat[size/N][N];
  for(i=0;i<size;i++)
  {
   if(isupper(c[i]))
    cmat[i/size][i%size]=(int)(c[i]),pmat[i/size][i%size]=0;
   else
    cmat[i/size][i%size]=(int)(c[i]),pmat[i/size][i%size]=0;
  }
  printf("\n\nThe cipher text in matrix form is:\n");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
    printf("%d ",cmat[i][j]);
   printf("\n");
  }
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
   {
    for(k=0;k<N;k++)
     pmat[i][j]=(pmat[i][j]+(cmat[i][k]*key[k][j]));
   }
  }
  printf("\n\nThe plain text decrypted in matrix form is:\n");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
    printf("%d ",pmat[i][j]);
   printf("\n");
  }
  printf("\n\nPlain text in string format is: ");
  for(i=0;i<size/N;i++)
  {
   for(j=0;j<N;j++)
   {
     p[N*i+j]=(char)(pmat[i][j]);
   }
  }
  p[size]='\0';
  printf("%s\n",p);
  return;
}

int main()
{
 char c[100];
 int i,j;
 printf("\n\n--------------------------------------------------AT BOB'S END---------------------------------------------\n");
 printf("\nEnter the cipher text to be received: ");
 scanf("%[^\n]s",c);
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
    key[j][i]=1;
   else
    key[j][i]=0;
  }
 }
 printf("Key matrix to be used in this case: \n");
 for(i=0;i<N;i++)
 {
  for(j=0;j<N;j++)
   printf("%d ",key[i][j]);
  printf("\n");
 }
 decrypt(c,key);
 return 0;
}