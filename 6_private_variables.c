#include <stdio.h>
#include <omp.h>

void sum_private(long count, int n_threads) {
    long global_sum = 0;
    omp_set_num_threads(n_threads);
    
    #pragma omp parallel private(global_sum)
    {
        long sum = 0;  // Variable privada para cada hilo
        #pragma omp for
        for(long i = 0; i < count; i++) {
            sum += i;
        }
        
        // Cada hilo tiene su propia copia de global_sum
        global_sum += sum;  // Aún hay condición de carrera aquí
    }
    
    printf("Sum with %d threads (private vars): %ld (Expected: %ld)\n", 
           n_threads, global_sum, (count * (count - 1)) / 2);
}

int main() {
    long count = 1000;
    int thread_counts[] = {2, 4, 8};
    
    for(int j = 0; j < 3; j++) {
        printf("\nTesting with NTHREADS=%d\n", thread_counts[j]);
        for(int k = 0; k < 5; k++) {
            sum_private(count, thread_counts[j]);
        }
    }
    
    return 0;
}
