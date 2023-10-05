#include <stdio.h>

void readnum(int a[], int n)
{
  printf("Enter %d elements :",n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
}

/*f-beginning of the array
s-beginning of second array
t-end of second array*/

void simplemerge(int a[],int f, int s , int t)
{
  int i=f,j=s,k=0;
  int temp[50];
  while(i<s && j<t)
  {
    if (a[i]<a[j])
    temp[k++]=a[i++];
    else
    temp[k++]=a[j++];
   }
   
  while(i<s)
  temp[k++]=a[i++];
  while(j<=t)
  temp[k++]=a[j++];


 //to delete the temp array and save into a 
 for(int i=f,k=0;i<=t;)
 {
  a[i++]=temp[k++];
  }
}

void mergesort(int a[], int beg, int end)
{
  int mid;
  if(beg<end)
  {
   mid = (beg+end)/2;
   mergesort(a,beg,mid);
   mergesort(a,mid+1,end);
   simplemerge(a,beg,mid+1,end);
   }
}
void display(int a[],int n)
{
  printf("The elements are :");
  for(int i=0;i<n;i++)
    printf("%d  \n",a[i]);
}

void main()
{
    int n;
    printf("Enter the size of the array");
    scanf("%d",&n);
    int a[n];
    
    int l=0;
    readnum(a,n);
    mergesort(a,l,n);
    display(a,n);
    
}
