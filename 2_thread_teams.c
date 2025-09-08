#include <stdio.h>
#include <omp.h>

int main() {
    printf("Testing different numbers of threads:\n\n");
    
    int thread_counts[] = {2, 4, 8};
    
    for(int i = 0; i < 3; i++) {
        int n = thread_counts[i];
        printf("\nSetting number of threads to: %d\n", n);
        omp_set_num_threads(n);
        
        #pragma omp parallel
        {
            printf("Hello from thread in team of %d threads!\n", omp_get_num_threads());
        }
    }
    
    return 0;
}
