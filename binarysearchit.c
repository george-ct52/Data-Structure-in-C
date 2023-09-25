#include <stdio.h>
void readnum(int a[],int n)
{
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
}
int binarysearch(int a[], int key, int n )
{
    int l,h,mid;
    l=0;
    h=n-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if (a[mid]==key)
            return mid;
        if (a[mid]>key)
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
void main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key= 10;
    int ind=binarysearch(arr, key, n);
    if (ind==-1)
        printf("Element not found");
    else
        printf("Element found at : %d",ind);
}
