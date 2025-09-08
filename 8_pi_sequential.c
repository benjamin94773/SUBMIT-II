#include <stdio.h>
#include <time.h>

#define NUM_STEPS 100000000

int main() {
    double pi = 0.0;
    double step = 1.0 / NUM_STEPS;
    clock_t start = clock();
    
    for(int i = 0; i < NUM_STEPS; i++) {
        double x = (i + 0.5) * step;
        pi += 4.0 / (1.0 + x * x);
    }
    
    pi *= step;
    clock_t end = clock();
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("PI = %.10f\n", pi);
    printf("Time taken: %f seconds\n", time_spent);
    
    return 0;
}
