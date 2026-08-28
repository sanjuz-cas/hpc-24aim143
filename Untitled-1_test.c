#include <omp.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    const long n = 20000000; /* reduced for quick test */
    double sum = 0.0;

    clock_t c0 = clock();
    double w0 = omp_get_wtime();

#pragma omp parallel for reduction(+: sum)
    for (long i = 0; i < n; i++)
        sum += 1.0 / (double)(i + 1);

    double cpu = (double)(clock() - c0) / CLOCKS_PER_SEC;
    double wall = omp_get_wtime() - w0;

    printf("sum=%.10f cpu=%.3fs wall=%.3fs ratio=%.2f\n",
           sum, cpu, wall, cpu / wall);
    return 0;
}
