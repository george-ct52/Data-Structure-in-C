#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int l,int h)
{
    int key=a[l];
    int i=l;
    int j=h;
    while (i<j)
    {
        do{
            i++;
        }while (a[i]<=key);
        
        do{
            j--;
        } while (a[i]>key);
        
        if (i<j)
        swap(&a[i],&a[j]);
    }
    swap(&a[j],&a[l]);
    return j;
}
void quicksort(int a[],int l,int h)
{
   int j= partition(a,l,h);
   partition(a,l,j);
   partition(a,j+1,h);
}

void main()
{
    int a[]={32,33,11,44,12,77,3,6};
    int h=sizeof(a)/sizeof(a[0]);
    int l=0;
    quicksort(a,l,h);
    for(int i=0;i<h;i++)
    {
        printf("%d",a[i]);
    }
    
}