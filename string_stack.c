#include <stdio.h>
#define size 10
int s[size];
int top=0;

//to check whether stack is empty
int isempty()
{
  if (top==0)
     return 1;
  else 
     return 0;
}
int isfull()
{
  if (top>=size)
     return 1;
  else 
     return 0;
}
void push(int item)
{
  if (isfull())
    printf("Stack Overflow !");
  else
    s[top++]=item;
}
char pop()
{
 if(isempty())
   printf("Stack Underflow !");
 else
   return s[--top];
}
char peak()
{ 
 if(isempty())
   printf("Stack is empty !");
 else 
   return s[top-1];
   
}
void display()
{
 for(int i=top-1;i>=0;i--)
   printf("%c",s[i]);
}

void main()
{
  char st[size];
  printf("Enter the String ");
  scanf("%s",st);
  for(int i=0;st[i]!='\0';i++)
   {
    push(st[i]);
   }
  printf("The reversed string is :");
  display();
}
