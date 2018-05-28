//
//  main.c
//  Ejercicio2_aritmetica_apuntadores_y_estructuras
//
//  Created by Itamar Vazquez on 24.05.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define enter printf("\n");
typedef struct alumno{
    int expediente;
    char nombre[50];
    int carrera;
    int edad;
}alumno;

//Function declarations
alumno add(alumno lista[20]);
alumno delete(alumno lista[20], int student_number);
void print(alumno lista[20]);
void lookup_Students_Number(alumno lista[20], int student_number);
void lookup_Students_Age(alumno lista[20], int student_age);

int main(){
    
    alumno lista[20] = {0};
    int menu_choice, i, d, final_choice, exp, age;
    char array[5][25]= {"Add new student","Print all student's data","Eliminate a student", "Look up student", "Exit"};
    //This code is here to tell that all cells in lista are empy at the beginning
    for(i=0;i<20;i++){
        lista[i].expediente = 0;
    }
    printf("Welcome the School's Database System");enter
label:
label2:
label3:
    printf("(1) - Add new student");enter
    printf("(2) - Print all student's data");enter
    printf("(3) - Eliminate a student");enter
    printf("(4) - Look up student");enter
    printf("(5) - Exit");enter
    
    scanf("%d", &menu_choice);
  
    
    switch (menu_choice) {
        case 1:
            // This just adds the title
            for(i=0;i<20;i++){
                printf("%c", array[0][i]);
            }enter
            add(lista);
            break;
            
            
        case 2:
            for(i=0;i<20;i++){
                printf("%c", array[1][i]);
            }enter
            print(lista);
            break;
            
            
        case 3:
            for(i=0;i<20;i++){
                printf("%c", array[2][i]);
            }enter
            printf("Type the student's number you want to eliminate: ");enter
            scanf("%d", &d);
            delete(lista, d);
            break;
            
            
        case 4:
            for(i=0;i<20;i++){
                printf("%c", array[3][i]);
            }enter
            printf("Do you want to seach by student number or by age?");enter
            printf("(1) - Student Number\n(2) - Age");enter
            scanf("%d", &menu_choice);
            if(menu_choice == 1){
                printf("Enter the student's number you want to search:");enter
                scanf("%d", &exp);
                lookup_Students_Number(lista, exp);
            }
            else if(menu_choice == 2){
                printf("Enter the student's age:");enter
                scanf("%d", &age);
                lookup_Students_Age(lista, age);
            }
            else{
                printf("That is not a valid option...\nPlease enter an option 1-5");enter
                goto label3;
                break;
            }
            
            
            break;
        case 5:
            printf("Bye!");enter
            return 0;
        default:
            printf("That is not a valid option...\nPlease enter an option 1-5");enter
            goto label;
            break;
    }
    enter
    printf("Do you want to make any more changes to the database?");enter
    printf("(1) - Yes");enter
    printf("(2) - No");enter
    scanf("%d", &final_choice);
    if(final_choice == 1){
        goto label2;
    }
    return 0;
}

alumno add(alumno lista[20]){
    int i;
    alumno *pointer = lista;
    for(i=0;i<20;i++){
        if((*(pointer+i)).expediente == 0){
            enter
            printf("Please enter the following data");enter
            printf("Name: ");scanf("%s", (*(pointer+i)).nombre);
            printf("Student Number: ");scanf("%d", &(*(pointer+i)).expediente);
            printf("Major: ");scanf("%d", &(*(pointer+i)).carrera);
            printf("Age: ");scanf("%d", &(*(pointer+i)).edad);
        break;
        }
    }
    
    return* lista;
}
alumno delete(alumno lista[20], int student_number){
    int i = (student_number-1);
    alumno *pointer = lista;
    enter
    strcpy((*(pointer+i)).nombre, "");
    (*(pointer+i)).expediente = 0;
    (*(pointer+i)).carrera = 0;
    (*(pointer+i)).edad = 0;
    return* lista;
}

void print(alumno lista[20]){
    int i;
    alumno *pointer;
    pointer = lista;
    for(i=0;i<20;i++){
        if((*(pointer+i)).expediente != 0){
            enter
            printf("Name: ");printf("%s", (*(pointer+i)).nombre);enter
            printf("Student Number: ");printf("%d", (*(pointer+i)).expediente);enter
            printf("Major: ");printf("%d", (*(pointer+i)).carrera);enter
            printf("Age: ");printf("%d", (*(pointer+i)).edad);enter enter
        }
    }
}
void lookup_Students_Number(alumno lista[20], int student_number){
    int i;
    int search_results =0;
    alumno *pointer;
    pointer = lista;
    for(i=0;i<20;i++){
        if(student_number == (*(pointer+i)).expediente){
            enter
            printf("Name: ");printf("%s", (*(pointer+i)).nombre);enter
            printf("Student Number: ");printf("%d", (*(pointer+i)).expediente);enter
            printf("Major: ");printf("%d", (*(pointer+i)).carrera);enter
            printf("Age: ");printf("%d", (*(pointer+i)).edad);enter enter
            search_results++;
        }
    }
    if(search_results == 0){
        printf("There were no results matching your seach!");
    }
}

void lookup_Students_Age(alumno lista[20], int student_age){
    int i;
    int search_results =0;
    alumno *pointer;
    pointer = lista;
    for(i=0;i<20;i++){
        if((*(pointer+i)).edad == student_age){
            enter
            printf("Name: ");printf("%s", (*(pointer+i)).nombre);enter
            printf("Student Number: ");printf("%d", (*(pointer+i)).expediente);enter
            printf("Major: ");printf("%d", (*(pointer+i)).carrera);enter
            printf("Age: ");printf("%d", (*(pointer+i)).edad);enter enter
            search_results++;
        }
    }
    if(search_results == 0){
        printf("There were no results matching your seach!");
    }
}
