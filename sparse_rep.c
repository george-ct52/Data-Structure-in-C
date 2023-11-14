#include<stdio.h>
int rows, col;
void s_read(int a[][col])
{
printf("\nEnter elements of the matrix:");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
            scanf("%d",&a[i][j]);
         if (a[i][j]!=0)
            {
                count++;
            }
    }
}

 

void sparse_converter(int a[][col])
{
int index=1,count0=0;
int s[15][3];

for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
            {
                if (a[i][j]==0)
                {   
                    count0++;
                    continue;
                 }
                else
                {
                    s[index][1]=i;
                    s[index][2]=j;
                    s[index][3]=a[i][j];
                    index++;
                }
            }
            s[0][1]=rows;
            s[0][2]=col;
            s[0][3]=index-1;
    }
 

for(int i=0;i<index;i++)
    {
        for(int j=0;j<3;j++)
            {
              printf("%d   ",s[i][j]);
            }
        printf("\n");
    }

}

void main()
{

printf("Enter the dimension of the array \n");
printf("Enter the rows :");
scanf("%d",&rows);
printf("Enter the columns :");
scanf("%d",&col);
int a[rows][col];
s_read(a);
sparse_converter(a);

}


