#include <stdio.h>
int linear(int a[],int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i]==key)
        {
            return i;
        }
        
    }
    return -1;
}
void main()
{
    int arr[] = { 34, 22, 4, 10, 40, 76 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter element to search");
    scanf("%d",&key);
    int ind=linear(arr, n, key);
    if (ind==-1)
        printf("Element not found");
    else
        printf("Element found at : %d",ind);
}