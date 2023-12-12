#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node node;

node *head = NULL, *tail = NULL;

node *newnode()
{
    node *p;
    p= malloc(sizeof(node));
    return p;
}

void insertFirst(int val)
{
    node *p = newnode();
    p->info = val;
    p->prev = NULL;
    p->next = head;
    if(head == NULL)
        head = tail = p;
    else
        {
            head->prev = p;
            head = p;
        }
}
void insertLast(int val)
{
    node *p = newnode();
    p->info = val;
    p->prev = tail;
    p->next = NULL;
    if(tail == NULL)
        head = tail = p;
    else
        {
            tail->next = p;
            tail = p;
        }
}
void insertBefore(int item, int val)
{
    node *curr = head;
    while(curr!=NULL && curr->info!=item)
        curr = curr->next;
    if(curr == NULL)
        printf("NO SUCH NODE");
    else
    {
        node *p = newnode();
        p->info = val;
        p->prev = curr->prev;
        p->next = curr;
        if(curr->prev == NULL)
            head = p;
        else
        {
            curr->prev->next = p;
            curr->prev = p;
        }
    }
}
void insertAfter(int item, int val)
{
    node *curr = head;
    while(curr!=NULL && curr->info!=item)
        curr = curr->next;
    if(curr == NULL)
        printf("NO SUCH NODE");
    else
    {
        node *p = newnode();
        p->info = val;
        p->prev = curr;
        p->next = curr->next;
        if(curr->next == NULL)
            tail = p;
        else
        {
            curr->next->prev = p;
            curr->next = p;
        }
    }
}
int deleteNode(int item)
{
    node *curr = head;
    while(curr!=NULL && curr->info!=item)
        curr = curr->next;
    if(curr == NULL)
        printf("NO SUCH NODE");
    else
    {
        if(curr->prev == NULL)
            head = curr->next;
        else
            curr->prev->next = curr->next;
        if(curr->next == NULL)
            tail= curr->prev;
        else
            curr->next->prev = curr->prev;
    }
    free(curr);
    
}
void traverseLtoR()
{
   node *curr = head;
   while(curr!=NULL)
   {
       printf("\n%d\n",curr->info);
       curr=curr->next;
   }
}
void traverseRtoL()
{
   node *curr = tail;
   while(curr!=NULL)
   {
       printf("\n%d\n",curr->info);
       curr=curr->prev;
   }
}
void main()
{
    
    int choice, value, item;

    do {
        printf("\nMenu\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert before a node\n");
        printf("4. Insert after a node\n");
        printf("5. Delete a node\n");
        printf("6. Traverse left to right\n");
        printf("7. Traverse right to left\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertFirst(value);
            break;

        case 2:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertLast(value);
            break;

        case 3:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the node value before which to insert: ");
            scanf("%d", &item);
            insertBefore(item, value);
            break;

        case 4:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the node value after which to insert: ");
            scanf("%d", &item);
            insertAfter(item, value);
            break;

        case 5:
            printf("Enter the value to delete: ");
            scanf("%d", &item);
            deleteNode(item);
            break;

        case 6:
            printf("Linked List (Left to Right): ");
            traverseLtoR();
            break;

        case 7:
            printf("Linked List (Right to Left): ");
            traverseRtoL();
            break;

        case 8:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

}