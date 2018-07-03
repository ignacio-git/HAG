//
//  main.c
//  Tarea4.1
//
//  Created by Itamar Vazquez on 03.07.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100
struct Stack{
    int top;
    char arr[MAX_SIZE];
} st;

void init(){
    st.top = -1;
}

bool isEmpty(){
    if(st.top == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(st.top == MAX_SIZE-1){
        return true;
    }else{
        return false;
    }
}

void push(char item){
    if(isFull()){
        printf("Stack is full");
    }else{
        st.top++;
        st.arr[st.top] = item;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is empty");
    }else{
        st.top--;
    }
}

char pull(){
    return st.arr[st.top];
}

bool domatch(char opening,char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}
int main()
{
    char array[MAX_SIZE];
    int length=0,i;
    
    init();
    
    printf("Enter an expression to check:");
    scanf("%s", array);
    
    length = strlen(array);
    
    for(i=0;i<length;i++){
        if(array[i] == '(' || array[i] == '{' || array[i] == '['){
            push(array[i]);
        }else if(array[i] == ')' || array[i] == '}' || array[i] == ']'){
            if(isEmpty() || !domatch(pull(),array[i])){
                printf("\nNot Balanced!");
                return 0;
            }else{
                pop();
            }
        }
    }
    if(isEmpty()){
        printf("\nBalanced !");
    }else{
        printf("\nNot Balanced!");
    }
}




