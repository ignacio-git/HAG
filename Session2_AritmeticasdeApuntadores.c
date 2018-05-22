//
//  main.c
//  Session2_AritmeticasdeApuntadores
//
//  Created by Itamar Vazquez on 22.05.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#include <stdio.h>
#define enter printf("\n");
int main() {
//    Aritmetica de Apuntadores
    
    float variable = 3.14;
    float variable1 = 14.3;
    float *apuntador;
//    apuntador = NULL; se puede utilizar para inicializar apuntadores
    enter
    printf("Direccion(variable): %p", &variable); //Para ver la direccion en memoria de la variable
    enter
    printf("variable : %f", variable); //Para ver el contenido de la variable
    enter
    printf("Direccion(variable): %p", &variable1); //Para ver la direccion en memoria de la variable
    enter
    printf("variable : %f", variable1); //Para ver el contenido de la variable
    enter
    apuntador = &variable;
    printf("*apuntador: %f", *apuntador);enter
    apuntador--;
    printf("*apuntador: %f", *apuntador);enter
    
    
    short arreglo[] = {1,2,3,4,5};
    apuntador = arreglo;
    
    
    
    
    
    return 0;
}
