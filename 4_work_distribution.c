#include <stdio.h>
#include <omp.h>

void test_distribution(int n_threads) {
    printf("\nTesting with %d threads:\n", n_threads);
    omp_set_num_threads(n_threads);
    
    #pragma omp parallel for
    for(int i = 0; i < 16; i++) {
        printf("Thread %d processing iteration %d\n", 
               omp_get_thread_num(), i);
    }
}

int main() {
    printf("Testing work distribution with different thread counts:\n");
    
    int thread_counts[] = {2, 4, 8, 16, 32};
    for(int i = 0; i < 5; i++) {
        test_distribution(thread_counts[i]);
    }
    
    return 0;
}
