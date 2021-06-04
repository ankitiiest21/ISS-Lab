#include<stdio.h>
#include<math.h>

int main()
{
 int g,p,key,X,b=7;
 printf("Enter p(to be known publicly): ");
 scanf("%d",&p);
 printf("Enter g(to be known publicly): ");
 scanf("%d",&g);
 int Y=(int)pow(g,b)%p;
 printf("The cipher text to be transported to the insecure channel to Alice's side is: %d\n",Y);
 printf("Enter the value to be received at Bob's side: ");
 scanf("%d",&X);
 key=(int)pow(X,b)%p;
 printf("Key decrypted at Bob's side is: %d\n",key);
}