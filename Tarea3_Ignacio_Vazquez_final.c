//
//  main.c
//  Tarea3_Ignacio_Vazquez_final
//
//  Created by Itamar Vazquez on 21.06.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define enter printf("\n");
int a =2;
typedef struct Struct_Files{
    FILE *clientes;
    FILE *cuentas;
    FILE *transaciones;
    FILE *text_file;
}struct_files;

typedef struct Users{
    int id;
    char name[50];
    char nachname[50];
    char nachname2[50];
    char birthdate[10];
}users;

typedef struct Transactions{
    int id_cuenta;
    int monto;
}transactions;



void doBinariesExist(struct_files *Dok, char location[50]);
int alreadyInstalled(struct_files *Dok);
users *addUser(users *Benutzer);
void upload(users *Benutzer);
void download(users *Benutzer);
void printCurrentUsers(users *Benutzer);
void eraseLocalUsers(users * Benutzer);
void deleteUser(users * Benutzer, int number);
int lookUp(users *Benutzer, int number);
void printSingleUser(users *Benutzer, int number);


struct_files Dok;
users Benutzer[500];
transactions[500];
int main(int argc, const char * argv[]) {
    
//    Variables
    int choice;
    int choice_user;
    char location[50];
    char location2[50];
    int number;
    
    
    
    
    
//    This only gets executed if the program was "installed for the first time"
if(alreadyInstalled(&Dok)==1){
    printf("Please enter the location where you want to save your files");enter
    scanf("%s",location);
    strcpy(location, "/Users/Itamarvazquez/Documents/Dinamica");
    strcpy(location2, "/Users/Itamarvazquez/Documents/Dinamica");
    doBinariesExist(&Dok, location2);
}
    
    
   // User Interface
GOTO:
GOTO1:
GOTO2:
GOTO3:
    printf("Main Menu");enter
    printf("(1) - Customers");enter
    printf("(2) - Accounts");enter
    printf("(3) - Transactions");enter
    printf("(4) - Exit");enter
    scanf("%d", &choice);
    switch (choice) {
        case 1://Customers
            printf("USERS");enter
            printf("(1) - Add New User");enter
            printf("(2) - Look up User");enter
            printf("(3) - Delete User");enter
            printf("(4) - Print All Users");enter
            scanf("%d", &choice_user);
            switch (choice_user) {
                case 1:
                    download(Benutzer);
                    addUser(Benutzer);

                    printCurrentUsers(Benutzer);
                    goto GOTO;
                case 2:
                    printf("What is the Users's ID?");enter
                    scanf("%d", &number);
                    printSingleUser(Benutzer, number);
                    goto GOTO1;
                case 3:printf("What is the Users's ID you want to delete?");enter
                    scanf("%d", &number);
                    deleteUser(Benutzer, number);
                    printCurrentUsers(Benutzer);
                    printCurrentUsers(Benutzer);
                    goto GOTO2;
                case 4:
                    download(Benutzer);
                    printCurrentUsers(Benutzer);
                    goto GOTO3;
                    break;
                default:
                    break;
            }
            break;
        case 2://Accounts
            break;
        case 3://Transactions
            break;
        case 4://Exit
            break;
        default:
            break;
    }
    return 0;
    

//    printf("Here is the info that array contains at first");enter
//
//    printCurrentUsers(Benutzer);
//
//    printf("This is the array with the contents downloaded");enter
//    download(Benutzer);
//    printCurrentUsers(Benutzer);
//    printf("This is the array with the contents added");enter
//    addUser(Benutzer);
//    printCurrentUsers(Benutzer);
//    printf("This is the array with the contents uploaded and reloaded back on");enter
//    upload(Benutzer);
//    download(Benutzer);
//    printCurrentUsers(Benutzer);

}







//Functions


