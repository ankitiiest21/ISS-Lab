#include<stdio.h>
#include<math.h>

int main()
{
 int g,p,key,Y,a=3;
 printf("Enter p(to be known publicly): ");
 scanf("%d",&p);
 printf("Enter g(to be known publicly): ");
 scanf("%d",&g);
 int X=(int)pow(g,a)%p;
 printf("The cipher text to be transported to the insecure channel to Bob's side is: %d\n",X);
 printf("Enter the value to be received at Alice's side: ");
 scanf("%d",&Y);
 key=(int)pow(Y,a)%p;
 printf("Key decrypted at Alice's side is: %d\n",key);
}