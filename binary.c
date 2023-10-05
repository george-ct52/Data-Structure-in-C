#include <stdio.h>

int binarysearch(int a[],int n ,int ele)
{
  int l, h, mid;
  l=0;
  h=n-1;
  while (l <= h)
  {
    mid = (l+h)/2;
    if(a[mid]==ele)
     return mid;
    
     if (a[mid]>ele)
        h=mid-1;
     else
        l= mid+1;
     }
      
    return -1;
 }
 
 
 void main()
 {
   int a[]={11,22,33,44,55,66,77};
   int n=7;
   int ele,index;
   printf("Enter the element to search :");
   scanf("%d",&ele);
   index=binarysearch(a,n,ele);
   if (index==-1)
   printf("Element not found");
   else
   printf("Found at %d",index);
 }
   
   
   
   
