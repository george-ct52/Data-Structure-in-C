#include<stdio.h>
#define size 5
int a[size];
int f=-1;
int r=-1;

int is_empty()
{
    if(f==-1)
        return 1;
    else
        return 0;
}

int is_full()
{
    if(f==(r+1)%size)
        return 1;
    else
        return 0;    
}
void insert_rear(int value)
{
    if(is_full()==1) 
        printf("Queue is full.\n");
    else
        {  
            if(is_empty()==1)
            {
                f=0;
                r=0;
            }
            else
            {
                r=(r+1)%size;
            }
            a[r]=value;
        }
}
void insert_front(int value)
{
    if(is_full()==1) 
        printf("Queue is full.\n");
    else
        {  
            if(is_empty()==1)
            {
                f=0;
                r=0;
            }
            else
            {
                f=(f+size-1)%size;
            }
            a[f]=value;
        }
}
int delete_front()
{
    int val;
    if (is_empty()==1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        val=a[f];
        if (f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            f=(f+1)%size;
        }
    }
    return val;
}
int delete_rear()
{
    int val;
    if (is_empty()==1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        val=a[r];
        if (f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            r=(r+size-1)%size;
        }
    }
    return val;
}
void display()
{
    int i=f;
    if (is_empty()==1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        do
        {
            printf("%d ",a[i]);
            i=((i+1)%size);
        } while (i!=(r+1)%size);
        printf("\n");
    }   
}
void main()
{
    int ch,value,v;
    
    do
    {   
        printf("\n 1.Insert element to front\n 2.Insert element to rear\n 3.Delete from rear\n 4.Delete from front\n 5.Display stack\n 6.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: 
                    printf("Enter the value to be inserted to front: "); 
                    scanf("%d", &value);
                    insert_front(value);
                    break;
            case 2: 
                    printf("Enter the value to be inserted to rear: "); 
                    scanf("%d", &value);
                    insert_rear(value);
                    break;
            case 3: 
                    v=delete_rear(); 
                    printf("Element deleted from rear: %d \n",v);
                    break;
            case 4: v=delete_front(); 
                    printf("Element deleted from front: %d \n",v);
                    break;
            case 5: printf("The queue is \n"); 
                    display();
                    break;
            case 6: printf("Exiting...\n");
                    break;
            default:
            	     printf("Wrong choice.\n");
        }
    }while(ch!=6);
}
