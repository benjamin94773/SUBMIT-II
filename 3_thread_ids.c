#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(4);  // Usando 4 hilos para el ejemplo
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        printf("Hello from thread %d of %d threads!\n", thread_id, total_threads);
    }
    
    return 0;
}
