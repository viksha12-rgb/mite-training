#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10  

typedef struct {
    char items[MAX][50];  
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, char item[]) {
    if (isFull(s)) {
        printf("Warehouse is full! Cannot add more stock.\n");
        return;
    }
    s->top++;
    strcpy(s->items[s->top], item);
    printf("Stock Added: %s\n", item);
}
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("No stock left to dispatch!\n");
        return;
    }
    printf("Dispatching Item: %s\n", s->items[s->top]);
    s->top--;
}
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("No remaining stock.\n");
        return;
    }
    printf("Remaining Stock: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%s", s->items[i]);
        if (i < s->top) printf(", ");
    }
    printf("\n");
}
int main() {
    Stack warehouse;
    initialize(&warehouse);
    push(&warehouse, "Item A");
    push(&warehouse, "Item B");
    push(&warehouse, "Item C");
    pop(&warehouse);  
    display(&warehouse);  
    return 0;
}
