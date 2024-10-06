#include<stdio.h>
int main ()
{
    int a[10],i,key,n,flag=0;
    printf("Enter array size: ");
    scanf("%d",&n);

    printf("\nEnter array elements: ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);

    }
    printf("\nEnter key elements to be searched: ");
    scanf("%d",&key);

    for ( i = 0; i <n; i++)
    {
        if (key==a[i])
        {
            flag=1;
            break;
        }
        
    }
    if (flag==1)
    {
        printf("\nElement found at index %d",i);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}




