#include <stdio.h>

#define N_STUD 5
#define N_SUBJ 3

int main(void) {
    double g[N_STUD][N_SUBJ];
    int i, j;

    for (i = 0; i < N_STUD; i++) {
        for (j = 0; j < N_SUBJ; j++) {
            double v;
            do {
                printf("Alumno %d, Asignatura %d (0-10): ", i+1, j+1);
                if (scanf("%lf", &v) != 1) { // entrada no numérica
                    while (getchar() != '
');
                    v = -1.0;
                }
                if (v < 0.0 || v > 10.0) printf("  -> Calificación inválida. Intente de nuevo.");
            } while (v < 0.0 || v > 10.0);
            g[i][j] = v;
        }
    }

    double subject_sum[N_SUBJ] = {0};
    double subject_max[N_SUBJ];
    double subject_min[N_SUBJ];
    for (j = 0; j < N_SUBJ; j++) {
        subject_max[j] = -1.0;
        subject_min[j] = 11.0;
    }

    printf("--- Resultados por alumno ---");
    for (i = 0; i < N_STUD; i++) {
        double sum = 0.0, smax = -1.0, smin = 11.0;
        for (j = 0; j < N_SUBJ; j++) {
            double v = g[i][j];
            sum += v;
            if (v > smax) smax = v;
            if (v < smin) smin = v;
            subject_sum[j] += v;
            if (v > subject_max[j]) subject_max[j] = v;
            if (v < subject_min[j]) subject_min[j] = v;
        }
        printf("Alumno %d: promedio = %.2f | max = %.2f | min = %.2f", i+1, sum / N_SUBJ, smax, smin);
    }

    printf("--- Resultados por asignatura ---");
    for (j = 0; j < N_SUBJ; j++) {
        int aprobados = 0;
        for (i = 0; i < N_STUD; i++) if (g[i][j] >= 6.0) aprobados++;
        printf("Asignatura %d: promedio = %.2f | max = %.2f | min = %.2f | aprobados = %d | reprobados = %d", j+1, subject_sum[j] / N_STUD, subject_max[j], subject_min[j], aprobados, N_STUD - aprobados);
    }

    return 0;
}
