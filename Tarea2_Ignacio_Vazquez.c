//
//  main.c
//  Tarea2_Ignacio_Vazquez
//
//  Created by Itamar Vazquez on 06.06.18.
//  Copyright © 2018 Ignacio Itamar Vazquez Martinez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#define enter printf("\n");
#define MAX 50000000
typedef struct{
    long long int inicio;
    long long int fin;
    long long int sumaParcial;
}Rango;
int part1 =0;
int part2 = 0;
int part4 = 0;
int part8 = 0;
int part16 = 0;
long long int sum [16]={0};

void* sum_array1(void* arg);
void* sum_array2(void* arg);
void* sum_array4(void* arg);
void* sum_array8(void* arg);
void* sum_array16(void* arg);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define enter printf("\n");

int main() {
    clock_t t;
    t = clock();
    double total_time;
    long long int n;       // Number of iterations and control variable
    int i;
    double pi = 0;
    double temp = 0;
    int num_threads = 1;
    printf("Approximation of the number PI through the Leibniz's series\n");
    printf("\nEnter the number of threads: ");
    scanf("%d",&num_threads);
    pthread_t threads[num_threads];
    switch (num_threads) {
        case 1:
            printf("Se ejecuto case1");
            for (int i = 0; i < num_threads; i++)
                pthread_create(&threads[i], NULL, sum_array1, (void*)NULL);
            
           
            for (int i = 0; i < num_threads; i++)
                pthread_join(threads[i], NULL);

            int total_sum1 = 0;
            for (int i = 0; i < num_threads; i++)
                total_sum1 += sum[i];
            break;
        case 2:
            printf("Se ejecuto case1");
            for (int i = 0; i < num_threads; i++)
                pthread_create(&threads[i], NULL, sum_array2, (void*)NULL);
            
            for (int i = 0; i < num_threads; i++)
                pthread_join(threads[i], NULL);
          
            int total_sum2 = 0;
            for (int i = 0; i < num_threads; i++)
                total_sum2 += sum[i];
            break;
        case 4:
            printf("Se ejecuto case1");
            for (int i = 0; i < num_threads; i++)
                pthread_create(&threads[i], NULL, sum_array4, (void*)NULL);

            for (int i = 0; i < num_threads; i++)
                pthread_join(threads[i], NULL);

            int total_sum4 = 0;
            for (int i = 0; i < num_threads; i++)
                total_sum4 += sum[i];
            break;
        case 8:
            printf("Se ejecuto case1");
            for (int i = 0; i < num_threads; i++)
                pthread_create(&threads[i], NULL, sum_array8, (void*)NULL);
            
            for (int i = 0; i < num_threads; i++)
                pthread_join(threads[i], NULL);
            

            int total_sum8 = 0;
            for (int i = 0; i < num_threads; i++)
                total_sum8 += sum[i];
            break;
        case 16:
            printf("Se ejecuto case1");
            for (int i = 0; i < num_threads; i++)
                pthread_create(&threads[i], NULL, sum_array16, (void*)NULL);
            

            for (int i = 0; i < num_threads; i++)
                pthread_join(threads[i], NULL);
            
            int total_sum16 = 0;
            for (int i = 0; i < num_threads; i++)
                total_sum16 += sum[i];
            break;

        default:
            break;
    }
    
    
    printf("\nPlease wait. Running...\n");
    n = 500000000;
    //      50000000000
    //      50000000000
    //      900000000
    for(i = 1; i <= n; i++){
        pi+= ((i+1)&1 ? -1.0 :1.0)/(2*i-1);
    }
    total_time =(clock()-(double)t);
    printf("This is the total time: %f",total_time/CLOCKS_PER_SEC);
    printf("\nAproximated value of PI = %1.16lf\n", 4*pi);
}

void* sum_array1(void* arg)
{
    
    // Each thread computes sum of 1/4th of array
    int thread_part = part1++;
    
    for (int i = thread_part * (MAX / 1); i < (thread_part + 1) * (MAX / 1); i++)
        sum[thread_part] += ((i+1)&1 ? -1.0 :1.0)/(2*i-1);
    
    return sum;
}
void* sum_array2(void* arg)
{
    
    // Each thread computes sum of 1/4th of array
    int thread_part = part1++;
    
    for (int i = thread_part * (MAX / 2); i < (thread_part + 1) * (MAX / 2); i++)
        sum[thread_part] +=((i+1)&1 ? -1.0 :1.0)/(2*i-1);
    
    return sum;
}
void* sum_array4(void* arg)
{
    
    // Each thread computes sum of 1/4th of array
    int thread_part = part4++;
    
    for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++)
        sum[thread_part] +=((i+1)&1 ? -1.0 :1.0)/(2*i-1);
        
    return sum;
}
void* sum_array8(void* arg)
{
    
    // Each thread computes sum of 1/4th of array
    int thread_part = part8++;
    
    for (int i = thread_part * (MAX / 8); i < (thread_part + 1) * (MAX / 8); i++)
        sum[thread_part] +=((i+1)&1 ? -1.0 :1.0)/(2*i-1);
    
    return sum;
}
void* sum_array16(void* arg)
{
    
    // Each thread computes sum of 1/4th of array
    int thread_part = part16++;
    
    for (int i = thread_part * (MAX / 16); i < (thread_part + 1) * (MAX / 16); i++)
        sum[thread_part] += ((i+1)&1 ? -1.0 :1.0)/(2*i-1);
    
    return sum;
}
