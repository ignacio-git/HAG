//
//  Stack.h
//  Tarea4
//
//  Created by Itamar Vazquez on 03.07.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
typedef struct stack stack;

typedef struct node{
    void *contents;
    struct node *prior;
}node;

typedef struct stack{
    node *top;
    int size;
}stack;

stack *createStack(void);

void push(stack *das_stack, void *data);

void *pop(stack *das_stack);

int isEmpty(stack *das_stack);

int destroyStack(stack *das_stack);
#endif /* Stack_h */
