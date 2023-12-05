#include<stdio.h>
#include<malloc.h>
struct link
  {
    int item;
    struct link *next;
  };

typedef struct link node;
node *head=NULL;
node *newnode(int val)
{  node *p;
   p=(node *)malloc(sizeof(node));
   p->item=val;
   p->next=NULL;
}

void display()
 {
   node *curr;
   curr=head;
   while(curr!=NULL)
   { 
    printf("%d -> ", curr->item);
    curr=curr->next;
   }
  }

void insertfirst(int val)
{ node *p;
   p=newnode(val);
   p->next=head;
   head=p;
}

void insertbefore(int ele,int val)
{ node *curr=head,*prev=NULL,*p;
  while(curr!=NULL && curr-> item != ele)
    {
     prev=curr;
     curr=curr->next;
     }
  if(curr==NULL)
     printf("Item Not Found\n");
  else
  {
    if(prev==head)
        insertfirst(val);
     else
       {
       p=newnode(val);
       p->next= prev->next;
       prev->next=p;
       }
  }
}

void insertafter(int item1,int val)
{ node *curr=head,*p;

  while(curr!=NULL && curr-> item != item1)
    {
      curr=curr->next;
    }
  
  if(curr==NULL)
     printf("Item Not Found\n");
  else
       {
	p=newnode(val);
        p->next= curr->next;
        curr->next=p;
       }
}


int main()
 {
  int ch,po,it;
           
   do
     { printf("\n1.Insert first\n 2.Insert after\n3.Display \n4.Insert before\n5.quit\n");
       printf("Enter the choice: ");
       scanf("%d",&ch);
       switch(ch)
       { case 1:
                printf("value to be inserted:");
                scanf("%d",&po); 
                insertfirst(po);
                break;
         case 2:
                printf("enter item after which the value to be inserted");
                scanf("%d",&it);
                printf("value to be inserted:");
                scanf("%d",&po);
                insertafter(it,po);
                break;
         case 3:
                display  ();
                break;
         case 4:         
                printf("enter item before which the value to be inserted");
                scanf("%d",&it);
                printf("value to be inserted:");
                scanf("%d",&po);insertbefore(it,po);break;
         
         case 5:break;
          default:printf("Invalid choice");
        }
    }while(ch!=5);

}
