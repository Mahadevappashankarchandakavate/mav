#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<ctype.h>

bool verifyRegistration(char registration[]) {
    if (strlen(registration) != 10) {
        return false;
    }

    for (int i = 0; i < 2; i++) {
        if (!isalpha(registration[i])) {
            return false;
        }
    }

    for (int i = 2; i < 4; i++) {
        if (!isdigit(registration[i])) {
            return false;
        }
    }

    for (int i = 4; i < 6; i++) {
        if (!isalpha(registration[i])) {
            return false;
        }
    }

    for (int i = 6; i < 10; i++) {
        if (!isdigit(registration[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    char registration[11];
    printf("Enter a vehicle registration number: ");
    scanf("%s", registration);

    if (verifyRegistration(registration)) {
        printf("Accept: Vehicle registration number is valid.\n");
    } else {
        printf("Reject: Vehicle registration number is invalid.\n");
    }

    return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* next; 
}; 
struct Stack { 
struct Node* top; 
};  
struct Stack* createStack() { 
struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
stack->top = NULL; 
return stack; 
} 
int isEmpty(struct Stack* stack) { 
return (stack->top == NULL); 
} 
void push(struct Stack* stack, int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = data; 
newNode->next = stack->top; 
stack->top = newNode; 
printf("%d pushed to the stack\n", data); 
}  
int pop(struct Stack* stack) { 
if (isEmpty(stack)) { 
printf("Stack is empty. Cannot pop.\n");  
return -1;
} 
struct Node* temp = stack->top; 
int poppedData = temp->data; 
stack->top = temp->next; 
free(temp); 
return poppedData; 
} 
int main() { 
struct Stack* stack = createStack(); 
push(stack, 10); 
push(stack, 20); 
push(stack, 30); 
printf("%d popped from the stack\n", pop(stack)); 
printf("%d popped from the stack\n", pop(stack)); 
printf("%d popped from the stack\n", pop(stack)); 
printf("%d popped from the stack\n", pop(stack)); 
return 0; 
}
