#include <stdio.h>



void readnum(int a[], int n)
{
  printf("Enter %d elements :",n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
}




int binarysearch(int a[], int n, int ele) {
    int l, h, mid;
    l = 0;
    h = n - 1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (a[mid] == ele)
            return mid;

        if (a[mid] > ele)
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}
void simplemerge(int a[],int f, int s , int t)
{
  int i=f,j=s,k=0;
  int temp[50];
  while(i<s && j<=t)
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

int main() {
    int n;
    int l = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];

    readnum(a,n);

    mergesort(a,l,n);
    display(a,n);

    int ele, index;
    printf("\nEnter the element to search: ");
    scanf("%d", &ele);
    index = binarysearch(a, n, ele);
    if (index == -1)
        printf("Element not found");
    else
        printf("Found at %d", index);

    return 0;
}
