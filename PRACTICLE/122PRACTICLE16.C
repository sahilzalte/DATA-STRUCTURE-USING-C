#include <stdio.h>
#include <stdlib.h>
#define max 5
int top = -1, stack[max];

void PUSH()
{
    int val;
    if (top == max - 1)
    {
        printf("\nStack Overflow !\n");
    }
    else
    {
        printf("\nEnter elemet to insert :");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void POP()
{
    if (top == -1)
    {
        printf("\nStack is Underflow !\n");
    }
    else
    {
        printf("\nDeleted item is :%d\n", stack[top]);
        top--;
    }
}

void DISPLAY()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int ch;
    setbuf(stdout, NULL);
    printf("\n*** Stack Menu ***\n");
    printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT\n");
    while (1)
    {
        printf("Enter user Choise:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            printf("Exit From Program ....");
            exit(0);
            break;

        default:
            printf("\nWrong Choise !\n");
            break;
        }
    }
    return 0;
}