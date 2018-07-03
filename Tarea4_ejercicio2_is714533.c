//
//  main.c
//  Tarea4
//
//  Created by Itamar Vazquez on 03.07.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//  INFIX TO POSTFIX

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"
#define enter printf("\n");
int PEMDAS(char ch);



int main(){
    char array[50]="";
    int i;
    char postfix[50] = "";
    char *temp;
    
    printf("Please type in your string");
    scanf("%s", array);
    stack *Stack = createStack();
    
    for(i=0; i<50; i++){
        if(array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/'){
            if(isEmpty(Stack)==1){
               push(Stack, &array[i]);
                printf("%c",array[i]);enter
            }
            if(isEmpty(Stack)==0){
                if(PEMDAS((char)(*(*(Stack)).top).contents) > PEMDAS(array[i])){
                    temp = pop(Stack);
                    push(Stack, temp);
                    printf("%c",*temp);enter
                }
            }
        }
        else{
            strcat(postfix, &array[i]);
            printf("Number: %c", array[i]);enter
        }
        
    }
    while(isEmpty(Stack)!=1){
        printf("%c", (char)pop(Stack));enter
    }
    enter
    enter
    printf("The final result");
    for(i=0; i<50; i++){
        printf("%c ", postfix[i]);
        
    }
    enter
    enter
    
    
    
    
    
    
}
int PEMDAS(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
            
        case '*':
        case '/':
            return 2;
            
        case '^':
            return 3;
    }
    return 0;
}
