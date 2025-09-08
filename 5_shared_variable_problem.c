#include <stdio.h>
#include <omp.h>

void sum_parallel(long count, int n_threads) {
    long sum = 0;
    omp_set_num_threads(n_threads);
    
    #pragma omp parallel for
    for(long i = 0; i < count; i++) {
        sum += i;  // Problema de condición de carrera aquí
    }
    
    printf("Sum with %d threads: %ld (Expected: %ld)\n", 
           n_threads, sum, (count * (count - 1)) / 2);
}

int main() {
    long counts[] = {10, 100, 1000};
    int thread_counts[] = {2, 4, 8, 32, 64};
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            printf("\nTesting COUNT=%ld with NTHREADS=%d\n", 
                   counts[i], thread_counts[j]);
            
            // Ejecutar 10 veces para cada combinación
            for(int k = 0; k < 10; k++) {
                sum_parallel(counts[i], thread_counts[j]);
            }
        }
    }
    
    return 0;
}
