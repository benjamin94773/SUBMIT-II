# Taller de Programación Paralela con OpenMP

## Benjamin Ortiz Morales
## Marco Antonio Riascos
## Julian Galvis Tocora
## Rui Yu Lei Wu

Este taller contiene una serie de ejercicios que demuestran diferentes aspectos de la programación paralela usando OpenMP.

## Requisitos
- Compilador GCC con soporte para OpenMP
- Sistema operativo compatible con OpenMP

## Compilación

Para compilar cada programa, use los siguientes comandos:

### Compilación secuencial (sin OpenMP):
```bash
gcc programa.c -o programa
```

### Compilación con OpenMP:
```bash
gcc -fopenmp programa.c -o programa
```

## Ejercicios

1. **Modelo básico OpenMP** (1_hello_omp.c)
   ```bash
   gcc -fopenmp 1_hello_omp.c -o hello_omp
   ./hello_omp
   ```

2. **Equipos de hilos** (2_thread_teams.c)
   ```bash
   gcc -fopenmp 2_thread_teams.c -o thread_teams
   ./thread_teams
   ```

3. **Identificadores de hilos** (3_thread_ids.c)
   ```bash
   gcc -fopenmp 3_thread_ids.c -o thread_ids
   ./thread_ids
   ```

4. **Distribución de trabajo** (4_work_distribution.c)
   ```bash
   gcc -fopenmp 4_work_distribution.c -o work_distribution
   ./work_distribution
   ```

5. **Suma en paralelo con problema de variables compartidas** (5_shared_variable_problem.c)
   ```bash
   gcc -fopenmp 5_shared_variable_problem.c -o shared_problem
   ./shared_problem
   ```

6. **Variables privadas** (6_private_variables.c)
   ```bash
   gcc -fopenmp 6_private_variables.c -o private_vars
   ./private_vars
   ```

7. **Reducción** (7_reduction.c)
   ```bash
   gcc -fopenmp 7_reduction.c -o reduction
   ./reduction
   ```

8. **Cálculo de PI secuencial** (8_pi_sequential.c)
   ```bash
   gcc 8_pi_sequential.c -o pi_sequential
   time ./pi_sequential
   ```

9. **Cálculo de PI paralelo** (9_pi_parallel.c)
   ```bash
   gcc -fopenmp 9_pi_parallel.c -o pi_parallel
   ./pi_parallel
   ```




