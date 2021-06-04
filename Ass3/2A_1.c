#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
const int n=26;

void encrypt(char p[100],int l)
{
 FILE *fp=fopen("2A_key.txt","r");
 int key[l];
 int i=0,j=0;
 for(i=0;i<l;i++)
  fscanf(fp,"%d",&key[i]);
 i=0;
 char c[100];
 for(i=0;p[i]!='\0';i++)
 {
  if(p[i]==' ')
   continue;
  else
  {
   if(islower(p[i]))
    c[j]=(char)((int)(p[i]+key[j%l]-97)%n+65),j++;
   else if(isupper(p[i]))
    c[j]=(char)((int)(p[i]+key[j%l]-65)%n+97),j++;
  }
 }
 c[j]='\0';
 printf("%s",c);
 fclose(fp);
 return;
}

int main()
{
 char p[100];
 int l,i;
 srand(time(0));
 FILE *fp;
 fp=fopen("2A_key.txt","w");
 printf("\n\n--------------------------------------------------AT ALICE'S END-------------------------------------------\n");
 printf("\nEnter the plain-text to be transmitted: ");
 scanf("%[^\n]s",p);
 printf("\n\nEnter the size of the key stream: ");
 scanf("%d",&l);
 printf("\n\nGenerating pseudo random-key stream and saving it in 2A_key.txt...\n");
 for(i=0;i<l;i++)
 {
  int k=rand()%n;
  fprintf(fp,"%d ",k);
 }
 fclose(fp);
 printf("\n\nThe cipher text to be transmitted is: ");
 encrypt(p,l);
 return 0;
}