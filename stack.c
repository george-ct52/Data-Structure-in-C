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
int pop()
{
 if(isempty())
   printf("Stack Underflow !");
 else
   return s[--top];
}
int peak()
{ 
 if(isempty())
   printf("Stack is empty !");
 else 
   return s[top-1];
   
}
void display()
{
 for(int i=top-1;i>=0;i--)
   printf("%d \n",s[i]);
}

void main()
{
 int ch;
 do{
    printf("Enter your choice : \n 1.Push \n 2.Pop \n 3.Peak \n 4.Display the stack \n 5.Exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
          if (isfull())
             printf("Stack is full. \n");
          else
          { 
             printf("Enter the element to push :");
             int key;
             scanf("%d",&key);
             push(key);
	  }
	  break;
    case 2:
         if(isempty())
          printf("The Stack is Empty :");
         else
          printf("The popped element is : %d \n",pop());
          break;
    case 3:
    	 printf("The top element is : %d \n",peak());
         break;
    case 4:
         printf("Displaying the stack :\n");
         display();
         break;
    case 5:
    	 goto exit;
         break;
    default:
        printf("Wrong Choice !");
    }
   }while (1); 
   
 
exit:printf("Exited successfully...");
 
 }
