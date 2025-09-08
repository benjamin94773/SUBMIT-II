#include <stdio.h>
#include <omp.h>

#define NUM_STEPS 100000000

void calculate_pi(int n_threads) {
    double pi = 0.0;
    double step = 1.0 / NUM_STEPS;
    
    omp_set_num_threads(n_threads);
    double start_time = omp_get_wtime();
    
    #pragma omp parallel for reduction(+:pi)
    for(int i = 0; i < NUM_STEPS; i++) {
        double x = (i + 0.5) * step;
        pi += 4.0 / (1.0 + x * x);
    }
    
    pi *= step;
    double end_time = omp_get_wtime();
    
    printf("Threads: %d, PI = %.10f\n", n_threads, pi);
    printf("Time taken: %f seconds\n\n", end_time - start_time);
}

int main() {
    printf("Calculating PI with different numbers of threads:\n\n");
    
    int thread_counts[] = {2, 4, 8, 32, 64, 128};
    int num_tests = sizeof(thread_counts) / sizeof(thread_counts[0]);
    
    for(int i = 0; i < num_tests; i++) {
        calculate_pi(thread_counts[i]);
    }
    
    return 0;
}
