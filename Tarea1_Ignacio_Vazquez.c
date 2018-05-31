//
//  main.c
//  Tarea1
//
//  Created by Itamar Vazquez on 28.05.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define enter printf("\n");
typedef struct{
    char nombre[15];
    float calificacion;
    int times_repeated;
} Profesor;

void readArray(Profesor array[20], int x);
void print(Profesor array[], int x);
void print_Final(Profesor array[40], int x);
void merge_Arrays(Profesor arrayFinal[40], Profesor array1[20], Profesor array2[20]);
void sort_by_name(Profesor arrayFinal[40]);
void merge_Duplicates(Profesor arrayFinal[40]);
void sort_by_Score(Profesor arrayFinal[40]);
void make_Ordered_Array(Profesor arrayFinal[40]);
//void add(Profesor arrayFinal[40], Profesor arrayFF [40], int k);
Profesor arr1[20];  //Primer arreglo
Profesor arr2[20];  //Segundo arreglo
Profesor arrF[40];  //Arreglo, con elementos fusionados
Profesor arrFF[40]; //Arreglo final, con elementos ordenados
int main(){
    
    int n1;
    int n2;
    int n3 = 40;
    int i; //Longitud de los arreglos
    //This code is here to tell that all cells in lista are empy at the beginning
    for(i=0;i<20;i++){
        (*(arr1+i)).calificacion = 0;
        strcpy((*(arr1+i)).nombre, "empty");
    }
    for(i=0;i<20;i++){
        (*(arr2+i)).calificacion = 0;
        strcpy((*(arr2+i)).nombre, "empty");
    }
    for(i=0;i<40;i++){
        (*(arrF+i)).calificacion = 0;
        strcpy((*(arrF+i)).nombre, "empty");
        (*(arrF+i)).times_repeated = 1;
    }
    scanf("%d", &n1);
    readArray(arr1,n1);//leer el primer arreglo
    scanf("%d", &n2);
    readArray(arr2, n2);//leer el segundo arreglo
    
    merge_Arrays(arrF, arr1, arr2);// Combinar los dos arreglos en el tercero
    sort_by_name(arrF); // Acomodar los nombres por orden alfabetico
    merge_Duplicates(arrF); // Borrar los duplicados, y hace el promedio del profesor
    sort_by_Score(arrF); // Ordenar el arreglo por puntajes de maestros
    print_Final(arrF, n3); // Imprimir la tabla ordenada al final
    return 0;
}



//Functions

void readArray(Profesor array[20], int x){
    int i;
    Profesor *pointer = array;
    for(i=0;i<x;i++){
        scanf("%s   %f", (*(pointer+i)).nombre, &(*(pointer+i)).calificacion);
    }
}


void print(Profesor array[], int x){
    int i;
    Profesor *pointer;
    pointer = array;
    for(i=0;i<x;i++){
        enter
        printf("%d Name: ", i);printf("%s\t",(*(pointer+i)).nombre);
        printf("Score: ");printf("%f", (*(pointer+i)).calificacion);enter
    }
    enter
}
void print_Final(Profesor array[40], int x){
    int i;
    Profesor *pointer;
    pointer = array;
    enter
    enter enter
    for(i=0;i<x;i++){
        if((strcmp((*(pointer+i)).nombre,"empty")!=0) ){
            printf("%s\t",(*(pointer+i)).nombre);
            printf("%.1f", (*(pointer+i)).calificacion);enter
        }
    }
}

