#include <stdio.h>
#define size 10
int arr[size],front=-1,rear=-1;

//to check whether queue is empty
int isempty()
{
  if (front==-1 && rear==-1 )
     return 1;
  else 
     return 0;
}

//to check whether queue is full
int isfull()
{
  if ((rear+1) % size == front)
     return 1;
  else 
     return 0;
}

void insertQ(int item)
{
 if (isfull())
    printf("Queue is full !");
 else if(isempty())
    front=rear=0;
 else //to reset rear when rear>size
    rear=(rear+1)%size;
 
 arr[rear]=item;
}

void delete()
{
  if (isempty())
     printf("Queue is Empty !");
  else if (front==rear)
     {
      printf("The deleted element is : %d",arr[front]);
      rear=front=-1;
     }
   else
      {
       printf("The deleted element is : %d",arr[front]);
       front= (front+1)%size;
      }
}

void display(int front, int rear) 
{
  
    printf("\n The Current Queue is \n");
    if (front > rear)
    {
     for (int i = front; i < size; i++)
     {
       printf("%d ", arr[i]);
     }
     for (int i = 0; i <=rear; i++)
     {
       printf("%d ", arr[i]);
     }
    }
    else
    {
    for (int i = front; i <= rear; i++)
     {
       printf("%d ", arr[i]);
     }
    }
    
      
    
}
void main()
{
 int ch;
 do{
    printf("\nEnter your choice : \n 1.Insert Q \n 2.Delete from Q \n 3.Display the Queue \n 4.Exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
          if (isfull())
             printf("Queue is full. \n");
          else
          { 
             printf("Enter the element to push :");
             int key;
             scanf("%d",&key);
             insertQ(key);
             printf("Element pushed successfully..");
	  }
	  break;
    case 2:
         if(isempty())
          printf("The Queue is Empty ! \n");
         else
          delete();
          break;
    
    case 3:
         
         display(front,rear);
         break;
    case 4:
    	 goto exit;
         break;
    default:
        printf("Wrong Choice ! \n");
    }
   }while (1);
   
    
    
exit:printf("Exited successfully...");
 
 }    


