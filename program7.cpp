#include <stdio.h>

#define N 10

int Stack[N];
int top = -1;

// Push operation
void push(int x)
{
    if (top == N - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        Stack[top] = x;
        printf("%d pushed into Stack\n", x);
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from Stack\n", Stack[top]);
        top--;
    }
}

// Display Stack
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", Stack[i]);
        }
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}