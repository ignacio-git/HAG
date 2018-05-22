//
//  main.c
//  Ejercicio_CodificacionCesar
//
//  Created by Itamar Vazquez on 22.05.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//  97-122

#include <stdio.h>
#include <string.h>
#define enter printf("\n");
int main() {
    char array[100];
    scanf("%[^\n]%*c",array);
    printf("%s",array);
    enter
    for(int i=0; i<strlen(array); i++){
        if(array[i] != 32){
            if(array[i] == 122){
                printf("%c",array[i]-25);
            }else{
            printf("%c",array[i]+1);
            }
        }else{
            printf("%c",array[i]);
        }
    }
    enter
    return 0;
}
