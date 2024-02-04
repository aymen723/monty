#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Stack structure
struct Stack
{
    struct Node *top;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to get the top element of the stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

// Function to display the stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *current = stack->top;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    display(stack);

    printf("Top element: %d\n", peek(stack));

    printf("Popped element: %d\n", pop(stack));

    display(stack);

    return 0;
}
