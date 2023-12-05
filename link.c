#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int info;
  struct Node* next;
};
typedef struct Node node;
node* head=NULL;
node* newnode()
{
 node*p;
 p=(node*)malloc(sizeof(node));
 return p;
 }
void insertfirst(int val)
{
  node* p=newnode();
  p->info=val;
  p->next =head;
  head=p;
 }
void display()
{
  node* curr=head;
  while(curr!=NULL)
  {
     printf("%d\t ",curr->info);
      curr=curr->next;
   }
}
 void insertafter(int item,int val)
 {
  node* curr=head;
  while(curr!=NULL && curr->info!=item)
     curr=curr->next;
   if(curr==NULL)
    printf("No such node exist");
   else
   {
     node* p=newnode();
     p->info=val;
     p->next=curr->next;
     curr->next=p;
    }
 }
 void insertbefore(int item,int val)
 {
  node* curr=head;node *prev=NULL;
  while(curr!=NULL && curr->info!=item){
     prev=curr;
     curr=curr->next;}
   if(curr==NULL)
    printf("No such node exist");
   else
   {
     node* p=newnode();
     p->info=val;
     p->next=curr;
     if(prev==NULL)
        head=p;
     else
        prev->next=p;
    }
  }
 void deletenode(int item)
 {
  node* curr=head;node *prev=NULL;
  while(curr!=NULL && curr->info!=item){
     prev=curr;
     curr=curr->next;}
   if(curr==NULL)
    printf("No node to delete");
   else
   {
     
     if(prev==NULL)
        head=curr->next;
     else
        prev->next=curr->next;
    free(curr);
    }
   }
void main()
{
  int c,in,ip;
  printf("1.Insert A Node\n2.Insert After An Item\n3.Insert before an Item\n4.Delete a Node\n5.Display\n6.Exit\n");
  do
  {
    printf("\nEnter choice:\n");
    scanf("%d",&c);
    switch(c)
     {
	case 1:
       	          printf("Enter an element to add:\n");
         	  scanf("%d",&in);
		  insertfirst(in);
	 break;
	 case 2:
       	          printf("Enter an element to add:\n");
         	  scanf("%d",&in);
                  printf("Enter the element after which it needs to be added:\n");
         	  scanf("%d",&ip);
		  insertafter(ip,in);
	 break;
	 case 3:
		  printf("Enter an element to add:\n");
         	  scanf("%d",&in);
                  printf("Enter the element before which it needs to be added:\n");
         	  scanf("%d",&ip);
		  insertbefore(ip,in);
	 break;
	case 4:
		printf("Enter the data to be deleted:\n");
         	  scanf("%d",&ip);
		  deletenode(ip);
	 break;
        case 5: 
                display();
	 break;
 	case 6:
		printf("Exiting program\n");
	 break;
        default:
                printf("Invalid Input\n");
     }
  }while(c!=6);
 }