//
//  Stack.c
//  Tarea4
//
//  Created by Itamar Vazquez on 03.07.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


//typedef struct node{
//    void *contents;
//    struct node *prior;
//}node;
//
//typedef struct stack{
//    node *top;
//    int size;
//}stack;

stack *createStack(){ //the asterisk means that the function returns a memory direction
    stack *neu_stack = (stack*)malloc(sizeof(stack));
    //validacion para ver si el sistema si asigno memoria
    if(neu_stack==NULL)
        return NULL;
    (*neu_stack).top=NULL;
    (*neu_stack).size=0;
    return neu_stack;
}

void push(stack *das_stack, void *data){
    node *neu_node = (node *)malloc(sizeof(node));
    (*neu_node).prior = (*das_stack).top;
    (*das_stack).top = neu_node;
    (*neu_node).contents = data;
    (*das_stack).size +=1;
}
void *pop(stack *das_stack){
    if((*das_stack).top==NULL)// If the stack is already empty just return NULL
        return NULL;
    void *popped_data;
    node *temp_node;
    temp_node = (*das_stack).top;
    popped_data =(*temp_node).contents;
    (*das_stack).top = (*(*das_stack).top).prior;
    (*das_stack).size--;
    free(temp_node);
    return popped_data;
}

int isEmpty(stack *das_stack){
    if((*das_stack).size == 0){
        return 1;
    }
    return 0;
}

int destroyStack(stack *das_stack){
    while(isEmpty(das_stack)==0){
        pop(das_stack);
    }
    free(das_stack);
    return 0;
}

