#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE][100];
    int top;
} Stack;

void push(Stack *s, const char *url) {
    if (s->top < MAX_SIZE - 1) {
        strcpy(s->stack[++s->top], url);
    }
}

char* pop(Stack *s) {
    if (s->top >= 0) {
        return s->stack[s->top--];
    }
    return NULL;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

typedef struct {
    Stack backStack;
    Stack forwardStack;
    char current[100];
} BrowserHistory;

void visit(BrowserHistory *bh, const char *url) {
    if (strlen(bh->current) > 0) {
        push(&bh->backStack, bh->current);
    }
    strcpy(bh->current, url);
    bh->forwardStack.top = -1; // Clear forward history
    printf("Visited: %s\n", bh->current);
}

void goBack(BrowserHistory *bh) {
    if (!isEmpty(&bh->backStack)) {
        push(&bh->forwardStack, bh->current);
        strcpy(bh->current, pop(&bh->backStack));
        printf("Action: Go Back\nCurrent Page: %s\n", bh->current);
    } else {
        printf("No previous page to go back to.\n");
    }
}

void goForward(BrowserHistory *bh) {
    if (!isEmpty(&bh->forwardStack)) {
        push(&bh->backStack, bh->current);
        strcpy(bh->current, pop(&bh->forwardStack));
        printf("Action: Go Forward\nCurrent Page: %s\n", bh->current);
    } else {
        printf("No forward page to go to.\n");
    }
}

int main() {
    BrowserHistory bh;
    bh.backStack.top = -1;
    bh.forwardStack.top = -1;
    strcpy(bh.current, "");
    visit(&bh, "google.com");
    visit(&bh, "github.com");
    visit(&bh, "stackoverflow.com");
    goBack(&bh);
    goForward(&bh);
    return 0;
}
