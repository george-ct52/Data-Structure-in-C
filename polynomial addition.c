#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int expo;
    struct Node* next;
};

typedef struct Node node;

node *newnode()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    return p;
    
}

node *read()
{
    int coe,exp,ch;
    node *curr, *head;
    head=newnode();
    curr=head;
    do{
        printf("Enter the coeffiecient :");
        scanf("%d",&curr->coeff);
        printf("Enter the exponent :");
        scanf("%d",&curr->expo);
        printf("More values ? (0,1)");
        scanf("%d",&ch);
        if(ch==1)
        {
            curr->next=newnode();
            curr=curr->next;
        }
    }while (ch!=0);
    curr->next =NULL;
    return head;
}
        
node *add(node *a , node *b)
{
    node *c,*curr;
    c=newnode();
    curr=c;
    while(a!=NULL && b!=NULL)
    {
        if(a->expo==b->expo)
        {
            curr->expo=a->expo;
            curr->coeff=a->coeff+b->coeff;
            a=a->next;
            b=b->next;
        }
        else if(a->expo > b->expo)
        {
            curr->expo=a->expo;
            curr->coeff=a->coeff;
            a=a->next;
        }
        else
        {
            curr->expo=b->expo;
            curr->coeff=b->coeff;
            b=b->next;        }
        if(a!=NULL && b!= NULL)
        {
            curr->next=newnode();
            curr=curr->next;
        }
    }
    if(a!=NULL || b!= NULL)
    {
        curr->next=newnode();
        curr=curr->next;
    }
    
    while(a!=NULL)
    {
        curr->coeff=a->coeff;
        curr->expo=a->expo;
        a=a->next;
        if(a!=NULL)
        {
            curr->next =newnode();
            curr=curr->next;
        }
        
    }
    
    while(b!=NULL)
    {
        curr->coeff=b->coeff;
        curr->expo=b->expo;
        b=b->next;
        if(b!=NULL)
        {
            curr->next =newnode();
            curr=curr->next;
        }
        
    }
    curr->next =NULL;
    return c;
    
}        

void display(node *a)
{
   node *curr=a;
   printf("\n");
   while(curr!=NULL)
   {
       printf("%d x^%d",curr->coeff,curr->expo);
       if(curr->next!=NULL)
       {
           printf("+");
       }
       curr =curr->next;
   }
   printf("\n");
}

void main()
{
    node *a ,*b,*c;
    printf("Enter the first polynomial :");
    a=read();
    printf("Enter the second polynomial :");
    b=read();
    display(a);
    display(b);
    c=add(a,b);
    printf("The added polynomial is :");
    display(c);
}
