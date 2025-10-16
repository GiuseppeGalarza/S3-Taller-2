#include <stdio.h>
#include <string.h>

#define N_STUD 5
#define N_SUBJ 3
#define MAX_NAME 50

int main(void) {
    double g[N_STUD][N_SUBJ] = {0}; // Inicializar matriz en 0
    char names[N_STUD][MAX_NAME];
    int i, j, choice;

    // Ingresar nombres de los estudiantes
    printf("--- Ingresar nombres de los estudiantes ---\n");
    for (i = 0; i < N_STUD; i++) {
        printf("Nombre del alumno %d: ", i + 1);
        fgets(names[i], MAX_NAME, stdin);
        names[i][strcspn(names[i], "\n")] = 0; // Eliminar salto de línea
    }

    // Menú principal
    do {
        printf("\n--- Menú ---\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Ver resultados por estudiante\n");
        printf("3. Ver resultados por asignatura\n");
        printf("4. Ver resultados de un estudiante\n");
        printf("5. Salir\n");
        printf("Opción: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Limpiar buffer

        if (choice == 1) {
            // Entrada con validación simple
            for (i = 0; i < N_STUD; i++) {
                printf("Calificaciones para %s:\n", names[i]);
                for (j = 0; j < N_SUBJ; j++) {
                    double v;
                    do {
                        printf("Asignatura %d (0-10): ", j + 1);
                        if (scanf("%lf", &v) != 1) { // entrada no numérica
                            while (getchar() != '\n');
                            v = -1.0;
                        }
                        if (v < 0.0 || v > 10.0) printf("  -> Calificación inválida. Intente de nuevo.\n");
                    } while (v < 0.0 || v > 10.0);
                    g[i][j] = v;
                }
            }
        }
        else if (choice == 2) {
            // Resultados por estudiante (cálculos y salida del código original)
            printf("\n--- Resultados por estudiante ---\n");
            for (i = 0; i < N_STUD; i++) {
                double sum = 0.0, smax = -1.0, smin = 11.0;
                for (j = 0; j < N_SUBJ; j++) {
                    double v = g[i][j];
                    sum += v;
                    if (v > smax) smax = v;
                    if (v < smin) smin = v;
                }
                printf("%s: promedio = %.2f | max = %.2f | min = %.2f\n", 
                       names[i], sum / N_SUBJ, smax, smin);
            }
        }
        else if (choice == 3) {
            // Resultados por asignatura (cálculos y salida del código original)
            double subject_sum[N_SUBJ] = {0};
            double subject_max[N_SUBJ];
            double subject_min[N_SUBJ];
            for (j = 0; j < N_SUBJ; j++) {
                subject_max[j] = -1.0;
                subject_min[j] = 11.0;
            }
            for (i = 0; i < N_STUD; i++) {
                for (j = 0; j < N_SUBJ; j++) {
                    double v = g[i][j];
                    subject_sum[j] += v;
                    if (v > subject_max[j]) subject_max[j] = v;
                    if (v < subject_min[j]) subject_min[j] = v;
                }
            }
            printf("\n--- Resultados por asignatura ---\n");
            for (j = 0; j < N_SUBJ; j++) {
                int aprobados = 0;
                for (i = 0; i < N_STUD; i++) if (g[i][j] >= 6.0) aprobados++;
                printf("Asignatura %d: promedio = %.2f | max = %.2f | min = %.2f | aprobados = %d | reprobados = %d\n",
                       j + 1, subject_sum[j] / N_STUD, subject_max[j], subject_min[j], aprobados, N_STUD - aprobados);
            }
        }
        else if (choice == 4) {
            // Resultados de un estudiante
            printf("\n--- Seleccionar estudiante ---\n");
            for (i = 0; i < N_STUD; i++) printf("%d. %s\n", i + 1, names[i]);
            printf("Número del estudiante: ");
            int student;
            scanf("%d", &student);
            while (getchar() != '\n');
            if (student >= 1 && student <= N_STUD) {
                i = student - 1;
                double sum = 0.0, smax = -1.0, smin = 11.0;
                printf("\nResultados de %s:\n", names[i]);
                for (j = 0; j < N_SUBJ; j++) {
                    double v = g[i][j];
                    printf("Asignatura %d: %.2f\n", j + 1, v);
                    sum += v;
                    if (v > smax) smax = v;
                    if (v < smin) smin = v;
                }
                printf("Promedio: %.2f | Máximo: %.2f | Mínimo: %.2f\n", sum / N_SUBJ, smax, smin);
            } else {
                printf("  -> Estudiante inválido.\n");
            }
        }
        else if (choice == 5) {
            printf("Saliendo...\n");
            return 0;
        }
        else {
            printf("  -> Opción inválida.\n");
        }
    } while (1);

    return 0;
}