void doBinariesExist(struct_files *Dok, char location[50]){
    //    printf("This is a test");
    
    char temp_location[100];
    char temp_location2[100];
    char temp_location3[100];
    //    char temp[100];
    strcpy(temp_location, location);
    strcpy(temp_location2, location);
    strcpy(temp_location3, location);
    enter
    //Clientes
    strcat(temp_location, "/clientes.dat");
    (*(Dok)).clientes = NULL;
    (*(Dok)).clientes = fopen(temp_location, "rb");enter
    if((*(Dok)).clientes == NULL){
        (*(Dok)).clientes = fopen(temp_location, "w+b");
        printf("This is a test");
    }
    printf("Location: %s", temp_location);enter
    
    //Cuentas
    strcat(temp_location2, "/cuentas.dat");
    (*(Dok)).clientes = NULL;
    (*(Dok)).cuentas = fopen(temp_location2, "rb");
    if((*(Dok)).cuentas == NULL){
        (*(Dok)).cuentas = fopen(temp_location2, "w+b");
        printf("This is a test");
    }
    //    printf("Cuentas: %s", temp_location2);enter
    printf("Location: %s", temp_location2);enter
    //Transacciones
    strcat(temp_location3, "/transacciones.dat");
    (*(Dok)).clientes = NULL;
    (*(Dok)).transaciones = fopen(temp_location3, "rb");
    if((*(Dok)).transaciones == NULL){
        (*(Dok)).transaciones = fopen(temp_location3, "w+b");
        printf("This is a test");
    }
    //    printf("Transacciones: %s", temp_location3) ;enter
    //    printf("This is another test");
    printf("Location: %s", temp_location3);enter
    fclose((*(Dok)).clientes);
    fclose((*(Dok)).cuentas);
    fclose((*(Dok)).transaciones);
}




int alreadyInstalled(struct_files *Dok){
    // If the document was not previously created it will return 1, if it was already there then it will return 0;
    int x =0;
    (*Dok).text_file = NULL;
    (*Dok).text_file = fopen("mydb.sys", "r");
    if((*Dok).text_file==NULL){
        (*Dok).text_file = fopen("mydb.sys", "w+");
        x++;
    }
    fclose((*Dok).text_file);
    return x;
    
}
users *addUser(users *Benutzer){
    int x=0;
    enter
    printf("Please add the new customer's info below:");enter
    for(int i=0; i<500; i++){
        if((*(Benutzer+i)).id == 0){
            (*(Benutzer+i)).id = a;
            printf("Enter Name:");enter
            scanf("%s", (*(Benutzer+i)).name);
            printf("Enter Last Name:");enter
            scanf("%s", (*(Benutzer+i)).nachname);
            printf("Enter Other Last Name:");enter
            scanf("%s", (*(Benutzer+i)).nachname2);
            a++;
            x++;
            break;
        }
    }
    return Benutzer;
}

void upload(users *Benutzer){
    int i=0;
    FILE *fp;
    
    fp=fopen("users.dat", "w");
    
    for(i=0; i<500; i++){
        fwrite(Benutzer, sizeof(Benutzer), 1, fp);
    }
    fclose(fp);
}


void download(users *Benutzer){
    FILE *fp;
    
    fp=fopen("users.dat", "r");
    

    fread(Benutzer, sizeof(Benutzer), 1, fp);
    fclose(fp);
}

void printCurrentUsers(users *Benutzer){
    for(int i=0; i<500; i++){
        if((*(Benutzer+i)).id != 0){
            printf("%d  |   ", (*(Benutzer+i)).id);
            printf("%s ", (*(Benutzer+i)).name);
            printf("%s ", (*(Benutzer+i)).nachname);
            printf("%s ", (*(Benutzer+i)).nachname2);
            printf("%s", (*(Benutzer+i)).birthdate);enter
        }
    }
}
void eraseLocalUsers(users * Benutzer){
    for(int i=0; i<500; i++){
        if((*(Benutzer+i)).id != 0){
            (*(Benutzer+i)).id = 0;
            strcpy((*(Benutzer+i)).name,"");
            strcpy((*(Benutzer+i)).nachname, "");
            strcpy((*(Benutzer+i)).nachname2, "");
        }
    }
}
void deleteUser(users * Benutzerl, int number){
    for(int i=0; i<500; i++){
        if((*(Benutzer+i)).id == number){
            (*(Benutzer+i)).id = 0;
            strcpy((*(Benutzer+i)).name,"");
            strcpy((*(Benutzer+i)).nachname, "");
            strcpy((*(Benutzer+i)).nachname2, "");
        }
    }
}
int lookUp(users *Benutzer, int number){
    for(int i=0; i<500; i++){
        if((*(Benutzer+i)).id == number){
            return (*(Benutzer+i)).id;
        }
    }
    return 0;
}
void printSingleUser(users *Benutzer, int number){
    for(int i=0; i<500; i++){
        if((*(Benutzer+i)).id == number){
            printf("%d  |   ", (*(Benutzer+i)).id);
            printf("%s ", (*(Benutzer+i)).name);
            printf("%s ", (*(Benutzer+i)).nachname);
            printf("%s ", (*(Benutzer+i)).nachname2);
            printf("%s", (*(Benutzer+i)).birthdate);enter
        }
    }
}





