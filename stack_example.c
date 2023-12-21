#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//definition of stack
struct stack {
	int top;
	unsigned capacity;
	int* array;
};

//create stack function
struct stack* createStack(unsigned capacity) {
	struct stack* stack1 = (struct stack*)malloc(sizeof(struct stack));
	stack1->capacity = capacity;
	stack1->top = -1;
	stack1->array = (int*)malloc(stack1->capacity * 4);
	return stack1;
}

//to check functions
int isFull(struct stack* stack1) {
	return stack1->top == stack1->capacity;
}
int isEmpty(struct stack* stack1) {
	return stack1->top == -1;
}

//functions
void push(struct stack* stack1, int x) {
	if (isFull(stack1))
		return;
	stack1->array[++stack1->top]=x;
	printf("pushed %d\n", x);
}
int pop(struct stack* stack1) {
	if (isEmpty(stack1))
		return -1;								// Error value for an empty stack
	return stack1->array[stack1->top--];
}
int peek(struct stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty. Cannot peek.\n");
		return -1;								// Error value for an empty stack
	}
	return stack->array[stack->top];
}

int evPos(char* exp) {
	struct stack* stack1 = createStack(strlen(exp));
	int length1 = strlen(exp);
	for (int i = length1 - 1; i >= 0;i--) {
		if (isdigit(exp[i]))
			push(stack1, exp[i] - '0');			//to ASCII
		else{
			int val1 = pop(stack1);
			int val2 = pop(stack1);
			switch (exp[i]) {
				case '+':push(stack1, val2 + val1);
					break;
				case '-': push(stack1, val2 - val1);
					break;
				case '*': push(stack1, val2 * val1);
					break;
				case '/': push(stack1, val2 / val1);
					break;
				default:
					break;
			}
		}
	}
	return pop(stack1);
}

int main() {
	struct stack* stack1 =createStack(5);
	push(stack1, 1);
	push(stack1, 2);
	push(stack1, 3);
	printf("pop %d\n", pop(stack1));
	printf("peek %d\n", peek(stack1));
	printf("pop %d\n", pop(stack1));

	printf("----");
	char str1[] = "+5*32";
	printf("%d", evPos(str1));
}