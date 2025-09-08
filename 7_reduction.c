#include <stdio.h>
#include <omp.h>
#include <time.h>

void sum_reduction(long count, int n_threads) {
    long sum = 0;
    double start_time = omp_get_wtime();
    
    omp_set_num_threads(n_threads);
    
    #pragma omp parallel for reduction(+:sum)
    for(long i = 0; i < count; i++) {
        sum += i;
    }
    
    double end_time = omp_get_wtime();
    
    printf("Sum with %d threads: %ld (Expected: %ld)\n", 
           n_threads, sum, (count * (count - 1)) / 2);
    printf("Time taken: %f seconds\n", end_time - start_time);
}

int main() {
    long counts[] = {1000, 1000000, 100000000};
    int thread_counts[] = {2, 4, 8, 32, 64};
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            printf("\nTesting COUNT=%ld with NTHREADS=%d\n", 
                   counts[i], thread_counts[j]);
            sum_reduction(counts[i], thread_counts[j]);
        }
    }
    
    return 0;
}