void merge_Arrays(Profesor arrayFinal[40], Profesor array1[20], Profesor array2[20]){
    int i;
    for(i=0; i<20; i++){
        strcpy((*(arrayFinal+i)).nombre,(*(array1+i)).nombre);
        (*(arrayFinal+i)).calificacion = (*(array1+i)).calificacion;
    }
    for(i=20; i<40; i++){
        strcpy((*(arrayFinal+i)).nombre,(*(array2+(i-20))).nombre);
        (*(arrayFinal+i)).calificacion = (*(array2+(i-20))).calificacion;
    }
}
void sort_by_name(Profesor arrayFinal[40]){
    int i,j;
    Profesor temp;
    for(i=0;i<40;i++){
        for(j=0;j<39;j++){
            if((*(arrayFinal+j)).nombre[0]>(*(arrayFinal+(j+1))).nombre[0]){
                //Copiar a temp
                strcpy(temp.nombre, (*(arrayFinal+(j+1))).nombre);
                temp.calificacion =(*(arrayFinal+(j+1))).calificacion;
                //anterior copiar a siguiente
                strcpy((*(arrayFinal+(j+1))).nombre, (*(arrayFinal+j)).nombre);
                (*(arrayFinal+(j+1))).calificacion = (*(arrayFinal+j)).calificacion;
                // temp copiar a anterior
                strcpy((*(arrayFinal+j)).nombre, temp.nombre);
                (*(arrayFinal+j)).calificacion = temp.calificacion;
            }
            if((*(arrayFinal+j)).nombre[0]==(*(arrayFinal+(j+1))).nombre[0]){
                if((*(arrayFinal+j)).nombre[1]>(*(arrayFinal+(j+1))).nombre[1]){
                    //Copiar a temp
                    strcpy(temp.nombre, (*(arrayFinal+(j+1))).nombre);
                    temp.calificacion =(*(arrayFinal+(j+1))).calificacion;
                    //anterior copiar a siguiente
                    strcpy((*(arrayFinal+(j+1))).nombre, (*(arrayFinal+j)).nombre);
                    (*(arrayFinal+(j+1))).calificacion = (*(arrayFinal+j)).calificacion;
                    // temp copiar a anterior
                    strcpy((*(arrayFinal+j)).nombre, temp.nombre);
                    (*(arrayFinal+j)).calificacion = temp.calificacion;
                    
                }
                if((*(arrayFinal+j)).nombre[1]==(*(arrayFinal+(j+1))).nombre[1]){
                    if((*(arrayFinal+j)).nombre[2]>(*(arrayFinal+(j+1))).nombre[2]){
                        //Copiar a temp
                        strcpy(temp.nombre, (*(arrayFinal+(j+1))).nombre);
                        temp.calificacion =(*(arrayFinal+(j+1))).calificacion;
                        //anterior copiar a siguiente
                        strcpy((*(arrayFinal+(j+1))).nombre, (*(arrayFinal+j)).nombre);
                        (*(arrayFinal+(j+1))).calificacion = (*(arrayFinal+j)).calificacion;
                        // temp copiar a anterior
                        strcpy((*(arrayFinal+j)).nombre, temp.nombre);
                        (*(arrayFinal+j)).calificacion = temp.calificacion;
                    }
                }
            }
        }
    }
}

void merge_Duplicates(Profesor arrayFinal[40]){
    int i;
    for(i=0;i<39;i++){
        if(strcmp((*(arrayFinal+i)).nombre, (*(arrayFinal+(i+1))).nombre)==0){
            (*(arrayFinal+(i+1))).calificacion += (*(arrayFinal+(i))).calificacion;
            (*(arrayFinal+(i+1))).times_repeated += (*(arrayFinal+(i))).times_repeated;
            (*(arrayFinal+i)).calificacion = (float)0;
            (*(arrayFinal+i)).times_repeated = (int)1;
            strcpy((*(arrayFinal+i)).nombre, "empty");
        }
    }
    for(i=0;i<39;i++){
        float r = arrayFinal[i].calificacion;
        float b = arrayFinal[i].times_repeated;
        (*(arrayFinal+i)).calificacion = r/b;
        (*(arrayFinal+i)).times_repeated = 1;
    }
}

void sort_by_Score(Profesor arrayFinal[40]){
    int i,j;
    Profesor temp;
    for(i=0;i<40;i++){
        for(j=0;j<39;j++){
            if(arrayFinal[j].calificacion < arrayFinal[j+1].calificacion){
                strcpy(temp.nombre, (*(arrayFinal+(j+1))).nombre);
                temp.calificacion =(*(arrayFinal+(j+1))).calificacion;
                //siguiente copiar a anterior
                strcpy((*(arrayFinal+j+1)).nombre, (*(arrayFinal+(j))).nombre);
                (*(arrayFinal+j+1)).calificacion = (*(arrayFinal+(j))).calificacion;
                // temp copiar al suguiente
                strcpy((*(arrayFinal+j)).nombre, temp.nombre);
                (*(arrayFinal+j)).calificacion = temp.calificacion;
            }
            
        }
    }
}


